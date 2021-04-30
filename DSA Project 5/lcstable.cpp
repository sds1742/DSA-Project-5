#include "lcstable.h"
lcstable::lcstable()
{
	
	ifstream stream;
	stream.open("multiStrings.txt");
	stream >> numstrings;
	simtable = new char* [numstrings];
	for (int i = 0; i < numstrings; i++) {
		simtable[i] = new char[numstrings];
	}
	for (int i = 0; i < numstrings; i++) {
		for (int j = 0; j < numstrings; j++) {
			simtable[i][j]='-';
		}
	}
	stream.close();
	computeLengths();
	
	directAccess();
	cout<<endl;
	cout<<"Part 2 output"<<endl;
	printtable();
}

void lcstable::printtable()
{
	for (int i = 0; i <= numstrings; i++) {
		for (int j = 0; j <= numstrings; j++) {
			if((i>0)&&(j>0)){
			cout << simtable[i-1][j-1]<<" ";
			}
			else{
			if((i==0)&&(j>0)){
			cout<<j<<" ";
			//prints the collunm labels
			}
			else if((j==0)&&(i>0)){
			cout<<i<<" ";
			//prints the row labels
			}
			else{
			cout<<"- ";
			}
			}
		}
		cout << endl;
	}
}

void lcstable::computeLengths()
{
	ifstream in;
	char line[LINLEN];
	//creates a 120 char long string, which is longer than any individual string in the file
	in.open("multiStrings.txt");
	positions[0] = 0;
	//the first line is ignored
	while (in.getline(line, LINLEN)) {
		positions[totStrings] = strlen(line) + 1;
		//the totStrings-th item in positions is given the value of strlen(line)+1
		totStrings++;
		//increment totstrings to move down the line
		line[strlen(line)] = '\0';
		//item at the end of line is given a value of newline
	}
	in.close();
}

void lcstable::directAccess()
{
	int i, j, currentPos = positions[0];
	char line[LINLEN];
	ifstream in;
	in.open("multiStrings.txt");
	in.seekg(currentPos);
	//sets pointer to beggining 
	for (i = 1; i < totStrings - 1; i++) {
		in.getline(line, LINLEN);
		//inputs line "string"
		line[strlen(line)] = '\0';
		//and gives it a newline char
		string s=line;
		//saves current line for manipulation later
		for (j = i + 1; j < totStrings; j++) {
			in.getline(line, LINLEN);
			line[strlen(line)] = '\0';
			//finds line which will be compared
			lcsunit u=lcsunit(s,line);
			//calls lcs constructor, which does all the work
			simtable[i-1][j-1]=u.getchar();
		}
		currentPos += positions[i];
		in.seekg(currentPos);
		//iterates currentpos and moves pointer to it
	}
}


