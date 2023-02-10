#include<iostream>
using namespace std;

class tbt{
	int data;
	tbt *left;
	tbt *right;
	bool rthread ,lthread;
	public:
		tbt *insert(tbt *,tbt *);
		tbt *create(int);
		tbt *leftmostnode(tbt *,tbt *);
		void inorder(tbt *,tbt *);
		tbt* preorder(tbt *, tbt*);
};

tbt * tbt :: create(int key){
	tbt * newnode =new tbt;
	newnode->data=key;
	newnode->left=newnode;
	newnode->right=newnode;
	newnode->lthread=true;
	newnode->rthread=true;
	return newnode;
	
}

tbt *tbt::insert(tbt * root, tbt *head){
	int key;
	tbt *curr;
	cout<<"Enter the Element to Insert : ";
	cin>>key;
	tbt * newnode = create(key);
	
	
	if(root==NULL){
		head->left=newnode;
		root=newnode;
		root->left=root->right=head;
		head->lthread=false;
		return root;
	}
	else{
		curr=root;
		while(1){
			if(curr->data==key){
				cout<<"Element already present !! \n";
				return root;
				break;
			}
			
			if(key<curr->data){
				if(curr->lthread){
					break;
				}
				else{
					curr=curr->left;
				}
			}
			else{
				if(curr->rthread){
					break;
				}
				curr=curr->right;
			}
		}
		if(key<curr->data){
			newnode->left=curr->left;
			curr->left=newnode;
			newnode->right=curr;
			curr->rthread=false;
			
		}
		else{
			newnode->left=curr;
			newnode->right=curr->right;
			curr->right=newnode;
			curr->rthread=false;
		}
	}
}












