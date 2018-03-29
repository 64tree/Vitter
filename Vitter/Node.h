#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{

public:
	// constructors
	Node() {}
	Node(char symbol, int weight, int order, Node *parent, Node *left, Node *right);
	char getSymbol(void);
	int getWeight(void);
	int getOrder(void);
	Node* getParent(void);
	Node* getLeft(void);
	Node* getRight(void);
	void setSymbol(char symbol);
	void setWeight(int weight);
	void setOrder(int order);
	void setParent(Node* parentLocation);
	void setLeft(Node* rightLocation);
	void setRight(Node* leftLocation);

protected:

	// attributes
	char symbol; // symbol
	int weight;          // weight
	int	order;           // number
	Node *parent,         // parent
		*left,           // left child
		*right;          // right child


};

#endif

