#pragma once
#include <string>
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
	void lcscalc(string X, string Y);
	void findlength(int a, int b);
	double getlength();
	string gets1();
	string gets2();
	void findsim();
	char getchar();
};

