#ifndef TREE_H
#define TREE_H

#include "Node.h"

using namespace std;

class Tree
{

public:
	// constructors
	Tree();
	Node* add_node(char symbol);


protected:
	
	int MAX_NUMBER = 512;
	Node* NYT;
	Node* Root;


};

#endif

