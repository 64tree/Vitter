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

void Node::setSymbol( char symbol)
{
	this->symbol = symbol;
}
void Node::setWeight(int weight)
{
	this->weight = weight;
}
void Node::setOrder(int order)
{
	this->order = order;
}

void Node::setParent(Node* parentLocation) 
{
	parent =parentLocation ;
}

void Node::setLeft(Node* leftLocation)
{
	left = leftLocation ;
}

void Node::setRight(Node* rightLocaction)
{
	right = rightLocaction ;
}