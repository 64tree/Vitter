#ifndef COMPRESSION_H
#define COMPRESSION_H
#include "Node.h"
#include "Tree.h"
#include <vector>
#include<bitset>
#include <iostream>
#include <fstream>

using namespace std;

class Compression
{

public:
	// constructors
	Compression();
	Compression(vector<char> characterlist);
	void output_to_file(string charEncoded);
	void Compress_to_file(string charEncoded);
	vector<char>CharRef;


	ofstream encodeFile;

protected:
	Node *NYT;
	Node *Root;
	vector<int> weightList;
	vector<int> OrderList;
	
	// attributes

	
	
};

#endif




