#include "lcsoutput.h"

lcsoutput::lcsoutput()
{
	ifstream is;
	is.open("twoStrings.txt");
	is>>s1;
	is>>s2;
	sslength = 0;
	//input strings and initialize vars
	matrixcols = s1.length()+1;
	matrixrows = s2.length()+1;
	c = new int* [matrixrows];
	for (int k = 0; k <matrixrows ; k++) {
		c[k] = new int[matrixcols];
	}
	//initialize c
	lcslength(s2, s1);
	cout<<"Part 1 output"<<endl;
	printLCS(s2.length(),s1.length());
	is.close();
	cout << endl;
	cout<<"length(X) = "<<s1.length()<<endl;
	cout<<"length(Y) = "<<s2.length()<<endl;
	cout<<"LCS length =  "<< sslength << endl;
}

void lcsoutput::lcslength(string X, string Y)
{
	int m = matrixrows;
	int n = matrixcols;
	for (int i = 1; i < m; i++) {
		c[i][0] = 0;
	}
	for (int j = 0; j < n; j++) {
		c[0][j] = 0;
	}
	//initialize the row of 0s in the first row and collumn, used to allow the rest of the function to work
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (X[i-1] == Y[j-1]) {
				//if a match is found
				c[i][j] = c[i - 1][j - 1] + 1;
				//iterate the counter
			}
			else {
				if (c[i - 1][j] >= c[i][j - 1]) {
					c[i][j] = c[i - 1][j];
					//in a b array, this would be "left"

				}
				else {
					c[i][j] = c[i][j - 1];
					//and this would be up in a b array
				}
			}
		}
	}
}

void lcsoutput::printLCS(int a, int b)
{
	if ((a == 0) || (b == 0)) {
		//base case
		return;
	}
	else if (s2[a-1] == s1[b-1]) {
		printLCS(a - 1, b - 1);
		//diagonal item found, moves to item it points to, and increments counter/outputs
		cout << s2[a-1];
		sslength++;
	}
	else if (c[a - 1][b] >= c[a][b - 1]) {
		//left item found, points to the item to the left
		printLCS(a - 1, b);
	}
	else {
		printLCS(a, b - 1);
		//up item found, looks to item above it
	}
}
	
