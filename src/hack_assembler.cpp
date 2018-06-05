#include <fstream>
#include <iostream>
#include <vector>
#include "instruction.hpp"
#include "label.hpp"
#include "config.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	Instruction ins;
	string filename = argv[1];
	vector<string> instruction;
	short addrCount = 0;

	ifstream filein(filename);
	for (string line; getline(filein, line);) {
	   auto count = line.find("//");

		if (line[0] == '/')
			continue;
		if (line[0] == LINE_END)
			continue;
		else if (line[0] == '(') {
			parseLabel(line, addrCount);
		} else if (count != string::npos) {
			instruction.push_back(trim(line.substr(0, count)));
			addrCount++;
		} else {
			instruction.push_back(trim(line));
			addrCount++;
		}
	}

	auto count = filename.find_last_of('.');
	string sub = filename.substr(0, count);
	string filenameout = sub + ".hack";
	ofstream fileout(filenameout);

	for (auto &l : instruction) {
		if (l.find('@') != string::npos) {
			fileout << ins.aIns(l) << endl;
		} else if (l.find('=') != string::npos) {
			string cInstruction = "111";
			cInstruction += ins.comp(l);
			cInstruction += ins.dest(l);
			fileout << cInstruction << "000" << endl;
		} else if (l.find(';') != string::npos) {
			fileout << "111" << ins.jump(l) << endl;
		}
	}

	return 0;
}
