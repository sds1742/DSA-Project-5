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
	//initialize variables
	table = new int* [2];
	for (int k = 0; k < 3; k++) {
		table[k] = new int[matrixcols];
	}
	//allocate c such that it is a 2*M matrix
	lcscalc(s2.substr(0,2),s1,1);
	//fill the c array by passing the first 2 letters of string 2. 
	for (int i = 1; i < matrixrows; i++) {
		lcscalc(s2.substr(i, 2), s1, 0);
		//runs through the rest of string 2. 
	}
	lcssize = static_cast<double>(table[1][s1.length()]);
	//the last iteration of the "c" arrray is identical to the last 2 rows of a n*m-method c array
	//and like in an n*m-method c array, the value in the last row and collunm is equal to the substring length
	//this is used in leui of recovering the substring length from the individual 2*m arrays
	findsim();
	//calculate similarity and simularity character for use in lcstable
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
	//the purpouse of the bool is to switch between the behavior needed at the first call and all other calls
	//the first call, much like the first 2 rows of a n*m array, needs the first row to be all 0s
	//all other calls must instead move the existing values in the second row to the first
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
	//calculations are otherwise identical to lcsoutput/a n*m array
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
	//find which string is longer and shorter, allowing the logic to work
	double pd1 = (shorter) / longer;
	double pd2 = (lcssize)/shorter;
	if ((pd1>=0.9) && (pd2>=0.9)) {
		simchar = 'H';
	}
	else if ((pd1>=0.8) && (pd2>=0.8)) {
		simchar = 'M';
	}
	else if ((pd1>=0.6) && (pd2>=0.5)) {
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

