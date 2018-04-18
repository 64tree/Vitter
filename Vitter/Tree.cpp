#include "stdafx.h"
#include "Tree.h"


Tree::Tree(){

	Node* NYT = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->NYT = NYT;
	Node* Root = new Node(NULL, 0, MAX_NUMBER, NULL, NULL, NULL);
	this->Root = Root;

	NodeRef.push_back(NYT);
	
}


void Tree::swap_nodes(Node* node1, Node* node2)
{
	Node temp1 ;
	//create temporary node with node1 data in
	temp1 = *node1;
	//copy node2 data into node1 
	node1->setWeight(node2->getWeight());
	node1->setSymbol(node2->getSymbol());
	node1->setRight(node2->getRight());
	node1->setLeft(node2->getLeft());
	//if the children nodes are not null need to change their parents to node1
	if (node1->getLeft() != NULL) 
	{
		node1->getLeft()->setParent(node1);
		node1->getRight()->setParent(node1);
			
	}
	//copy node1(temp1) data into node2
	node2->setWeight(temp1.getWeight());
	node2->setSymbol(temp1.getSymbol());
	node2->setRight(temp1.getRight());
	node2->setLeft(temp1.getLeft());
	//if the children nodes are not null need to change their parents to node2
	if (node2->getLeft() != NULL)
	{
		node2->getLeft()->setParent(node2);
		node2->getRight()->setParent(node2);
	}

}

void Tree::update_tree(Node* current_node) 
{
	// perform check until you are the root 
	while(Root != current_node)
	{
		// for items of a greater order 		
		for (int i = 0; i < (512 - (current_node->getOrder()) ); i++)
		{
			// if there is a lower weight in a higher order and it is not its parent the nodes need to be swapped
			if ((current_node->getWeight()) >(NodeRef[i]->getWeight())&& (current_node->getParent() != NodeRef[i]))
			{
				//swap nodes
				swap_nodes(current_node, NodeRef[i]);
				// chance current node as nodes now swapped
				current_node = NodeRef[i];
			}
		}
		// increase the parents weight 
		current_node->getParent()->increaseWeight();
		// change current node to the parent 
		current_node = current_node->getParent();
	}

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
}

Node* Tree::find_char(char charToFind)
{
	/*for every node in tree find the matching character node */
	for (int i = 0; i < NodeRef.size(); i++) 
	{
		if (charToFind == NodeRef[i]->getSymbol())
		{
			/*return pointer of node of matching character*/
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


string Tree::calculateCode(Node* charNode) 
{
	Node* currentNode;
	currentNode = charNode;
	string calculatedCode = "";
	//transvere through tree until you reach the root 
	while (currentNode!= Root)
	{
		if ((currentNode) == currentNode->getParent()->getLeft())
		{
			//insert 0 to the start of the string as left branch 
			calculatedCode.insert(0,"0");
		}
		else
		{
			//insert 1 to the start of the string as right branch 
			calculatedCode.insert(0, "1");

		}
		//move to the next node up (its parent)
		currentNode = currentNode->getParent();
	}
	
	//return the huffman code for the character 
	return calculatedCode;
} 


vector<char> Tree::getCharRef(void) 
{
	return CharRef;
}



