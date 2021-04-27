#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class lcsoutput
{
private:
	string s1;
	string s2;
	int** c;
	int sslength;
	int matrixcols;
	int matrixrows;
public:
	lcsoutput();
	void lcslength(string X, string Y);
	void printLCS(int a, int b);
};

