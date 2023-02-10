#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* link;
};

class stack{
	char data;
	stack *link , *head ,*top;
	
	public :
		stack(){
			head==NULL;
		}
		void push(char);
		void pop();
		void display();
		void postfix(char []);
};

struct node* top;

int count=0;
void push(int data){
	
	struct node* temp;
	temp=new node();
	
	temp->data=data;
	
	temp->link=top;
	top=temp;
	count++;
}

void pop(){
	struct node* temp;
	if (top==NULL){
		cout<<"Stack is empty "<<endl;
	}
	else{
	
	temp=top;
	
	top=top->link;
	
	temp->link=NULL;
	}
	cout<<endl;
}

void empty(){
	struct node* temp;
	if (top==NULL){
		cout<<"Stack is empty";
		cout<<endl;
	}
}

void display(){
	struct node* temp;
	
	if (top==NULL){
		cout<<"Stack is empty";
		exit(1);
	}
	else{
		temp=top;
		while(temp!=NULL){
//			temp=top;
			cout<<temp->data<<" ";
		
			temp=temp->link;
		
	}
		
	}
	
}

int priority(char x){
	if(x=='^')
		return 3;
	else if(x=='*' || x=='/')
			return 2;
		else if(x=='+' || x=='-')
			return 1;
				else
					return 0;	
		
}

void postfix(char infix[]){
	int i=0,j=0,instack , incoming ;
	char postfix[10];
	while(infix[i]!='\0'){
		if (!isalnum(infix[i])){
			if(infix[i]=='('){
				push(infix[i]);
				i++;
			}
			else{
				if (top==NULL){
					push(infix[i]);
					i++;
				}
				else{
					if(infix[i]==')'){
						while(top->data='('){
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else{
						instack=priority(top->data);
						
						incoming=priority(infix[i]);
						
						if( instack>=incoming){
							postfix[j]=top->data;
							j++;
							pop();
							push(infix[i]);
							i++;
						}
						else{
							push(infix[i]);
							i++;
						}
					}
				}
			}
		}
	else{
		postfix[j]=postfix[i];
		i++;j++;
	}	
	}
	while(top!=NULL){
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j]='\0';
	cout<<postfix;
}








int main(){
	struct node* temp;
	
	char infix[10];
	cout<< " enter your exprecion :"<<endl;
	cin>>infix;
	postfix(infix);
	cout<<endl;
	push(10);
	push(15);
	push(45);
	
	display();
//	cout<<endl;
	pop();
//	cout<<endl;
	display();
	pop();
	display();
	pop();
//	cout<<endl;
	display();
}
