#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include "lcsunit.h"
using namespace std;
class lcstable
{
private:
	string* words;
	char** simtable;
	int numstrings;
	const int POSLEN = 20;
	const int LINLEN = 120;
	int* positions=new int[POSLEN];
	int totStrings=0;
public:
	lcstable();
	void printtable();
	void computeLengths();
	void directAccess();
	void ShowPositionsArray();
	//todo: turn the words call into random access file system
};

