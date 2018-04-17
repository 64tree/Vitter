#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->NYT = NYT;
	Node* Root = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->Root = Root;//THIS IS NOT GOING TO WORK AS POINTING TO THE SAME PLACE ALWAYS 

	NodeRef.push_back(NYT);
	
}

Node* Tree::update_tree(Node* current_node) 
{
	//current_node->getParent()->increaseWeight();
	//add up the new weights 
	while(Root != current_node)
	{
		current_node->getParent()->increaseWeight();

		current_node = current_node->getParent();


	}
	return NYT->getParent();
}	


bool Tree::is_char_in_tree(char charToFind) 
{
	bool charInTree;
	charInTree = false;
	
	for (int i = 0; i < (CharRef.size()); i++)
	{
		if (CharRef[i] == charToFind) 
		{
			charInTree = true;
		}	
	}
	return charInTree;
}

void Tree::increase_char(Node* charIncreaseNode)
{
	charIncreaseNode->increaseWeight();
	charIncreaseNode->getParent()->increaseWeight();

}

Node* Tree::find_char(char charToFind)
{
	for (int i = 0; i < NodeRef.size(); i++) 
	{
		if (charToFind == NodeRef[i]->getSymbol())
		{
			return NodeRef[i];
		}
	
	}
	
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

    
	CharRef.push_back(symbol);

	return NYT->getParent(); // return the nyt parent
}


int Tree::calculateCode(Node* charNode) 
{
	Node* currentNode;
	currentNode = charNode;
	int calculatedCode = 0;
	while (currentNode!= Root)
	{

		if ((currentNode) == currentNode->getParent()->getLeft())
		{
			calculatedCode += 0b0;
		}
		else
		{
			calculatedCode += 0b1;
		
		}
			
		currentNode = currentNode->getParent();
	}
	
	return calculatedCode;
} 

