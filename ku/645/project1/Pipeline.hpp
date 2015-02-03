#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

#define INVALIDSTR "INV";

const int PIPE_LENGTH = 9;

const string pipe[11] = {
	"IF1  ",
	"IF2  ",
	"IF3  ",
	"ID   ",
	"EX   ",
	"MEM1 ",
	"MEM2 ",
	"MEM3 ",
	"WB   ",
	"S    ",
	"     "
};

const string cmds_str[5] = {
	"LD:    ",
	"SD:    ",
	"DADD:  ",
	"DADDI: ",
	"BNEZ:  "
};

enum STAGES {
	IF1,
	IF2,
	IF3,
	ID,
	EX,
	MEM1,
	MEM2,
	MEM3,
	WB,
	S,
	BLANK,
};

enum WHICH_TIMING {
	NO_BYPASS,
	BRANCH_TAKEN,
	BRANCH_NOT_TAKEN
};

enum CMD_TYPE {
	LD,
	SD,
	DADD,
	DADDI,
	BNEZ,
	INVALID = -1
};

struct Command {
	CMD_TYPE type;
	int r1;
	int r2;
	int r3;
	int offset;
	int imm;
	string label; 

	Command() {
		r1 = -1;
		r2 = -1;
		r3 = -1;
		offset = -1;
		imm = -1;
		type = INVALID;
		label = INVALIDSTR
	};

	Command(int R1, int R2, int R3, int Offset, int Imm) {
		r1 = R2;
		r2 = R2;
		r3 = R3;
		offset = Offset;
		imm = Imm;
		type = INVALID;
		label = INVALIDSTR;
	};

	void print() { 
		cout << "r1: " << r1 << endl;
		cout << "r2: " << r2 << endl;
		cout << "r3: " << r3 << endl;
		cout << "offset: " << offset << endl;
		cout << "imm: " << imm << endl;
		cout << "type: " << type << endl;
		cout << "label: " << label << endl;
	}	
};

class Pipeline {
public:
	Pipeline();
	Pipeline(
		string infile, 
		string Timingfile, 
		string Regfile,
		WHICH_TIMING mode
		);

	void getInput();
	void executeProgram();
	void flushPipeline();


	void printRegisters();
	void printTimings();

	void printCommands();

//Private functions
private:
	int parseRegister(string reg);
	int parseRegisterOffset(string reg); 
	int parseOffsetRegister(string reg); 
	int parseImmediate(string imm);
	Command parseLD(stringstream &ss);
	Command parseSD(stringstream &ss);
	Command parseDADD(stringstream &ss);
	Command parseDADDI(stringstream &ss);
	Command parseBNEZ(stringstream &ss);

	void calcTiming(int cmd_idx);
	void calcTimingNoBypass(int cmd_idx);
	void calcTimingBypass(int cmd_idx);

	void handleBranchStalls(int cmd_idx, bool branch_taken);
	bool isFlushTiming(int timings_idx);

	int getStageIdx(
		int timings_idx, 
		STAGES stage
	);

	void insertSpaces(
		vector<string> &timing,
		const int num_spaces
	);
	
	int dependency(
		const int lookbehind_idx, 
		Command cmd, 	
		const int timings_idx 
	);

//Private variables
private:
	string infile;
	string timingfile; 
	string regfile;

	WHICH_TIMING which_timing;

	vector<Command> commands;
	map<string, int> labels; 

	int registers[32];
	char memory[992];

	vector<vector<string>> timings;
	vector<int> cmd_exe_order;
};







