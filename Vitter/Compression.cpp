#include "stdafx.h"
#include "Compression.h"
#include "Tree.h"


Compression::Compression() {

	

	

};


Compression::Compression(vector<char> characterlist) 
{
	Tree tree;
	Node* NewWeight;

	char characterToEncode;
	for (int i = 0; i < 4; i++) 
	{
		characterToEncode = characterlist[i];

		if (true == tree.is_char_in_tree(characterToEncode))
		{
			Node* charIncreaseNode;
			charIncreaseNode = tree.find_char(characterToEncode);

			tree.increase_char(charIncreaseNode);
			tree.update_tree(charIncreaseNode);
		}
		else
		{
			NewWeight = tree.add_node(characterToEncode);
			tree.update_tree(NewWeight->getRight());
		}

	}
	int value;

	value = tree.calculateCode(tree.find_char('M'));

	int x = 9;
	//NewWeight = tree.add_node('x');
	//NewWeight = tree.add_node('g');




	

}