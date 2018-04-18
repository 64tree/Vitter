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
	for (int i = 0; i < 20; i++) 
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
	
	
	string value;
	vector<char> ref;
	ref = tree.getCharRef();

	// for each char in the tree
	for (int x = 0; x < (tree.getCharRef().size()); x++)
	{
		Node* characterNode = tree.find_char(tree.getCharRef()[x]);
		//find char in tree and calculate the code
		value = tree.calculateCode(characterNode);
		cout << "The character :"<<(characterNode->getSymbol())<<" The Weight:" <<(characterNode->getWeight())<<" The Huffman Code :" <<value << endl;
		output_to_file(value, (characterNode->getSymbol()));
	}


		int x = 9;


		//bitset<string.lenght> sybmol (string ("the Code "))
		encodeFile.close();
	}
	
	
void Compression::output_to_file(string charEncoded, char Encode ) 
{
	int charValue;
	charValue = Encode;
	//ofstream encodeFile("encodeFile.txt");
	ofstream encodeFile("encodeFile.bin", ios::binary);
	if (encodeFile.is_open()) 
	{
		encodeFile << charEncoded << endl;
	}
	

	
}



	

