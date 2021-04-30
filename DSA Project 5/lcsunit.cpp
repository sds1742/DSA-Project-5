#include "lcsunit.h"

lcsunit::lcsunit()
{
	s1 = "string1";
	s2 = "string2";
	lcssize = 0;
	simchar = 'Z';
}

lcsunit::lcsunit(string a, string b)
{
	s1 = a;
	s2 = b;
	lcssize = 0;
	simchar = 'X';
	matrixcols = s1.length() + 1;
	matrixrows = s2.length();
	table = new int* [2];
	for (int k = 0; k < 3; k++) {
		table[k] = new int[matrixcols];
	}
	lcscalc(s2.substr(0,2),s1,1);
	for (int i = 1; i < matrixrows; i++) {
		lcscalc(s2.substr(i, 2), s1, 0);
	}
	lcssize = static_cast<double>(table[1][s1.length()]);
	findsim();
}

void lcsunit::lcscalc(string X, string Y,bool b)
{
	int m = X.length();
	int n = Y.length();
	if (b == 1) {
		for (int i = 1; i < m+1; i++) {
			table[i][0] = 0;
		}
		for (int j = 0; j < n+1; j++) {
			table[0][j] = 0;
		}
	}
	else {
		for (int i = 0; i < n + 1; i++) {
			table[0][i] = table[1][i];
		}
	}
	for (int i = 1; i < m+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (X[i-1] == Y[j-1]) {
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

