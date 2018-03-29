// Vitter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Compression.h"

int main()
{
	string filename;
	cout << "What's your file name? ";
	getline(cin, filename);
	cout << "Hello " << filename << ".\n";
	
	//first i need to read in a file 
	int Character;
	int *p_loadprogram;
	vector<string> list;

	int loadprogram[100] = { 0 };
	p_loadprogram = loadprogram;

	ifstream CompressFile; // To read the file named CompressFile.
	CompressFile.open(filename.c_str(), ifstream::in); // To open the file.
	int size = 0; // To clean the array when it opens the file again. 

	if (CompressFile) { // This displays the contents of the file, if it was able to open.    

		CompressFile >> Character;
		list.push_back(Character);
		while (!CompressFile.eof()) { // It keeps reading the file until it ends.
			loadprogram[size] = Character;
			CompressFile >> Character;
			size++;
		}
		cout << "\nThe Character in the file " << filename << " have been read: " << endl;

	}
	else if (CompressFile.fail()) { // This indicates that the file was not able to open.
		cout << "\nThe file does not exist. " << endl;
	}

	CompressFile.close(); // To close the file.


    return 0;
}





