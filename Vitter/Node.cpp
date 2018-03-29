#include "stdafx.h"
#include "Node.h"
#include <string>
//using std::string;

//creates the node object
Node::Node(char symbol, int weight, int order, Node *parent, Node *left, Node *right)
{
	 this->symbol= symbol;
	 this->weight = weight;
	 this->order = order;
	 this->parent = parent;
	 this->left = left;
	 this->right = right;
	
}
char Node::getSymbol(void)
{
	return symbol;
}

int Node::getWeight(void)
{
	return weight;
}

int Node::getOrder(void)
{
	return order;
}

Node* Node::getParent(void) 
{
	return parent;
}

Node* Node::getLeft(void)
{
	return left;
}

Node* Node::getRight(void)
{
	return right;
}

void Node::setParent(Node* parentLocation) 
{
	parentLocation = parent;
}

void Node::setLeft(Node* leftLocation)
{
	leftLocation = left;
}

void Node::setRight(Node* rightLocaction)
{
	rightLocaction = right;
}