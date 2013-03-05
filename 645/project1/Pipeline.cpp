#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Pipeline.hpp"

using namespace std;

Pipeline::Pipeline() {
	infile = "input-1.txt";
	timingfile = "timingfile.txt";
	regfile = "regfile.txt";

	which_timing = BRANCH_TAKEN;

	memset(registers, 0, sizeof(int) * 32);
	memset(memory, 0, sizeof(char) * 992);
}


Pipeline::Pipeline(
	string Infile, 
	string Timingfile, 
	string Regfile,
	WHICH_TIMING mode
) {

	infile = Infile;
	timingfile = Timingfile;
	regfile = Regfile;

	which_timing = mode;

	memset(registers, 0, sizeof(int) * 32);
	memset(memory, 0, sizeof(char) * 992);
}

void Pipeline::printCommands() {
	int i = 0;
	cout << "COMMANDS: " << endl;
	for(auto command : commands) {
		cout << "COMMAND: " << ++i << endl;
		command.print();
		cout << "\n\n";
	}

	cout << "LABELS :" << endl;
	for(auto label : labels) {
		cout << label.first << " : " << label.second << endl;
	}cout << endl;
}

void Pipeline::getInput() {
	fstream fin;
	fin.open(infile.c_str());
	if(fin.fail()) {
		cout << "Error opening file. Exiting.\n";
		exit(1);
	}

	string buffer;
	
	//Get initial register configuration:
	getline(fin, buffer);
	int count = 0;
	for(fin >> buffer; buffer[0] != 'M'; fin >> buffer) {
		int val; 
		fin >> val; 
		registers[parseRegister(buffer)] = val;
	}

	//Get values at memory locations
	for(fin >> buffer; buffer[0] != 'C'; fin >> buffer) {
		int val;
		fin >> val; 
		memory[stoi(buffer)] = val;
	}

	getline(fin, buffer);
	int cmd_num = 0;
	while(getline(fin, buffer)) {
		Command command;
		stringstream ss(buffer);

		ss >> buffer;

		//Decide what whetherthis line starts with a label
		if(':' == buffer[buffer.length() - 1]) {
			//Clip off the ':' off the end and map the label to
			// index 0 of the cmd vector
			string label = buffer.substr(0, buffer.length() - 1);
			labels[label] = cmd_num;
			ss >> buffer;
		}
		
		if("LD" == buffer) {
			command = parseLD(ss);
		}
		else if("SD" == buffer) {
			command = parseSD(ss);
		}
		else if("DADD" == buffer) {
			command = parseDADD(ss);	
		}
		else if("DADDI" == buffer) {
			command = parseDADDI(ss);
		}
		else if("BNEZ" == buffer) {
			command = parseBNEZ(ss);
		} else {
			cout << "Error getting input. Exiting.\n";
			exit(1);
		}

		commands.push_back(command);
		cmd_num++;
	}

	fin.close();
}

//e.g. LD R1 8(R2)
Command Pipeline::parseLD(stringstream &ss) {
	Command command;
	string buffer;

	//get the destination register
	ss >> buffer;
	command.r1 = parseRegister(buffer); 

	//get the operand register and memory offset
	ss >> buffer;
	command.r2 = parseRegisterOffset(buffer);
	command.offset = parseOffsetRegister(buffer);

	command.type = LD;

	return command;
}

Command Pipeline::parseSD(stringstream &ss) {
	Command command; 
	string buffer; 

	//get the operand register and memory offset
	ss >> buffer;
	command.r1 = parseRegisterOffset(buffer);
	command.offset = parseOffsetRegister(buffer);
	
	//get the destination register
	ss >> buffer;
	command.r2 = parseRegister(buffer); 

	command.type = SD;

	return command;
}

Command Pipeline::parseDADD(stringstream &ss) {
	Command command;
	string buffer;

	//get the destination register
	ss >> buffer;
	command.r1 = parseRegister(buffer); 

	//get the destination register
	ss >> buffer;
	command.r2 = parseRegister(buffer); 

	//get the destination register
	ss >> buffer;
	command.r3 = parseRegister(buffer); 

	command.type = DADD; 

	return command;
}

Command Pipeline::parseDADDI(stringstream &ss) {
	Command command;
	string buffer; 

	//get the destination register
	ss >> buffer;
	command.r1 = parseRegister(buffer); 

	ss >> buffer;
	command.r2 = parseRegister(buffer); 

	ss >> buffer; 
	command.imm = parseImmediate(buffer); 

	command.type = DADDI; 

	return command;
}

Command Pipeline::parseBNEZ(stringstream &ss) {
	Command command;
	string buffer;

	//get the destination register
	ss >> buffer;
	command.r1 = parseRegister(buffer); 

	//get the label to branch to
	ss >> buffer;
	command.label = buffer;

	command.type = BNEZ; 

	return command;
}

//given reg = R9, returns 9
int Pipeline::parseRegister(string reg) {
	reg = reg.substr(1, reg.length());
	return stoi(reg);
}

//given reg = "-8(R3)", returns 3
int Pipeline::parseRegisterOffset(string reg) {
	for(int i = 0; i < reg.length(); i++) {
		if('R' == reg[i]) {
			reg = reg.substr(i + 1, reg.length() - i);
			break;
		}
	}
	return stoi(reg);
}

//given reg = "-8(R3)", returns -8
int Pipeline::parseOffsetRegister(string reg) {
	for(int i = 0; i < reg.length(); i++) {
		if('(' == reg[i]) {
			reg = reg.substr(0, i);
			break;
		}
	}
	return stoi(reg);
}

//given imm = #-64, returns -64
int Pipeline::parseImmediate(string imm) {
	return stoi(imm.substr(1, imm.length() - 1));
}

void Pipeline::executeProgram() {
	for(int i = 0; i < commands.size(); i++) {
		Command cmd = commands[i];
		bool taken = false;

		cmd_exe_order.push_back(i);
		if(LD == cmd.type) {
			registers[cmd.r1] = memory[registers[cmd.r2] + cmd.offset];
			calcTiming(i);
		}
		else if(SD == cmd.type) {
			memory[registers[cmd.r1] + cmd.offset] = registers[cmd.r2];
			calcTiming(i);
		}
		else if(DADD == cmd.type) {
			registers[cmd.r1] = registers[cmd.r2] + registers[cmd.r3];
			calcTiming(i);
		}
		else if(DADDI == cmd.type) {
			registers[cmd.r1] = registers[cmd.r2] + cmd.imm;
			calcTiming(i);
		}
		else if(BNEZ == cmd.type) {
			calcTiming(i);
			int tmp = i;
			if(0 != registers[cmd.r1]) {
				i = labels[cmd.label] - 1;
				taken = true;
			}
			handleBranchStalls(tmp, taken);
		} else {
			cout << "Bad command read during execution. Exiting\n";
			exit(1);
		}
	}
}

void Pipeline::handleBranchStalls(int cmd_idx, bool branch_taken) {
	vector<string> timing;
	int target_idx = getStageIdx(timings.size() - 1, IF2);
	insertSpaces(timing, target_idx);

	switch(which_timing) {
		case NO_BYPASS:
			timing.push_back(pipe[IF1]);		
			
			// Add stalls
			for(int stall_cnt = 1; stall_cnt < PIPE_LENGTH; stall_cnt++){
				timing.push_back(pipe[S]);				
			}
			cmd_exe_order.push_back(cmd_idx + 1);
			timings.push_back(timing);
			break;

		case BRANCH_TAKEN:
			target_idx = getStageIdx(timings.size() - 1, ID); 
			if(!branch_taken) {
				timing.push_back(pipe[IF1]);		
				
				// Add stalls
				for(int stall_cnt = 1; stall_cnt < PIPE_LENGTH; stall_cnt++){
					timing.push_back(pipe[S]);				
				}
				cmd_exe_order.push_back(labels[commands[cmd_idx].label]);
				timings.push_back(timing);
			}

			break;
		case BRANCH_NOT_TAKEN:
			if(branch_taken) {
				timing.push_back(pipe[IF1]);		
				
				// Add stalls
				for(int stall_cnt = 1; stall_cnt < PIPE_LENGTH; stall_cnt++){
					timing.push_back(pipe[S]);				
				}
				cmd_exe_order.push_back(cmd_idx + 1);
				timings.push_back(timing);
			}
			
			break;
	}
}

void Pipeline::printRegisters() { 
	ofstream fout;
	fout.open(regfile.c_str());
	if(fout.fail()) {
		cout << "Error Opening " << regfile 
		     << " in printRegisters(). Exiting.\n";
		exit(1);
	}

	for(int i = 0; i < 32; i++) {
		stringstream ss;
		ss << i;
		fout.width(5);
		fout << "R" + ss.str();
	}

	fout << endl;
	for(int i = 0; i < 32; i++) {
		fout.width(5);
		fout << registers[i];
	}

	fout << endl;
	fout.close();
}

void Pipeline::printTimings() {
	ofstream fout(timingfile.c_str());	
	if(fout.fail()){
		cout << "Error Opening File. Exiting.\n";
		exit(1);
	}

	fout << "          ";

	// Print the top row 
	for(auto i : cmd_exe_order) {
		stringstream ss;
		ss << i + 1; 
		fout.width(5);
		fout << left << "I#" + ss.str();
	}
	fout << endl;

	// We want the outer look to go as deep as the last 
	//  commands timing is long.
	for(int j = 0; j < timings[timings.size()-1].size(); j++) {
		stringstream ss;
		ss << j + 1;
		fout.width(10);
		fout << left << "C#" + ss.str();
		for(int i = 0; i < timings.size(); i++) {

			if(j < timings[i].size()) {
				fout << timings[i][j];
			} else {
				fout << pipe[BLANK];
			}
		}
		fout << endl;
	}
	fout.close();
}

void Pipeline::calcTiming(int cmd_idx) {
	switch(which_timing) {
		case NO_BYPASS:
			calcTimingNoBypass(cmd_idx);
			break;
		case BRANCH_TAKEN:
		case BRANCH_NOT_TAKEN:
			calcTimingBypass(cmd_idx);
			break;
		default:
			cout << "Error in calcTiming. Exiting.\n";
			exit(1);
	}
}

//Gets the index withing a timing vector that the given 
// stage occures.
int Pipeline::getStageIdx(int timings_idx, STAGES stage) {
	// First, make sure last stage wasn't flush stage from a branch
	if(isFlushTiming(timings_idx) && IF1 != stage) {
		return getStageIdx(timings_idx, IF1) + 1;
	}

	int idx = -1;
	vector<string> timing = timings[timings_idx];

	for(int i = 0; i < timing.size(); i++) {
		if(pipe[stage] == timing[i]) {
			idx = i;	
			break;
		}
	}
	return idx;
}

// True if the last stage in a timing is a stall. 
bool Pipeline::isFlushTiming(int timings_idx) {
	vector<string> timing = timings[timings_idx];
	return pipe[S] == timing[timing.size() - 1];
}

void Pipeline::insertSpaces(vector<string> &timing, const int num_spaces) {
	for(int i = 0; i < num_spaces; i++) {
		timing.push_back(pipe[BLANK]);
	}
}

//Finds a depency with a previous instruction if it exists, 
// then returns it's index in the Command vector
int Pipeline::dependency(
	const int lookbehind_idx, 
	Command cmd, 
	const int cmd_idx 
) {
	int ret_val = INVALID;

	for(int i = cmd_idx - 1; i >= lookbehind_idx && ret_val == INVALID; i--) {

		Command prev_cmd = commands[i];
		CMD_TYPE prev_type = prev_cmd.type;

		switch(cmd.type) {
			case LD:
			case SD: 
			case BNEZ: 
				if(cmd.r2 = prev_cmd.r1
				   && BNEZ != prev_type
				   && SD   != prev_type ) {
					ret_val = i;
				}
				break;
			case DADD:
			case DADDI:
				if((cmd.r2 == prev_cmd.r1 || cmd.r2 == prev_cmd.r1)
				   && BNEZ != prev_type 
				   && SD   != prev_type ) {
					ret_val = i;
				}
				break;
		}
	}

	return ret_val;
}

void Pipeline::calcTimingNoBypass(int cmd_idx) {
	//Add the first command's stages to the pipeline
	vector<string> timing;
	if(0 == timings.size()) {
		for(int i = 0; i < PIPE_LENGTH; i++) {
			timing.push_back(pipe[i]);
		}
		timings.push_back(timing);
		return;
	}

	//Add each command into the timing vector while checking 
	// for dependencies
	Command cmd = commands[cmd_idx];
	int timings_idx = timings.size() - 1;

	//find IF2 in the previous command's timing
	int if1_idx =  getStageIdx(timings_idx, IF2);

	//Now we know where to put this command's IF1.
	//Insert blanks up inuntil if2_idx then push back the first stage
	insertSpaces(timing, if1_idx);
	timing.push_back(pipe[IF1]);

	if(isFlushTiming(timings_idx)) {
		int dep_timings_idx = timings_idx - 1;
		int if2_idx = getStageIdx(dep_timings_idx, EX);
		int num_stalls = if2_idx - if1_idx - 1;

		//insert the stalls
		for(int i = 0; i < num_stalls; i++) {
			timing.push_back(pipe[S]);
		}
	} else {
		int dep_idx = dependency(
			cmd_idx < 5 ? 0 : cmd_idx - 5,
			cmd, 
			cmd_idx
		);
		if(INVALID != dep_idx){
			int dep_timings_idx = timings_idx - (cmd_idx - dep_idx) + 1;
			int if2_idx = getStageIdx(dep_timings_idx, MEM2);
			int num_stalls = if2_idx - if1_idx - 1;

			//insert the stalls
			for(int i = 0; i < num_stalls; i++) {
				timing.push_back(pipe[S]);
			}
		}
	}

	//Insert the rest of the stages into the timing vector
	for(int stage = 1; stage < PIPE_LENGTH; stage++) {
		timing.push_back(pipe[stage]);
	}

	timings.push_back(timing);
}

void Pipeline::calcTimingBypass(int cmd_idx) {
	//Add the first command's stages to the pipeline
	vector<string> timing;
	if(0 == timings.size()) {
		for(int i = 0; i < PIPE_LENGTH; i++) {
			timing.push_back(pipe[i]);
		}
		timings.push_back(timing);
		return;
	}

	//Add each command into the timing vector while checking 
	// for dependencies
	Command cmd = commands[cmd_idx];
	int timings_idx = timings.size() - 1;

	//find IF2 in the previous command's timing
	int if1_idx =  getStageIdx(timings_idx, IF2);

	insertSpaces(timing, if1_idx);
	timing.push_back(pipe[IF1]);

	int dep_idx = dependency(
		cmd_idx ? cmd_idx - 1 : 0,
		cmd, 
		cmd_idx
	);
	if(INVALID != dep_idx){
		int dep_timings_idx = timings_idx - (cmd_idx - dep_idx) + 1;
		int if2_idx = getStageIdx(dep_timings_idx, MEM2);

		Command prev_cmd = commands[dep_idx];
		switch(prev_cmd.type) {
			case LD:
				if(BNEZ == cmd.type) {
					if2_idx = getStageIdx(dep_timings_idx, ID);
				} else {
					if2_idx = getStageIdx(dep_timings_idx, MEM1);		
				}

				break;
			case DADDI:
			case DADD:
				if(BNEZ == cmd.type) {
					if2_idx = getStageIdx(dep_timings_idx, ID);
				} else {
					if2_idx = getStageIdx(dep_timings_idx, IF3);		
				}
				break;
		}

		int num_stalls = if2_idx - if1_idx - 1;

		//insert the stalls
		for(int i = 0; i < num_stalls; i++) {
			timing.push_back(pipe[S]);
		}
	}

	//Insert the rest of the stages into the timing vector
	for(int stage = 1; stage < PIPE_LENGTH; stage++) {
		timing.push_back(pipe[stage]);
	}

	timings.push_back(timing);
}








