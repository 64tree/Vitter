// Vitter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Compression.h"

using namespace std;

int main()
{
	vector<char> characterlist;
	string filename;
	cout << "What's your file name? ";
	//getline(cin, filename);
	cout << "Hello " << filename << ".\n";
	filename = "Harry.txt";

	//open the file 
	ifstream fin(filename);

	char ch;
	//until the end of the file get the character and place in the vector 
	while (!fin.eof()) {
		fin.get(ch);
		cout << ch  <<endl;
		characterlist.push_back(ch);
	}
	fin.close();


	getchar();
	getchar();

    return 0;
}





