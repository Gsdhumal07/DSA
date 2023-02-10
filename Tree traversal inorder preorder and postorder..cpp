#include <iostream>
using namespace std;

struct Node{
	Node *left , *right;
	int data;
	Node(int data){
		this->data=data;
		left = right = NULL;
	}
};

void inorder(struct Node* node){
	if(node==NULL){
		return ;
	}
	
	inorder(node->left);
	
	cout<<node->data<<" ";
	
	inorder(node->right);
}

void preorder(struct Node* node){
	if(node==NULL){
		return ;
	}
	
	cout<<node->data<<" ";
	
	preorder(node->left);
	
	preorder(node->right);
}

void postorder(struct Node* node ){
	if(node==NULL){
		return ;
	}
	
	postorder(node->left);
	
	postorder(node->right);
	
	cout<<node->data<<" ";
}

int main(){
	struct Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	
	cout<<"The inorder traversal of the Tree : ";
	inorder(root);
	cout<<endl<<"\nThe preorder traversal of the tree : ";
	preorder(root);
	cout<<endl<<"\nThe postfix traversal of the tree : ";
	postorder(root);
}






