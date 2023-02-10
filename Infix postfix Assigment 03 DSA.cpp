#include <iostream>
#include<string.h>
using namespace std;

class node
{
    int data;
    node *next,*top;
	public:
     node()
     {
     top = NULL;
    }
     void push(int);
     void pop();
    char *postfix(char []);
    void eval(char [] );
    char* reverse(char[]);
  void  prefix_eval(char A[]);
};

void node :: push(int element)
{
     node *newnode = new node;
     newnode->data = element;
     newnode->next = NULL;
     if(top == NULL)
     {
     top = newnode;
     }
     else
     {
     newnode->next = top;
     top = newnode;
    }
}

void node :: pop()
{
     if(top == NULL)
     {
     cout << "Stack is empty";
     }
     else
     {
     node *ptr = top;
     top = top->next;
     delete ptr;
     }
}

int priority(char a)
{
     if(a == '^')
     return 3;
    else if(a == '/' || a == '*')
     return 2;
    else if(a == '+' || a == '-')
     return 1;
    else
     return 0;
}
char*node ::postfix(char infix[] ){
	int i,j;
	char a,in;
	i=0;
	j=0;
	char*abc;
	
	char postfix[20];
	abc=postfix;
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
						a=priority(top->data);
						in=priority(infix[i]);
						while(top!=NULL && a>=in){
							postfix[j]=top->data;
							j++;
							pop();
						}
						push(infix[i]);
						i++;
					}
				}
			}
		}
		else{
			postfix[j]=infix[i];
			i++;
			j++;
		}
	}
	while(top!=NULL){
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j]='\0';
	//cout<<"\n your postfix expression is:-";
	//cout<<postfix;
	return abc;
}

int calci(int x,int y,char z){
	if(z=='/'){
		return(y/x);
		
	}
	else if(z=='*'){
		return(y*x);
	}
	else if(z=='-'){
		return(y-x);
	}
	else if(z=='+'){
		return(y+x);
	}
	else{
		cout<<"invalide operator in stack";
	}	
}
int rt_value(char a){
	if(a=='1'){
		return 1;
	}
	else if(a=='2'){
		return 2;
	}
	else if(a=='3'){
		return 3;
	}
	else if(a=='4'){
		return 4;
	}
	else if(a=='5'){
		return 5;
	}
	else if(a=='6'){
		return 6;
	}
	else if(a=='7'){
		return 7;
	}
	else if(a=='8'){
		return 8;
	}
	else if(a=='9'){
		return 9; 
	}
}
void node::eval(char postfix[]){
	int i=0;
	int int_val;
	int x,y,current_value,net_value;
	do{
		while(isalnum(postfix[i])){
			if(isdigit(postfix[i])){
				push(rt_value(postfix[i]));
			}
			else {
				cout<<"\n Enter the value for "<<postfix[i]<<":-";
				cin>>int_val;
				push(int_val);
			}
			i++;
		}
		x=top->data;
		pop();
		y=top->data;
		pop();
		current_value=calci(x,y,postfix[i]);
		i++;
		push(current_value);
			
	}while(postfix[i]!='\0');
	net_value=top->data;
	cout<<"\n \nThe postfix Evolution is : "<<net_value;
	pop();
}
char* node::reverse(char exp[])
{
	int i, j = 0;
	char rev[20];
	int len = strlen(exp); 
	for(i=len-1; i>=0; i--)
	{
		if(exp[i] == '(')
		{
			rev[j] = ')';
		}
		else if(exp[i] == ')')
		{
			rev[j] = '(';
		}
		else
		{		
		rev[j] = exp[i];
		}
		j++;
	
	}
	rev[j] = '\0';
	return rev;
}
void node::prefix_eval(char pre[]){
	
	int i=0,alpha;
    char X,Y,opr;
    
    while(pre[i]!='\0'){
        i++;
    }
    
    for(int j=i-1; j>=0 ; j--){
	
    	
    	if(isalnum(pre[j])){
            
            if(isdigit(pre[j])){
                push(pre[j]);
            }
            
            else{
            	cout<<"\nEnter the Numerical value for "<<pre[j]<<" : ";
				cin>>alpha;
				push(alpha);
			}
			
	    } 
	    
	    else{

            int val;
            X=top->data;
            pop();  
            Y=top->data;
            pop();
            opr=pre[j];
            val=calci(Y,X,opr);
            push(val);
            
        }

        
	}
	
	int ans;
    ans=top->data;
    cout<<" \n \n The Prefix Evolution is : "<<ans;
    pop();
	
}

int main(){
	node a;
	char infix[20];
	int choice;
	char*postfix;
	char*exp;
	char*obj;
	char*prefix;
		cout<<"Enter infix expression : ";
		cin>>infix;
	do{	
		cout<<"\n \n 01.Postifix Exprestion  \n 02.postfix evaluation \n 03.Infix conversion \n 04.Prefix Evolution ";
		cout<<"\n \n Enter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
					cout<<"\n postfix expression is :"<<a.postfix(infix);
				break;
			case 2:
				postfix=a.postfix(infix);
				a.eval(postfix);
				break;
			case 3:
				exp=a.reverse(infix);
				obj=a.postfix(exp);
				prefix=a.reverse(obj);
				cout<<"\n prefix expresion is "<<prefix;
				break;
			case 4:
				exp=a.reverse(infix);
				obj=a.postfix(exp);
				prefix=a.reverse(obj);
				a.prefix_eval(prefix);
		}
		
	}while(choice!=0);
	return 0;
}
