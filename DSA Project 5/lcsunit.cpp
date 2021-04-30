#include "lcsunit.h"

lcsunit::lcsunit()
{
	s1 = "string1";
	s2 = "string2";
}

lcsunit::lcsunit(string a, string b)
{
	s1 = a;
	s2 = b;
	lcssize = 0;
	simchar = 'X';
	matrixcols = s1.length() + 1;
	matrixrows = s2.length() + 1;
	table = new int* [matrixrows];
	for (int k = 0; k < matrixrows; k++) {
		table[k] = new int[matrixcols];
	}
	lcscalc(s2, s1);
	findlength(s2.length(), s1.length());
	findsim();
}

void lcsunit::lcscalc(string X, string Y)
{
	int m = X.length();
	int n = Y.length();
	for (int i = 1; i < m; i++) {
		table[i][0] = 0;
	}
	for (int j = 0; j < n; j++) {
		table[0][j] = 0;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (X[i] == Y[j]) {
				table[i][j] = (table[i - 1][j - 1]) + 1;
			}
			else {
				if (table[i - 1][j] >= table[i][j - 1]) {
					table[i][j] = table[i - 1][j];
				}
				else {
					table[i][j] = table[i][j - 1];
				}
			}
		}
	}
}

void lcsunit::findlength(int a, int b)
{
	if ((a == 0) || (b == 0)) {
		return;
	}
	else if (s2[a] == s1[b]) {
		findlength(a - 1, b - 1);
		lcssize=lcssize+1;
	}
	else if (table[a - 1][b] >= table[a][b - 1]) {
		findlength(a - 1, b);
	}
	else {
		findlength(a, b - 1);
	}
}

double lcsunit::getlength()
{
	return lcssize;
}

string lcsunit::gets1()
{
	return s1;
}

string lcsunit::gets2()
{
	return s2;
}

void lcsunit::findsim()
{
	double longer;
	double shorter;
	if (s1.length() > s2.length()) {
		longer = s1.length();
		shorter = s2.length();
	}
	else {
		longer = s2.length();
		shorter = s1.length();
	}
	double pd1 = (longer - shorter) / longer;
	double pd2 = (lcssize)/shorter;
	if ((pd1<=0.1) && (pd2>=0.9)) {
		simchar = 'H';
	}
	else if ((pd1<=0.2) && ((shorter * 0.8) <= lcssize)) {
		simchar = 'M';
	}
	else if ((pd1<=0.4) && ((shorter * 0.5) <= lcssize)) {
		simchar = 'L';
	}
	else {
			simchar = 'D';
	}
	return;
}

char lcsunit::getchar()
{
	return simchar;
}

