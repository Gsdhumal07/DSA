#include<iostream>
using namespace std;

class tbt{
	int data;
	tbt *left;
	tbt *right;
	bool lthread;
	bool rthread;
	
	public :
		tbt* create(int key);
		tbt* insert(tbt * ,tbt *);
		void inorder(tbt * , tbt *);
		tbt* preorder(tbt * , tbt *);
		tbt* leftmost(tbt *);
};


tbt *tbt::create(int key){
	
	tbt *newnode = new tbt;
	newnode->data=key;
	newnode->left=newnode;
	newnode->right=newnode;
	newnode->lthread=true;
	newnode->rthread=true;
	return newnode;
	
}


tbt * tbt::insert(tbt *root ,tbt *head){
	int key;
	cout<<"\nEnter the value : ";
	cin>>key;
	tbt *cur;
	tbt *newnode = create(key);
	if(root=NULL){
		head->left=newnode;
		root=newnode;
		root->lthread=root->rthread=head;
		root->lthread=false;
		return root;
	}
	else{
		cur=root;
		while(1){
			if(cur->data==key){
				cout<<"\nElement is already present : ";
				return root;
				break;
			}
			
			if(key<cur->data){
				if(cur->lthread){
					break;
				}
				else{
					cur=cur->left;
				}
			}
			else{
				if(cur->rthread){
					break;
				}
				else{
					cur=cur->right;
				}
			}
		}
		if(key<cur->data){
			newnode->left=cur->left;
			cur->left=newnode;
			newnode->right=cur;
			cur->lthread=false;
		}
		else{
			newnode->left=cur;
			newnode->right-cur->right;
			cur->right=newnode;
			cur->rthread=false;
			
			
		}
	}
	return root;
	
}

tbt * tbt::leftmost(tbt *temp){
	if(temp==NULL){
		return NULL;
	}
	else{
		while(temp!=NULL){
			if(temp->lthread){
				break;
			}
			temp=temp->left;
		}
		return temp;
	}
}

void tbt::inorder(tbt *root ,tbt *head){
	
	tbt *cur;
	cur=leftmost(root);
	while(cur != head){
		cout<<"\n";
		cout<<cur->data<<" ";
		if(cur->rthread){
			
			cur=cur->right;
		}
		
		else{
			
			cur=leftmost(cur->right);
			
		}
		
	}
}

tbt *tbt::preorder(tbt *root ,tbt *head){
	tbt *cur=root;
	while(1){
		cout<<cur->data<<" ";
		if(cur->lthread==false){
			cur=cur->left;
		}
		else if(cur->rthread==false){
			cur=cur->right;
		}
		else{
			while(cur->right!=head && cur->rthread==true){
				cur=cur->right;
			}
			if(cur->right!=head){
				cur=cur->right;
			}
			else{
				break;
			}
		}
	}
}




int main(){
	
	tbt *root=NULL;
	tbt t;
	tbt *head = t.create(999);
	root=t.insert(root ,head);
	root=t.insert(root ,head);
	root=t.insert(root ,head);
	t.inorder(root ,head);
	t.preorder(root , head);
}











