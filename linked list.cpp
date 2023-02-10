#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node * next;
};
void linkedlisttraverser(struct Node *ptr){
	while(ptr!=NULL){
		cout<<" "<<ptr->data;
//		cout<<endl;
		ptr=ptr->next;
		
	}
	
}





int main(){
	struct Node * head ;
	struct Node * second ;
	
	struct Node * third ;
//	allocate memory for the nodes in the linked list in Heap
	head = (struct Node *) malloc(sizeof(struct Node));
	second = (struct Node *) malloc(sizeof(struct Node));
	third = (struct Node *) malloc(sizeof(struct Node));
	
	//	link first and second nodes
	head->data = 7;
	head->next = second;
	
	//	link second and third nodes
	second->data = 15;
	second->next = third;
	
	//	terminate the list at the third node
	third->data = 66;
	third->next = NULL;
	
	
	linkedlisttraverser(head);
	
	return 0;
}
