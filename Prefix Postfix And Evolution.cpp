#include<iostream>
#include<string.h>
using namespace std;

class stack{
	int data;
	stack *link,*top;
	public:
		stack(){
			top=NULL;
		}
		void push(int);
		void pop();
		int priority(char);
		char* InfixToPostfix(char[]);
		char* reverse(char[]);
		void evolution(char[]);
		
};

void stack::push(int item){
	stack *newnode=new stack();
	newnode->data=item;
	newnode->link=NULL;
	
	if (top==NULL){
		top=newnode;
	}
	else{
		newnode->link=top;
		top=newnode;
	}
}

void stack::pop(){
	if(top==NULL){
		cout<<"......QUEUE IS EMPTY......."<<endl;
	}
	else{
		stack *node=top;
		top=top->link;
		delete(node);
	}
}

int stack::priority(char x){
	if(x=='^'){
		return 3;
	}
	
	else if(x=='*' || x=='/'){
		return 2;
	}
	
	else if(x=='+' || x=='-'){
		return 1;
	}
	
	else{
		return 0;
	}
}


char* stack::InfixToPostfix(char infix []){
	int i=0 , j=0 , instack , income ;
	char postfix[20];
	while(infix[i]!='\0'){
		if(!isalnum(infix[i])){
			if(infix[i]=='('){
				push(infix[i]);
				i++;
			}
			else{
				if(top==NULL){
					push(infix[i]);
					i++;
				}
				else{
					if(infix[i]==')'){
						while(top->data!='('){
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else{
						instack=priority(top->data);
						income=priority(infix[i]);
						
						while(top!=NULL && instack >= income){
							postfix[j]=top->data;
							j++;
							pop();
							if(top!=NULL){
								instack=priority(top->data);
								income=priority(infix[i]);
							}
						}
						push(infix[i]);
						i++;
					}
				}
			}
			
		}
		postfix[i]=infix[i];
		i++;
		j++;
	}
	postfix[j]='\0';
	return postfix;
} 

int calculate(int a, int b, char oprator){
	if(oprator=='+' ){
		return (a+b);
	}
	else if(oprator == '-'){
		return (a-b);
	}
	else if(oprator=='*'){
		return(a*b);
	}
	else if(oprator =='/' && b!=0){
		return (a/b);
	}
}

void stack::evolution(char postfix[]){
	int result , final , a , b , i=0 , input;
	do{
		while(isalnum(postfix[i])){
		if(isalpha(postfix[i])){
		
			push(postfix[i]);
		}
		else{
			cout<<"Enter the value of : "<<postfix[i]<<" ";
			cin>>input;
			push(input);
		}
		i++;	
		}
	
		b=top->data;
		pop();
		a=top->data;
		pop();
		result=calculate(a,b,postfix[i]);
		i++;
		push(result);

	}while(postfix[i]!='\0');
		final=top->data;
		cout<<"EVOLUTION OF POSTFIX : "<<final;
		pop();
		
	}
	
char* stack::reverse(char line[]){
	int i=0,j=0;
	char rev[20];
	int len=strlen(line);
	for(i=len-1;i>0;i++){
		if(line[i]=='('){
			rev[j]=')';
		}
		else if(line[i]==')'){
			rev[j]='(';
		}
		else{
			rev[j]=line[i];
		}
		j++;
	}
	rev[j]='\0';
	return rev;
}

int main(){
		int ch, eval;
	char infix[20];
	char* post;
	char* fixin;
	char* temp;
	char* prefix;
	stack obj;
	cout<<"\nEnter the infix expression\n";
	cin>>infix;
	
	do
	{
	cout<<"\nwhat will you like to do"<<endl;
	
	cout<<"\n 1]Postfix";
	cout<<"\n 2]Prefix";
	cout<<"\n 3]Postfix Evaluation\n";
	cout<<"\n 0]Exit";
	cin>>ch;
	switch(ch)
	{
		case 0:
			cout<<"\n.....END.....\n";
			break;
		case 1:
			post = obj.InfixToPostfix(infix);
			cout<<"\nPostfix : "<<post;
			break;
		case 2:
			fixin = obj.reverse(infix);
			temp = obj.InfixToPostfix(fixin);			
			prefix = obj.reverse(temp);
			cout<<"\nPrefix :\t"<<prefix;
			break;
		case 3:
			post = obj.InfixToPostfix(infix);		
			obj.evolution(post);
			break;			
		default:
			cout<<"\n.....Wrong choice.....\n";	
				
	}
	}while(ch!=0); 
	
}











