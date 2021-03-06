// IllumioApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <cassert>
#include <regex>


std::map<std::string, std::string> getMapFromFile(std::string);
std::string cleanIpPort(std::string, int);
bool regexMatching(std::string , std::string);
void fromFlowOuput(std::string, std::string, std::map<std::string, std::string>);
void natFiletoOutput(std::string, std::string, std::string);

int main()
{
	/*
	std::string natfile = "C:\\Users\\Conor Lum\\Documents\\SampleNat.txt";
	std::string flowfile = "C:\\Users\\Conor Lum\\Documents\\SampleFlow.txt";
	std::string outputfile = "C:\\Users\\Conor Lum\\Documents\\SampleOutput.txt";
	These are the file names I used but should be changed to the files locations
	*/
	std::string natfile;
	std::string flowfile;
	std::string outputfile;

	natFiletoOutput(natfile, flowfile, outputfile);
	

}

void natFiletoOutput(std::string natfile, std::string flowfile, std::string outputfile) {
	std::map<std::string, std::string> m = getMapFromFile(natfile);
	fromFlowOuput(flowfile, outputfile, m);
}

void fromFlowOuput(std::string flowfile, std::string outputfile, std::map<std::string, std::string> m) {
	
	std::ifstream infileFlow(flowfile);
	std::ofstream outputFile(outputfile);
	std::string line;

	while (std::getline(infileFlow, line))
	{
		bool flag = false;
		if (line.length() > 2) {
			for (auto const& element : m) {//for each key

				std::string ele = cleanIpPort(element.first, line.length());
				flag = regexMatching(line, ele);
				if (flag) {
					outputFile << line << "->" << element.second << "\n";
					break;
				}

			}
			if (!flag) {
				outputFile << "No nat match for " << line << "\n";
			}

		}
	}
}


std::map<std::string, std::string> getMapFromFile(std::string filename) {
	std::ifstream infileNat(filename);
	std::string line;
	std::map<std::string, std::string> m;
	while (std::getline(infileNat, line))
	{
		if (line.length() > 2) {
			std::string key = line.substr(0, line.find(","));
			std::string value = line.substr(line.find(",") + 1);
			m[key] = value;

		}
	}
	return m;
}

std::string cleanIpPort(std::string element,int len) {
	size_t found = element.find("*");
	size_t found2 = element.find("*", found + 1);
	std::string ele;
	if (found > len) {
		return element;
	}
	else if (found2 > len) {
		return element.substr(0, found) + "." + element.substr(found);
	}
	else {
		return element.substr(0, found) + "." + element.substr(found, found2) + "." + element.substr(found2);
	}
}

bool regexMatching(std::string line, std::string ele) {
	std::regex regex(ele);
	std::smatch match;
	if (std::regex_match(line, match, regex)) {		
		return true;
	}
	return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
