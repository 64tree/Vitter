#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->NYT = NYT;
	Node* Root = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->Root = Root;//THIS IS NOT GOING TO WORK AS POINTING TO THE SAME PLACE ALWAYS 

	//NodeReference.push_back(NYT);
	
}

Node* Tree::update_tree(Node* current_node) 
{

	//add up the new weights 
	while(Root != current_node)
	{
		current_node->getLeft();
		current_node->getParent();
		current_node->getRight();
	
	}
	return NYT->getParent();
}	


Node* Tree::find_char(char charToFind)
{
	for (int i = 0; i < NodeRef.max_size(); i++) 
	{
		if (charToFind == NodeRef[i]->getSymbol())
		{
			return NodeRef[i];
		}
	
	}

	/*for (int x = 512; x <= (512 -VecNodeReference.max_size()); x--)
	{
		if (charToFind == (NodeReference[x].symbol))
		{
			return NodeReference[x].nodeRef;
		}
	}*/

	
}

Node* Tree::add_node(char symbol )
{
	
	int newOrder = (NYT->getOrder()); //get the order of nyt so i can find new orders 

	Node* NewNYT = new Node(NULL, 0, (newOrder - 2), NYT, NULL, NULL); // setup new nyt with current nyt as parent 
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

	NodeRef.push_back(NewChar);
	NodeRef.push_back(NewNYT);

	/*NodeReference[newOrder-1].symbol = symbol;
	NodeReference[newOrder-1].nodeRef = NewChar;
	NodeReference[newOrder-2].symbol = symbol;
	NodeReference[newOrder-2].nodeRef = NewNYT;
	VecNodeReference.push_back(NodeReference[newOrder - 1]);
	*/VecNodeReference.push_back(NodeReference[newOrder - 2]);
	CharRef.push_back(symbol);

	return NYT->getParent(); // return the nyt parent
}