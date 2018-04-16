#ifndef COMPRESSION_H
#define COMPRESSION_H
#include "Node.h"
#include "Tree.h"
#include <vector>

using namespace std;

class Compression
{

public:
	// constructors
	Compression();
	//void add_node(char symbol);



protected:
	Node *NYT;
	Node *Root;
	vector<int> weightList;
	vector<int> OrderList;
	
	// attributes

	
	
};

#endif




