#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	Root = NYT;
	this->NYT = NYT;
	int newOrder = (NYT->getOrder());

}




void Tree::add_node(char symbol)
{
	int newOrder = ((NYT->getOrder())-2);
	Node* NewNode = new Node(symbol, 1, newOrder,NULL, NULL, NULL);
	

}