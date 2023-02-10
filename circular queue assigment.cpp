#include <iostream>
using namespace std;

int n;
int front=-1;
int rare=-1;
//cout<<"enter the no. of elements that you want to add in your Queue : ";
//cin>>n;
int circularqueue[5];

void enqueue(int x){
//	cheching  queue is full or not 
	if((rare+1)%5==front){
		cout<<"Queue is full "<<endl;	
	}
	else if(front ==-1 && rare==-1){
		front = rare=0;
		circularqueue[rare]=x;
	}
	
	else{
		rare=(rare+1)%5;
		circularqueue[rare];
	}
}

void dequeue(int x){
	if(front ==-1 && rare==-1){
		cout<<"Queue is Empty : ";
	}
	else if(front ==rare){
		cout<<"the dequeue element is : "<<circularqueue[front]<<endl;
		front=rare=+1;
	}
	else{
		cout<<"the dequeue element is : "<<circularqueue[front]<<endl;
		front=(front+1)%5;
	}
}

void display(){
	int i=front;
	if(front ==-1 && rare==-1){
		cout<<"Queue is Empty : "<<endl;
	}
	else{
		cout<<"the Queue Is : "<<endl;
		while(i!=rare){
			cout<<circularqueue[i]<<" ";
			i=(i+1)%5;
			cout<<circularqueue[rare];
		}
		
	}
}
int main(){
	int ch;

//		enqueue(12);
//		enqueue(17);
//		enqueue(78);
//		dequeue(12);
//		display();
//	
//	do{
//		cout<<"\n01.Enqueue the elements : "<<"\n02.Dequeue the elements : "<<"\n03.Display"<<"\n00.EXIT : "<<endl;
//		cout<<"\nEnter your choice : ";
//		cin>>ch;
//		switch(ch){
//			case 01:
//				int n;
//				int arr[5];
//				cout<<"enter the element that u want to add in Queue : ";
//			
//				cin>>n;
//				enqueue(n);
////				display();
//				break;
//				
//			case 02:
//				int x;
//				cout<<"enter the element that u want to delect from Queue : ";
//				cin>>n;
//				dequeue(x);
////				display();
//				break;
//				
//			case 03:
//				display();
//					
//		}
//	}while(ch!=0);
	
}
