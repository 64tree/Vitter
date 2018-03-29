#ifndef NODE_H
#define NODE_H
#include <string>


using namespace std;





class Node
{

public:
	// constructors
	Node() {}
	Node(unsigned char symbol, int weight, int number, Node *parent, Node *left, Node *right);


protected:

	// attributes
	unsigned char symbol; // symbol
	int weight,           // weight
		number;           // number
	Node *parent,         // parent
		*left,           // left child
		*right;          // right child


};

#endif

