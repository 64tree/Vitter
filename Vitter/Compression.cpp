#include "stdafx.h"
#include "Compression.h"
#include "Tree.h"


Compression::Compression() {

	Tree tree;
	Node* NewWeight;


	NewWeight = tree.add_node('m');
	
	NewWeight = tree.add_node('s');
	NewWeight = tree.add_node('w');

	

	NewWeight = tree.find_char('m');

};


