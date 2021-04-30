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
	//ShowPositionsArray();
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
			}
			else if((j==0)&&(i>0)){
			cout<<i<<" ";
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
	in.open("multiStrings.txt");
	positions[0] = 0;
	while (in.getline(line, LINLEN)) {
		positions[totStrings] = strlen(line) + 1;
		//cout << "number of chars =" << positions[totStrings++] << endl;
		totStrings++;
		line[strlen(line)] = '\0';
		//cout << "string = " << line << endl;
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
	for (i = 1; i < totStrings - 1; i++) {
		in.getline(line, LINLEN);
		line[strlen(line)] = '\0';
		//cout << "this string [" << line << "]" << endl;
		string s=line;
		for (j = i + 1; j < totStrings; j++) {
			in.getline(line, LINLEN);
			line[strlen(line)] = '\0';
			//cout << " compared with[" << line << "]" << endl;
			lcsunit u=lcsunit(s,line);
			simtable[i-1][j-1]=u.getchar();
			
		}
		currentPos += positions[i];
		in.seekg(currentPos);
	}
}

void lcstable::ShowPositionsArray()
{
	int i;
	for (i = 0; i < totStrings; i++) {
		cout << " line " << i << " position " << positions[i] << endl;
	}
}
