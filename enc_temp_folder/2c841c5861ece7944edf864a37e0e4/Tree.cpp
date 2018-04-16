#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->NYT = NYT;
	Node* Root = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->Root = Root;//THIS IS NOT GOING TO WORK AS POINTING TO THE SAME PLACE ALWAYS 
}




Node* Tree::add_node(char symbol )
{
	/*
	int newOrder = (NYT->getOrder()); //get the order of nyt so i can find new orders 
	Node* newParent = NYT;	// get parent locatation for new node 
	Node* NewNode = new Node(symbol, 1, (newOrder-2), newParent, NULL, NULL);
	Node* NewNYTNode = new Node(NULL, 0, (newOrder - 1), newParent, NULL, NULL);
	//NYT->setParent(Root);/// this is not the case after the first tree 
	NYT->setLeft(NewNYTNode);
	NYT->setRight(NewNode);
	NYT->setWeight(0);
	//NYT->setOrder(newOrder - 1);
	*/

	
	int newOrder = (NYT->getOrder()); //get the order of nyt so i can find new orders 
	//Node* newParent = NYT;	// get parent locatation for new node 
	//NYT->setOrder(newOrder - 2);
	//Node* NewNode = new Node(symbol, 1, (newOrder - 1), newParent, NULL, NULL);
	//Node* NewWeight = new Node(NULL, 1, (newOrder), (NYT->getParent()), NYT, NewNode);
	

	Node* NewNYT = new Node(symbol, 0, (newOrder - 2), NYT, NULL, NULL); // setup new nyt with current nyt as parent 
	Node* NewChar = new Node(symbol, 1, (newOrder - 1), NYT, NULL, NULL); // setup new character with current nyt as parent
	
	NYT->setLeft(NewNYT);  //set left node
	NYT->setRight(NewChar); //set right node
	NYT->setWeight(1);

	this->NYT = NYT->getLeft();// set the nyt as the current NYT left node

	//check to see if this is will be the root node 
	if (0 == (Root->getWeight()))
	{
		Root = NYT->getParent();
	}

	return NYT->getParent(); // return the nyt parent
}