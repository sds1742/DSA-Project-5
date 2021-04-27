#include "lcsoutput.h"

lcsoutput::lcsoutput()
{
	ifstream is;
	is.open("twoStrings.txt");
	is>>s1;
	is>>s2;
	sslength = 0;
	matrixcols = s1.length()+1;
	matrixrows = s2.length()+1;
	c = new int* [matrixrows];
	for (int k = 0; k <matrixrows ; k++) {
		c[k] = new int[matrixcols];
	}
	lcslength(s2, s1);
	printLCS(s2.length(),s1.length());
	is.close();
	cout << endl;
	cout << sslength << endl;
}

void lcsoutput::lcslength(string X, string Y)
{
	int m = matrixrows;
	int n = matrixcols;
	//cout << m << " " << n << endl;
	for (int i = 1; i < m; i++) {
		c[i][0] = 0;
	}
	for (int j = 0; j < n; j++) {
		c[0][j] = 0;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (X[i-1] == Y[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				if (c[i - 1][j] >= c[i][j - 1]) {
					c[i][j] = c[i - 1][j];
				}
				else {
					c[i][j] = c[i][j - 1];
				}
			}
		}
	}
}

void lcsoutput::printLCS(int a, int b)
{
	if ((a == 0) || (b == 0)) {
		
		return;
	}
	else if (s2[a-1] == s1[b-1]) {
		printLCS(a - 1, b - 1);
		cout << s2[a-1];
		sslength++;
	}
	else if (c[a - 1][b] >= c[a][b - 1]) {
		printLCS(a - 1, b);
	}
	else {
		printLCS(a, b - 1);
	}
}
	