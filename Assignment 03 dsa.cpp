#include<bits/stdc++.h>
using namespace std;

class Stack{
	
	queue<int> q1 ,q2;
	
	int curr_size;
	
	public:
		Stack(){
			curr_size=0;
		}
		
		void push(int a){
			curr_size++;
			
			q1.push(a);
			
			while(q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			
			queue<int> q = q1;
			q1 = q2;
			q2 = q;
		}
		
		void pop(){
			
			if(q1.empty()){
				return;
			}
			else{
				q1.pop();
				curr_size--;
			}
		}
		
		int top(){
			if(q1.empty()){
				return 0;
			}
			else{
				return q1.front();
			}
			
		}
		
		int size(){
			return curr_size;
		}
};

int main(){
	Stack s;
	int ch ,a ,b;
	
	do{
		cout<<"\nWhich Opration do you want to do : "<<endl;
		cout<<"\n01. Insertion Element :"<<"\n02. Delect Element :"<<"\n03. Top Element :"<<"\n04. Current size :"<<"\n00. Exit ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			
			case 1:
				cout<<"\nEnter the element : ";cin>>a;
				s.push(a);
				break;
				
			case 2:
				
				s.pop();
				cout<<"\n Successfully !!  Delected last inserted element : "	;
				break;
				
			case 3:
				cout<<"\nTop element : ";
				cout<<s.top();
				break;
				
			case 4:
				cout<<"\nThe current size of queue : "	;
				cout<<s.size();
				break;
					
				
			default:
				cout<<"...INVALID CHOICE..."	;
						
		}
	}while(ch!=0);
}

