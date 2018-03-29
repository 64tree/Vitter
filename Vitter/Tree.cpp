#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->NYT = NYT;
	Node* Root = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->Root = Root;//THIS IS NOT GOING TO WORK AS POINTING TO THE SAME PLACE ALWAYS 
}




void Tree::add_node(char symbol)
{
	int newOrder = (NYT->getOrder()); //get the order of nyt so i can find new orders 
	Node* newParent = NYT;	// get parent locatation for new node 
	Node* NewNode = new Node(symbol, 1, (newOrder-2), newParent, NULL, NULL);
	NYT->setParent();
	NYT->setOrder(newOrder - 1);

	

}