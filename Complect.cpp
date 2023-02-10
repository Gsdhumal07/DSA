#include <iostream>
#include <string.h>
using namespace std;


class stack
{
	int data;
	stack *link, *top;
	
	public:
		stack()
		{
			top = NULL;	
		}
		void push(int);
		void pop();
		char* postfix(char[]);
		int priority(char);
		char* reverse(char[]);
		void post_eval(char[]);
};

void stack::push(int item)
{
	stack *newnode = new stack();
	newnode->data = item;
	newnode->link = NULL;

	if(top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->link = top;
		top = newnode;
	}
}

void stack::pop()  
{
	
	if(top == NULL)
	{
		cout<<"\n...Stack is empty...";
	}
	else
	{  
		stack *node = top;
		top = top->link;
		delete(node);
	}
}

int stack::priority(char x)

{
	if(x=='^')
		return 3;	
		
	else if((x =='*') || (x == '/'))
		return 2;
		
	else if((x == '+') || (x == '-'))
		return 1;
		
	else
		return 0;
	
}

char* stack::postfix(char infix[])
{
	int i = 0, j = 0, instack, income;
	char postfix[20];
	while(infix[i]!='\0')
	{
		if(!isalnum(infix[i]))
		{
			if(infix[i]=='(')
			{
				push(infix[i]);
				i++;
			}
			else
			{
				if(top == NULL)
				{
					push(infix[i]);
					i++;
				}
				else
				{
					if(infix[i]==')')
					{
						while(top->data!='(')
						{
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else
					{
					
						instack = priority(top->data);
						income = priority(infix[i]);
						
						while(top!=NULL && instack>=income)
						{
							postfix[j] = top->data;
							j++;
							pop();
							if(top!=NULL)
							{							
							instack = priority(top->data);
							income = priority(infix[i]);
							}
						}
							push(infix[i]);
							i++;	
					}
				}
			}
		}
		else
		{
			postfix[j] = infix[i];
			i++;
			j++;	
		}
	}
	while(top != NULL)
	{
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}

int calculate(int y, int x ,char opr)
{
	if(opr == '/' && y != 0)
		return (x / y);
		
	else if(opr == '-')
		return (x - y);
		
	else if(opr == '*')
		return (x * y);
		
	else 
		return (x + y);
}

void stack::post_eval(char postfix[])
{
	int alpha, x, y, result, answer, i=0;
	do
	{	
		while(isalnum(postfix[i]))
		{
			if(!isalpha(postfix[i]))
			{
				push(postfix[i]);
			}
			else
			{
				cout<<"\nEnter the Numerical value for "<<postfix[i]<<" : ";
				cin>>alpha;
				push(alpha);
			}
			i++;
		}
		y = top->data;
		pop();
		x = top->data;
		pop();
		result = calculate(y, x , postfix[i]);
		i++;	
		push(result);
	}while(postfix[i] != '\0');
			
		answer = top->data;
		cout<<"\nPostfix Evaluated :"<<answer;
		pop();	
}

char* stack::reverse(char line[])
{
	int i, j = 0;
	char revline[20];
	int len = strlen(line); 
	for(i=len-1; i>=0; i--)
	{
		if(line[i] == '(')
		{
			revline[j] = ')';
		}
		else if(line[i] == ')')
		{
			revline[j] = '(';
		}
		else
		{		
		revline[j] = line[i];
		}
		j++;
	
	}
	revline[j] = '\0';
	return revline;
}

int main()
{
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
	cout<<"\nwhat will you like to do";
	cout<<"\n 0]Exit";
	cout<<"\n 1]Postfix";
	cout<<"\n 2]Prefix";
	cout<<"\n 3]Postfix Evaluation\n";
	cin>>ch;
	switch(ch)
	{
		case 0:
			cout<<"\n.....END.....\n";
			break;
		case 1:
			post = obj.postfix(infix);
			cout<<"\nPostfix : "<<post;
			break;
		case 2:
			fixin = obj.reverse(infix);
			temp = obj.postfix(fixin);			
			prefix = obj.reverse(temp);
			cout<<"\nPrefix :\t"<<prefix;
			break;
		case 3:
			post = obj.postfix(infix);		
			obj.post_eval(post);
			break;			
		default:
			cout<<"\n.....Wrong choice.....\n";	
				
	}
	}while(ch!=0); 

}
