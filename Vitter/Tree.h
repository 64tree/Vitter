#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>
using namespace std;

class Tree
{

public:
	// constructors
	Tree();
	Node* add_node(char symbol);
	Node* update_tree(Node* current_node);
	Node* find_char(char charToFind);

	struct nodeData {
		Node* nodeRef;
		char symbol;
	}NodeReference[512];

protected:
	
	int MAX_NUMBER = 512;
	Node* NYT;
	Node* Root;

	vector<nodeData> VecNodeReference;
	vector<Node*>NodeRef;
	vector<char>CharRef;
};

#endif

