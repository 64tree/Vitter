#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>
#include <string>
using namespace std;

class Tree
{

public:
	// constructors
	Tree();
	Node* add_node(char symbol);
	Node* update_tree(Node* current_node);
	Node* find_char(char charToFind);
	bool is_char_in_tree(char charToFind);
	void increase_char(Node* charIncreaseNode);
	int calculateCode(Node* charNode);

protected:
	
	int MAX_NUMBER = 512;
	Node* NYT;
	Node* Root;

	vector<Node*>NodeRef;
	vector<char>CharRef;
};

#endif

