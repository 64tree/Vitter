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
	string huffman_encode;

	// for each char in the tree
	for (int x = 0; x < (tree.getCharRef().size()); x++)
	{
		Node* characterNode = tree.find_char(tree.getCharRef()[x]);
		//find char in tree and calculate the code
		value = tree.calculateCode(characterNode);
		cout << "The character :"<<(characterNode->getSymbol())<<" The Weight:" <<(characterNode->getWeight())<<" The Huffman Code :" <<value << endl;
		

		
		/*convets asci character symbol to binary*/
		bitset<8> AsciBit = bitset<8>(characterNode->getSymbol());
		string BinString = AsciBit.to_string();
		/*add the huffman encode value to string */
		BinString.append(value);
		/*add the character and huffmand code to the string */
		huffman_encode.append(BinString);

	}
	/*human Readable binary file */ 
	/*JUST HUFFCODES*/
	output_to_file(huffman_encode);
	
	Compress_to_file(huffman_encode);
		int x = 9;


		//bitset<string.lenght> sybmol (string ("the Code "))
		encodeFile.close();
	}

void Compression::Compress_to_file(string huffcodes)
{
	string byte;
	ofstream encodeFile("encodeFile.bin", ios::binary);
	if (encodeFile.is_open())
	{
		for (int i = 0; i < huffcodes.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				
				byte.push_back(huffcodes[i + j]);

			}
			i = i + 6;
			
			string byte1 = byte;
			byte.clear();
			//bitset<8> EncodBit(byte1);
			///EncodBit.test();

			//cout << EncodBit << endl;
			
			//encodeFile << EncodBit << endl;
			//EncodBit.reset();
		}
		
	}
	encodeFile.close();
	
	

	//for (charEncoded.size();
}

void Compression::output_to_file(string charEncoded)
{
	ofstream encodeFile("encodeFile.txt");
	if (encodeFile.is_open())
	{
		encodeFile << charEncoded << endl;
	}
}
	
/*void Compression::output_to_file(string charEncoded ) 
{
	
	
}*/



	

