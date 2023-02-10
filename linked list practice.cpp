
#include<iostream>
using namespace std;

class Node{
	Node *link;
	Node *left;
	Node *data;
	
	public :
	void insertdata( int);
};

void Node::insertdata(int x){
	
	Node *newnode = new Node;
	newnode->data = x;
	newnode->link=NULL;
	return newnode;
	

}
