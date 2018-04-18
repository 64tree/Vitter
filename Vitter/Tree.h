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
	void update_tree(Node* current_node);
	void swap_nodes(Node* node1, Node* node2);
	Node* find_char(char charToFind);
	bool is_char_in_tree(char charToFind);
	void increase_char(Node* charIncreaseNode);
	string calculateCode(Node* charNode);
	vector<char> getCharRef(void);

protected:
	
	int MAX_NUMBER = 512;
	Node* NYT;
	Node* Root;
	
	vector<Node*>NodeRef;
	vector<char>CharRef;
};

#endif

