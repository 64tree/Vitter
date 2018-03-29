#ifndef COMPRESSION_H
#define COMPRESSION_H

using namespace std;

class compression
{

public:
	// constructors
	compression() {}
	void create_node();


protected:

	// attributes

	typedef struct node {
		unsigned CompressFile symbol; // symbol
		int weight,           // weight
			number;           // number
		node *parent,         // parent
			*left,           // left child
			*right;          // right child
	} node;
	
};

#endif




