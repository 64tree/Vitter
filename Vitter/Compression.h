#ifndef COMPRESSION_H
#define COMPRESSION_H

using namespace std;

class Compression
{

public:
	// constructors
	Compression() {}
	void create_node();

	typedef struct node {
		unsigned char symbol; // symbol
		int weight,           // weight
			number;           // number
		node *parent,         // parent
			*left,           // left child
			*right;          // right child
	} node;



protected:

	// attributes

	
	
};

#endif




