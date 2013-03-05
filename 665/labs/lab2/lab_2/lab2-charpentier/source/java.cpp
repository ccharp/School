/*
 * Copyright (c) 1997, 2008, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#include "incls/_precompiled.incl"
#include "incls/_java.cpp.incl"
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

HS_DTRACE_PROBE_DECL(hotspot, vm__shutdown);

int compare_methods(methodOop* a, methodOop* b) {
  // %%% there can be 32-bit overflow here
  return ((*b)->invocation_count() + (*b)->compiled_invocation_count())
       - ((*a)->invocation_count() + (*a)->compiled_invocation_count());
}

int compare_methods2(methodOop* a, methodOop* b) {
  // %%% there can be 32-bit overflow here
  return ((*b)->our_invocation_count() + (*b)->our_backedge_count())
    - ((*a)->our_invocation_count() + (*a)->our_backedge_count());
}

// PK: some statistics
extern long long compilerRunTime, appRunTime;
extern int VMIndicatorReached;

// PK: Arrary to hold all methodOop objects
GrowableArray<methodOop>* all_invoked_methods;

// PK: Function to collect invoked methods
void get_invoked_methods(methodOop m){
  if (m->invocation_count() + m->compiled_invocation_count() >= 1 ) {
    all_invoked_methods->push(m);
  }
}

// PK: Mark all methods indicated in the hotmethods file as hot in their
// respective class instances
void mark_hot_methods()
{
  all_invoked_methods = new GrowableArray<methodOop>(1024);
  SystemDictionary::methods_do(get_invoked_methods);

  // Here we attempt to mark the methods indicated as hot in the hotfile.
  // Only the marked methods will be compiled.
  ifstream inFile;
  FILE *ofp;
  char str[1500], method_name[1500], name_file[1500];
  bool found;
  int count = 0, osr_bci, priority;
  const char *hotFile_name = HotMethodFileName!=NULL ? HotMethodFileName :
    "hotMethods.file";
  
  // if CompileOption == 1, then mark all methods above the specified
  // threshold as eligible to be compiled
  if(VMSignalOption == 1){
    int hotCount;
    for(int index=0 ; index<all_invoked_methods->length() ; index++){
      methodOop m = all_invoked_methods->at(index);
      hotCount = (m->our_invocation_count() + m->our_backedge_count());
      if(hotCount >= HotnessThreshold){
	m->isHot = 1;
	m->isOsr = 1;
      }
      m->invocation_counter()->init();
      m->backedge_counter()->init();
      m->our_invocation_counter()->init();
      m->our_backedge_counter()->init();
    }
  }
  // if CompileOption -- 2, then compile only the methods that are above a
  // certain HotnessThreshold
  else if(VMSignalOption == 2){
    static int count = 0;
    int numHotMethods = 0, numOsrMethods = 0, numCompiledMethods = 0;
    int hotCount;
    
    /*if count==0, then no methods should be compiled. We will clear out the
      hotMethods file at this time. For later 'count' values we will append
      to this file*/
    if(count == 0){
      if((ofp = fopen(hotFile_name, "w")) == NULL){
	fprintf(stderr, "File %s cannot be opened for writing\n", hotFile_name);
	exit(0);
      }
      fclose(ofp);
    }
    else if(count > 0){
      all_invoked_methods->sort(&compare_methods2);
      for(int index=0 ; index<all_invoked_methods->length() ; index++){
	methodOop m = all_invoked_methods->at(index);
	hotCount = (m->our_invocation_count() + m->our_backedge_count());
	if((m->our_invocation_count() > 1) && (hotCount >= HotnessThreshold)){
	  numHotMethods++;
	  m->isHot = numHotMethods;
	  //m->isHot = 1;
	  m->print_short_name(tty);
	  tty->print(" : %d %d\n", m->our_invocation_count(), m->our_backedge_count());
	}
	if((m->our_backedge_count() > 1) &&
	   (hotCount > InvocationCounter::InterpreterBackwardBranchLimit)){
	  numOsrMethods++;
	  m->isOsr = numOsrMethods;
	  //m->isOsr = 1;
	}
      }
    }
    /*When methods marked as hot finish compilation, their names will be
      entered in the file 'hotMethods.file' from the procedure
      'log_new_nmethod()' in nmethod.cpp*/
    tty->print_cr("PK: Number of hot methods: %d, OSR: %d\n",
		  numHotMethods, numOsrMethods);    
    count++;

    /*Initialize the counts of all methods*/
    for(int index=0 ; index<all_invoked_methods->length() ; index++){
      methodOop m = all_invoked_methods->at(index);
      //tty->print("Method Counts: ");
      //m->print_name(tty);
      //tty->print(": %d %d\n", m->invocation_count(), m->backedge_count());
      m->invocation_counter()->init();
      m->backedge_counter()->init();
      m->our_invocation_counter()->init();
      m->our_backedge_counter()->init();
    }
  }
  else if(VMSignalOption == 3){

    tty->print_cr("Start marking hot methods from file %s", hotFile_name);
    inFile.open(hotFile_name);
    if(!inFile){
      tty->print_cr("%s cannot be opened for reading\n", hotFile_name);
      exit(0);
    }

    // Each line in this file indicates the name of a hot method. We mark all
    // indicated methods as hot in their respective instances
    inFile.getline(str, 1500);
    while(inFile){
      found = false;

      sscanf(str, "Name:%s bci:%d Priority:%d", name_file, &osr_bci, &priority);
      for(int index=0 ; index<all_invoked_methods->length() ; index++){
	methodOop m = all_invoked_methods->at(index);
	m->getName(method_name);
	if(strcmp(name_file, method_name) == 0){
	  m->isHot = 1;
	  if(osr_bci > 0){
	    /* can only OSR compile the first encountered loop in a method*/
	    if(m->isOsr == 0)
	      m->isOsr = osr_bci;
	  }
	  /*tty->print("Final: ");
	  m->print_name(tty);
	  tty->print(": Counts: %d %d\n",
		     m->our_invocation_counter()->count(),
		     m->our_backedge_counter()->count());*/

	  m->invocation_counter()->init();
	  m->backedge_counter()->init();
	  found = true;
	  break;
	}
      }
      if(!found)
	tty->print_cr("Method %s not found in the methodOop array\n", str);
      inFile.getline(str, 1500);
    }
    inFile.close();

    // Reset the counts of all methods
    for(int index=0 ; index<all_invoked_methods->length() ; index++){
      methodOop m = all_invoked_methods->at(index);
      m->our_invocation_counter()->init();
      m->our_backedge_counter()->init();
    }
  }
  /* Stage compile */
  else if(VMSignalOption == 4){
    #define PERCENT 1
    #define THRESHOLD 2
    /*The goal of this option is to see how each (set of) compiles
      progressively improves benchmark performance
      With this option we compile a percentage of the hot methods after every
      few runs*/
    int percent_compile[]={0, 1, 2, 5, 10, 25, 50, 100, 200, 500, -1, -1, -1};
    //int percent_compile[]={10, 25, 50, 100, 200, 500, -1, -1, -1};
    int c2CompileThreshold[] = {0, 500000, 250000, 100000, 50000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, -1, -1, -1};
    //int c2CompileThreshold[] = {0, 50000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, -1, -1, -1};
    int iter_per_step = 5;
    int compile_option = THRESHOLD;
    int num_methods, total_methods, hot_methods, cur_threshold;
    int i, index, t1;

    /* Our input file contains a list of methods to compile, sorted by
      (invocation+backedge) counts. We compile the next set of methods at
      each step. We mark the methods as hot here. Hot methods should be
      compiled at their first next invocation.*/
    if((VMIndicatorReached % iter_per_step) == 0){
      
      inFile.open(hotFile_name);
      if(!inFile){
	tty->print_cr("%s cannot be opened for reading\n", hotFile_name);
	exit(0);
      }

      /* The first line in this file lists the number of total and hot
	 methods for this benchmark*/
      inFile.getline(str, 1500);
      sscanf(str, "Total methods: %d, Hot methods: %d",
	     &total_methods, &hot_methods);

      /*Find the number of methods to be compiled in this step as a
	percentage of the hot methods*/
      index = VMIndicatorReached / iter_per_step;
      if(compile_option == PERCENT){
	num_methods = (hot_methods * percent_compile[index]) / 100;
      
	/*Mark hot methods to be compiled in this stage*/
	if(num_methods >= 0){
	  tty->print_cr("\nTotal number of methods compiled (CountCompiledMethods) = %d\n",
		 CountCompiledMethods);
	  tty->print_cr("\n\nStart stage %d. Compile %d%% = %d methods\n\n",
			index, percent_compile[index], num_methods);
	}
      }
      else if(compile_option == THRESHOLD){
	num_methods = 0;
	cur_threshold = c2CompileThreshold[index];
      }

      /* For all the usual cases*/
      if((compile_option==PERCENT && num_methods >= 0) ||
	 (compile_option==THRESHOLD && cur_threshold >= 0)){

	inFile.getline(str, 1500);
	while(inFile){
	  found = false;
	  
	  if((sscanf(str, "Name: %s , Count: %d", name_file, &t1)) == 2){
	    if(compile_option==THRESHOLD &&
	       (cur_threshold==0 || t1<cur_threshold)){
	      tty->print_cr("\nTotal number of methods compiled (CountCompiledMethods) = %d\n",
		     CountCompiledMethods);
	      tty->print_cr("\n\nStart stage %d. Threshold %d = %d methods\n\n",
			    index, c2CompileThreshold[index], num_methods);
	      break;
	    }
	    
	    for(i=0 ; i<all_invoked_methods->length() ; i++){
	      methodOop m = all_invoked_methods->at(i);
	      m->getName(method_name);
	      if(strcmp(name_file, method_name) == 0){
		m->isHot = 1;
		found = true;
		break;
	      }
	    }
	    if(!found)
	      tty->print_cr("Method %s not found in the methodOop array\n", name_file);
	    
	    /* break out if we have marked the pecentage of hot methods to be
	       compiled at this stage*/
	    if(compile_option == PERCENT){
	      if(num_methods > 0)
		num_methods--;
	      if(num_methods == 0)
		break;
	    }
	    else if(compile_option == THRESHOLD)
	      num_methods++;
	  }
	  inFile.getline(str, 1500);
	}
      }
      else{
	/* Compile all methods that are currently active*/
	num_methods = 0;
	for(i=0 ; i<all_invoked_methods->length() ; i++){
	  methodOop m = all_invoked_methods->at(i);
	  m->isHot = 1;
	  num_methods++;
	}
	tty->print_cr("\nTotal number of methods compiled (CountCompiledMethods) = %d\n",
	       CountCompiledMethods);
	if(compile_option == PERCENT)
	  tty->print_cr("\n\nStart stage %d. Compile %d%% = %d methods\n\n",
			index, percent_compile[index], num_methods);
	else if(compile_option == THRESHOLD)
	  tty->print_cr("\n\nStart stage %d. Threshold %d = %d methods\n\n",
			index, c2CompileThreshold[index], num_methods);
      }
      inFile.close();
    }
  }
  /* Sort methods based on their hotness counts. Write their sorted rank as
     their priority. Hotter methods will be sent to compile earlier using a
     sorted priority queue*/
  else if(VMSignalOption == 5){
    int numHotMethods = 1;
    int hotCount;
    
    all_invoked_methods->sort(&compare_methods2);
    for(int index=0 ; index<all_invoked_methods->length() ; index++){
      methodOop m = all_invoked_methods->at(index);
      m->isHot = numHotMethods++; // holds the method priority
      m->isOsr = 1; // enable OSR compilation

      /*re-initialize method counters*/
      m->invocation_counter()->init();
      m->backedge_counter()->init();
      m->our_invocation_counter()->init();
      m->our_backedge_counter()->init();
    }
  }
  
  // VMIndicator method processed one more time
  VMIndicatorReached++;
}

#ifndef PRODUCT

// Statistics printing (method invocation histogram)

GrowableArray<methodOop>* collected_invoked_methods;

void collect_invoked_methods(methodOop m) {
  if (m->invocation_count() + m->compiled_invocation_count() >= 1 ) {
    collected_invoked_methods->push(m);
  }
}


GrowableArray<methodOop>* collected_profiled_methods;

void collect_profiled_methods(methodOop m) {
  methodHandle mh(Thread::current(), m);
  if ((m->method_data() != NULL) &&
      (PrintMethodData || CompilerOracle::should_print(mh))) {
    collected_profiled_methods->push(m);
  }
}


void print_method_invocation_histogram() {
  ResourceMark rm;
  HandleMark hm;
  collected_invoked_methods = new GrowableArray<methodOop>(1024);
  SystemDictionary::methods_do(collect_invoked_methods);
  collected_invoked_methods->sort(&compare_methods2);
  //
  tty->cr();
  tty->print_cr("Histogram Over MethodOop Invocation Counters (cutoff = %d):", MethodHistogramCutoff);
  tty->cr();
  tty->print_cr("____Count_(I+C)____Method________________________Module_________________");
  unsigned total = 0, int_total = 0, comp_total = 0, static_total = 0, final_total = 0,
      synch_total = 0, nativ_total = 0, acces_total = 0;
  unsigned long long tot_exec_counts = 0;
  for (int index = 0; index < collected_invoked_methods->length(); index++) {
    methodOop m = collected_invoked_methods->at(index);
    int c = m->invocation_count() + m->compiled_invocation_count();
    // PK: remove the following branch later
    if(MethodHistogramCutoff > 0){
      if (c >= MethodHistogramCutoff)
	m->print_invocation_count();
    }
    //PK:
    /*if(c > 0){
      tty->print("Histogram: ");
      m->print_name(tty);
      tty->print(": Counts: %d %d %d %d\n",
		 m->our_invocation_counter()->count(),
		 m->our_backedge_counter()->count(),
		 m->initial_inv_count(), m->initial_back_count());
		 }*/
      
    tot_exec_counts += (m->our_invocation_count() + m->our_backedge_count());
    int_total  += m->invocation_count();
    comp_total += m->compiled_invocation_count();
    if (m->is_final())        final_total  += c;
    if (m->is_static())       static_total += c;
    if (m->is_synchronized()) synch_total  += c;
    if (m->is_native())       nativ_total  += c;
    if (m->is_accessor())     acces_total  += c;
  }
  tty->cr();
  total = int_total + comp_total;
  tty->print_cr("Invocations summary:");
  // PK: additional statistics
  tty->print_cr("Total execution counts: %lld\n", tot_exec_counts);
  tty->print_cr("Total invocation counts: %lld\n", totInvCount);
  tty->print_cr("Total backedge counts: %lld\n", totBackCount);
  // PK: end
  
  tty->print_cr("\t%9d (%4.1f%%) interpreted",  int_total,    100.0 * int_total    / total);
  tty->print_cr("\t%9d (%4.1f%%) compiled",     comp_total,   100.0 * comp_total   / total);
  tty->print_cr("\t%9d (100%%)  total",         total);
  tty->print_cr("\t%9d (%4.1f%%) synchronized", synch_total,  100.0 * synch_total  / total);
  tty->print_cr("\t%9d (%4.1f%%) final",        final_total,  100.0 * final_total  / total);
  tty->print_cr("\t%9d (%4.1f%%) static",       static_total, 100.0 * static_total / total);
  tty->print_cr("\t%9d (%4.1f%%) native",       nativ_total,  100.0 * nativ_total  / total);
  tty->print_cr("\t%9d (%4.1f%%) accessor",     acces_total,  100.0 * acces_total  / total);
  tty->cr();
  SharedRuntime::print_call_statistics(comp_total);
}

void print_method_profiling_data() {
  ResourceMark rm;
  HandleMark hm;
  collected_profiled_methods = new GrowableArray<methodOop>(1024);
  SystemDictionary::methods_do(collect_profiled_methods);
  collected_profiled_methods->sort(&compare_methods);

  int count = collected_profiled_methods->length();
  if (count > 0) {
    for (int index = 0; index < count; index++) {
      methodOop m = collected_profiled_methods->at(index);
      ttyLocker ttyl;
      tty->print_cr("------------------------------------------------------------------------");
      //m->print_name(tty);
      m->print_invocation_count();
      tty->cr();
      m->print_codes();
    }
    tty->print_cr("------------------------------------------------------------------------");
  }
}

void print_bytecode_count() {
  if (CountBytecodes || TraceBytecodes || StopInterpreterAt) {
    tty->print_cr("[BytecodeCounter::counter_value = %d]", BytecodeCounter::counter_value());
  }
}

AllocStats alloc_stats;



// General statistics printing (profiling ...)

void print_statistics() {

#ifdef ASSERT

  if (CountRuntimeCalls) {
    extern Histogram *RuntimeHistogram;
    RuntimeHistogram->print();
  }

  if (CountJNICalls) {
    extern Histogram *JNIHistogram;
    JNIHistogram->print();
  }

  if (CountJVMCalls) {
    extern Histogram *JVMHistogram;
    JVMHistogram->print();
  }

#endif

  if (MemProfiling) {
    MemProfiler::disengage();
  }

  if (CITime) {
    CompileBroker::print_times();
  }

#ifdef COMPILER1
  if ((PrintC1Statistics || LogVMOutput || LogCompilation) && UseCompiler) {
    FlagSetting fs(DisplayVMOutput, DisplayVMOutput && PrintC1Statistics);
    Runtime1::print_statistics();
    Deoptimization::print_statistics();
    nmethod::print_statistics();
  }
#endif /* COMPILER1 */

#ifdef COMPILER2
  if ((PrintOptoStatistics || LogVMOutput || LogCompilation) && UseCompiler) {
    FlagSetting fs(DisplayVMOutput, DisplayVMOutput && PrintOptoStatistics);
    Compile::print_statistics();
#ifndef COMPILER1
    Deoptimization::print_statistics();
    nmethod::print_statistics();
#endif //COMPILER1
    SharedRuntime::print_statistics();
    os::print_statistics();
  }

  if (PrintLockStatistics || PrintPreciseBiasedLockingStatistics) {
    OptoRuntime::print_named_counters();
  }

  if (TimeLivenessAnalysis) {
    MethodLiveness::print_times();
  }
#ifdef ASSERT
  if (CollectIndexSetStatistics) {
    IndexSet::print_statistics();
  }
#endif // ASSERT
#endif // COMPILER2
  if (MethodHistogramCutoff==0 || CountCompiledCalls) {
    print_method_invocation_histogram();
  }
  if (ProfileInterpreter || Tier1UpdateMethodData) {
    print_method_profiling_data();
  }
  if (TimeCompiler) {
    COMPILER2_PRESENT(Compile::print_timers();)
  }
  if (TimeCompilationPolicy) {
    CompilationPolicy::policy()->print_time();
  }
  if (TimeOopMap) {
    GenerateOopMap::print_time();
  }
  if (ProfilerCheckIntervals) {
    PeriodicTask::print_intervals();
  }
  if (PrintSymbolTableSizeHistogram) {
    SymbolTable::print_histogram();
  }
  if (CountBytecodes || TraceBytecodes || StopInterpreterAt) {
    BytecodeCounter::print();
  }
  if (PrintBytecodePairHistogram) {
    BytecodePairHistogram::print();
  }

  if (PrintCodeCache) {
    MutexLockerEx mu(CodeCache_lock, Mutex::_no_safepoint_check_flag);
    CodeCache::print();
  }

  if (PrintCodeCache2) {
    MutexLockerEx mu(CodeCache_lock, Mutex::_no_safepoint_check_flag);
    CodeCache::print_internals();
  }

  if (PrintClassStatistics) {
    SystemDictionary::print_class_statistics();
  }
  if (PrintMethodStatistics) {
    SystemDictionary::print_method_statistics();
  }

  if (PrintVtableStats) {
    klassVtable::print_statistics();
    klassItable::print_statistics();
  }
  if (VerifyOops) {
    tty->print_cr("+VerifyOops count: %d", StubRoutines::verify_oop_count());
  }

  print_bytecode_count();
  if (WizardMode) {
    tty->print("allocation stats: ");
    alloc_stats.print();
    tty->cr();
  }

  if (PrintSystemDictionaryAtExit) {
    SystemDictionary::print();
  }

  if (PrintBiasedLockingStatistics) {
    BiasedLocking::print_counters();
  }

#ifdef ENABLE_ZAP_DEAD_LOCALS
#ifdef COMPILER2
  if (ZapDeadCompiledLocals) {
    tty->print_cr("Compile::CompiledZap_count = %d", Compile::CompiledZap_count);
    tty->print_cr("OptoRuntime::ZapDeadCompiledLocals_count = %d", OptoRuntime::ZapDeadCompiledLocals_count);
  }
#endif // COMPILER2
#endif // ENABLE_ZAP_DEAD_LOCALS
}

#else // PRODUCT MODE STATISTICS

void print_statistics() {

  if (CITime) {
    CompileBroker::print_times();
  }
#ifdef COMPILER2
  if (PrintPreciseBiasedLockingStatistics) {
    OptoRuntime::print_named_counters();
  }
#endif
  if (PrintBiasedLockingStatistics) {
    BiasedLocking::print_counters();
  }
}

#endif


// Helper class for registering on_exit calls through JVM_OnExit

extern "C" {
    typedef void (*__exit_proc)(void);
}

class ExitProc : public CHeapObj {
 private:
  __exit_proc _proc;
  // void (*_proc)(void);
  ExitProc* _next;
 public:
  // ExitProc(void (*proc)(void)) {
  ExitProc(__exit_proc proc) {
    _proc = proc;
    _next = NULL;
  }
  void evaluate()               { _proc(); }
  ExitProc* next() const        { return _next; }
  void set_next(ExitProc* next) { _next = next; }
};


// Linked list of registered on_exit procedures

static ExitProc* exit_procs = NULL;


extern "C" {
  void register_on_exit_function(void (*func)(void)) {
    ExitProc *entry = new ExitProc(func);
    // Classic vm does not throw an exception in case the allocation failed,
    if (entry != NULL) {
      entry->set_next(exit_procs);
      exit_procs = entry;
    }
  }
}

// Note: before_exit() can be executed only once, if more than one threads
//       are trying to shutdown the VM at the same time, only one thread
//       can run before_exit() and all other threads must wait.
void before_exit(JavaThread * thread) {
  #define BEFORE_EXIT_NOT_RUN 0
  #define BEFORE_EXIT_RUNNING 1
  #define BEFORE_EXIT_DONE    2
  static jint volatile _before_exit_status = BEFORE_EXIT_NOT_RUN;

  // Note: don't use a Mutex to guard the entire before_exit(), as
  // JVMTI post_thread_end_event and post_vm_death_event will run native code.
  // A CAS or OSMutex would work just fine but then we need to manipulate
  // thread state for Safepoint. Here we use Monitor wait() and notify_all()
  // for synchronization.
  { MutexLocker ml(BeforeExit_lock);
    switch (_before_exit_status) {
    case BEFORE_EXIT_NOT_RUN:
      _before_exit_status = BEFORE_EXIT_RUNNING;
      break;
    case BEFORE_EXIT_RUNNING:
      while (_before_exit_status == BEFORE_EXIT_RUNNING) {
        BeforeExit_lock->wait();
      }
      assert(_before_exit_status == BEFORE_EXIT_DONE, "invalid state");
      return;
    case BEFORE_EXIT_DONE:
      return;
    }
  }

  // The only difference between this and Win32's _onexit procs is that
  // this version is invoked before any threads get killed.
  ExitProc* current = exit_procs;
  while (current != NULL) {
    ExitProc* next = current->next();
    current->evaluate();
    delete current;
    current = next;
  }

  // Hang forever on exit if we're reporting an error.
  if (ShowMessageBoxOnError && is_error_reported()) {
    os::infinite_sleep();
  }

  // Terminate watcher thread - must before disenrolling any periodic task
  WatcherThread::stop();

  // Print statistics gathered (profiling ...)
  if (Arguments::has_profile()) {
    FlatProfiler::disengage();
    FlatProfiler::print(10);
  }

  // shut down the StatSampler task
  StatSampler::disengage();
  StatSampler::destroy();

#ifndef SERIALGC
  // stop CMS threads
  if (UseConcMarkSweepGC) {
    ConcurrentMarkSweepThread::stop();
  }
#endif // SERIALGC

  // Print GC/heap related information.
  if (PrintGCDetails) {
    Universe::print();
    AdaptiveSizePolicyOutput(0);
  }


  if (Arguments::has_alloc_profile()) {
    HandleMark hm;
    // Do one last collection to enumerate all the objects
    // allocated since the last one.
    Universe::heap()->collect(GCCause::_allocation_profiler);
    AllocationProfiler::disengage();
    AllocationProfiler::print(0);
  }

  if (PrintBytecodeHistogram) {
    BytecodeHistogram::print();
  }

  if (JvmtiExport::should_post_thread_life()) {
    JvmtiExport::post_thread_end(thread);
  }
  // Always call even when there are not JVMTI environments yet, since environments
  // may be attached late and JVMTI must track phases of VM execution
  JvmtiExport::post_vm_death();
  Threads::shutdown_vm_agents();

  // Terminate the signal thread
  // Note: we don't wait until it actually dies.
  os::terminate_signal_thread();

  print_statistics();
  Universe::heap()->print_tracing_info();

  VTune::exit();

  { MutexLocker ml(BeforeExit_lock);
    _before_exit_status = BEFORE_EXIT_DONE;
    BeforeExit_lock->notify_all();
  }

  // PK: print useful messages
  printf("\nTotal number of methods queued (CountQueuedMethods) = %d\n", CountQueuedMethods);
  printf("\nTotal number of methods compiled (CountCompiledMethods) = %d\n\n", CountCompiledMethods);
  
  //PK: print the times of all threads
  if(PKPrintThreads){
    Threads::print_thread_time();
    printf("\nCompiler Runtime: %lld, App. Runtime: %lld\n", compilerRunTime, appRunTime);
    //os::infinite_sleep();
  }
  
  #undef BEFORE_EXIT_NOT_RUN
  #undef BEFORE_EXIT_RUNNING
  #undef BEFORE_EXIT_DONE
}

void vm_exit(int code) {
  Thread* thread = ThreadLocalStorage::thread_index() == -1 ? NULL
    : ThreadLocalStorage::get_thread_slow();
  if (thread == NULL) {
    // we have serious problems -- just exit
    vm_direct_exit(code);
  }

  if (VMThread::vm_thread() != NULL) {
    // Fire off a VM_Exit operation to bring VM to a safepoint and exit
    VM_Exit op(code);
    if (thread->is_Java_thread())
      ((JavaThread*)thread)->set_thread_state(_thread_in_vm);
    VMThread::execute(&op);
    // should never reach here; but in case something wrong with VM Thread.
    vm_direct_exit(code);
  } else {
    // VM thread is gone, just exit
    vm_direct_exit(code);
  }
  ShouldNotReachHere();
}

void notify_vm_shutdown() {
  // For now, just a dtrace probe.
  HS_DTRACE_PROBE(hotspot, vm__shutdown);
  HS_DTRACE_WORKAROUND_TAIL_CALL_BUG();
}

void vm_direct_exit(int code) {
  notify_vm_shutdown();
  ::exit(code);
}

void vm_perform_shutdown_actions() {
  // Warning: do not call 'exit_globals()' here. All threads are still running.
  // Calling 'exit_globals()' will disable thread-local-storage and cause all
  // kinds of assertions to trigger in debug mode.
  if (is_init_completed()) {
    Thread* thread = Thread::current();
    if (thread->is_Java_thread()) {
      // We are leaving the VM, set state to native (in case any OS exit
      // handlers call back to the VM)
      JavaThread* jt = (JavaThread*)thread;
      // Must always be walkable or have no last_Java_frame when in
      // thread_in_native
      jt->frame_anchor()->make_walkable(jt);
      jt->set_thread_state(_thread_in_native);
    }
  }
  notify_vm_shutdown();
}

void vm_shutdown()
{
  vm_perform_shutdown_actions();
  os::shutdown();
}

void vm_abort(bool dump_core) {
  vm_perform_shutdown_actions();
  os::abort(dump_core);
  ShouldNotReachHere();
}

void vm_notify_during_shutdown(const char* error, const char* message) {
  if (error != NULL) {
    tty->print_cr("Error occurred during initialization of VM");
    tty->print("%s", error);
    if (message != NULL) {
      tty->print_cr(": %s", message);
    }
    else {
      tty->cr();
    }
  }
  if (ShowMessageBoxOnError && WizardMode) {
    fatal("Error occurred during initialization of VM");
  }
}

void vm_exit_during_initialization(Handle exception) {
  tty->print_cr("Error occurred during initialization of VM");
  // If there are exceptions on this thread it must be cleared
  // first and here. Any future calls to EXCEPTION_MARK requires
  // that no pending exceptions exist.
  Thread *THREAD = Thread::current();
  if (HAS_PENDING_EXCEPTION) {
    CLEAR_PENDING_EXCEPTION;
  }
  java_lang_Throwable::print(exception, tty);
  tty->cr();
  java_lang_Throwable::print_stack_trace(exception(), tty);
  tty->cr();
  vm_notify_during_shutdown(NULL, NULL);

  // Failure during initialization, we don't want to dump core
  vm_abort(false);
}

void vm_exit_during_initialization(symbolHandle ex, const char* message) {
  ResourceMark rm;
  vm_notify_during_shutdown(ex->as_C_string(), message);

  // Failure during initialization, we don't want to dump core
  vm_abort(false);
}

void vm_exit_during_initialization(const char* error, const char* message) {
  vm_notify_during_shutdown(error, message);

  // Failure during initialization, we don't want to dump core
  vm_abort(false);
}

void vm_shutdown_during_initialization(const char* error, const char* message) {
  vm_notify_during_shutdown(error, message);
  vm_shutdown();
}

JDK_Version JDK_Version::_current;

void JDK_Version::initialize() {
  jdk_version_info info;
  assert(!_current.is_valid(), "Don't initialize twice");

  void *lib_handle = os::native_java_library();
  jdk_version_info_fn_t func = CAST_TO_FN_PTR(jdk_version_info_fn_t,
     os::dll_lookup(lib_handle, "JDK_GetVersionInfo0"));

  if (func == NULL) {
    // JDK older than 1.6
    _current._partially_initialized = true;
  } else {
    (*func)(&info, sizeof(info));

    int major = JDK_VERSION_MAJOR(info.jdk_version);
    int minor = JDK_VERSION_MINOR(info.jdk_version);
    int micro = JDK_VERSION_MICRO(info.jdk_version);
    int build = JDK_VERSION_BUILD(info.jdk_version);
    if (major == 1 && minor > 4) {
      // We represent "1.5.0" as "5.0", but 1.4.2 as itself.
      major = minor;
      minor = micro;
      micro = 0;
    }
    _current = JDK_Version(major, minor, micro, info.update_version,
                           info.special_update_version, build,
                           info.thread_park_blocker == 1);
  }
}

void JDK_Version::fully_initialize(
    uint8_t major, uint8_t minor, uint8_t micro, uint8_t update) {
  // This is only called when current is less than 1.6 and we've gotten
  // far enough in the initialization to determine the exact version.
  assert(major < 6, "not needed for JDK version >= 6");
  assert(is_partially_initialized(), "must not initialize");
  if (major < 5) {
    // JDK verison sequence: 1.2.x, 1.3.x, 1.4.x, 5.0.x, 6.0.x, etc.
    micro = minor;
    minor = major;
    major = 1;
  }
  _current = JDK_Version(major, minor, micro, update);
}

void JDK_Version_init() {
  JDK_Version::initialize();
}

static int64_t encode_jdk_version(const JDK_Version& v) {
  return
    ((int64_t)v.major_version()          << (BitsPerByte * 5)) |
    ((int64_t)v.minor_version()          << (BitsPerByte * 4)) |
    ((int64_t)v.micro_version()          << (BitsPerByte * 3)) |
    ((int64_t)v.update_version()         << (BitsPerByte * 2)) |
    ((int64_t)v.special_update_version() << (BitsPerByte * 1)) |
    ((int64_t)v.build_number()           << (BitsPerByte * 0));
}

int JDK_Version::compare(const JDK_Version& other) const {
  assert(is_valid() && other.is_valid(), "Invalid version (uninitialized?)");
  if (!is_partially_initialized() && other.is_partially_initialized()) {
    return -(other.compare(*this)); // flip the comparators
  }
  assert(!other.is_partially_initialized(), "Not initialized yet");
  if (is_partially_initialized()) {
    assert(other.major_version() >= 6,
           "Invalid JDK version comparison during initialization");
    return -1;
  } else {
    uint64_t e = encode_jdk_version(*this);
    uint64_t o = encode_jdk_version(other);
    return (e > o) ? 1 : ((e == o) ? 0 : -1);
  }
}

void JDK_Version::to_string(char* buffer, size_t buflen) const {
  size_t index = 0;
  if (!is_valid()) {
    jio_snprintf(buffer, buflen, "%s", "(uninitialized)");
  } else if (is_partially_initialized()) {
    jio_snprintf(buffer, buflen, "%s", "(uninitialized) pre-1.6.0");
  } else {
    index += jio_snprintf(
        &buffer[index], buflen - index, "%d.%d", _major, _minor);
    if (_micro > 0) {
      index += jio_snprintf(&buffer[index], buflen - index, ".%d", _micro);
    }
    if (_update > 0) {
      index += jio_snprintf(&buffer[index], buflen - index, "_%02d", _update);
    }
    if (_special > 0) {
      index += jio_snprintf(&buffer[index], buflen - index, "%c", _special);
    }
    if (_build > 0) {
      index += jio_snprintf(&buffer[index], buflen - index, "-b%02d", _build);
    }
  }
}
