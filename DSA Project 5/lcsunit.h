#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class lcsunit
{
private:
	string s1;
	string s2;
	int** table;
	double lcssize;
	int matrixcols;
	int matrixrows;
	char simchar;
public:
	lcsunit();
	lcsunit(string a, string b);
	void lcscalc(string X, string Y,bool b);
	void findsim();
	char getchar();
};

