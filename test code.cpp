#include<iostream>
using namespace std;

class stack{
    char data;
    stack *link,*top;
//    char postfix[];

    public:
    stack(){
        top=NULL;
    }

    void push(char c);
    void pop();
    void postfix(char infix[]);
};

void stack :: push(char c){
    stack *newnode=new stack();
    newnode->data=c;
    newnode->link=NULL;
    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->link=top;
        top=newnode;
    }
}

void stack :: pop(){
    if(top=NULL){
        cout<<"Stack is empty"<<endl;
    }
    else{
        top=top->link;
    }
}


int priority(char t){

    if(t=='^'){
        return 3;
    }

    else if(t=='/' || t=='*'){
        return 2;
    }

    else if(t=='+' || t=='-'){
        return 1;
    }

    else{
        return 0;
    }

}


void stack::postfix( char infix[])
{
    int i=0;
    int a,b;
    char postfix[20];
    int j=0;
    while(infix[i]<='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(top==NULL)
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while (top->data!='(')
            {
                postfix[j]=top->data;
                j++;
                pop();
            }
            pop();
        }
        else{
            a=priority(top->data);
            b=priority(infix[i]);
            if(a>=b)
            {
                postfix[j]=top->data;
                j++;
                pop();
            }
            else{
                push(infix[i]);
            }

        }
    i++;   
    }
    while(top!=NULL)
    {
        postfix[j]=top->data;
        pop();
        j++;
    }
    postfix[j]='\0';
    cout<<endl<<"postfix expression : "<<postfix<<endl;
}

int main(){
    stack obj1;
    char infix[20];
    cout<<"enter the expression : "<<endl;
    cin>>infix;
    cout<<endl<<"infix : "<<infix<<endl;
//    cout<<endl<<"postfix expression : ";
    obj1.postfix(infix);    
//    cout<<str;
    return 0;
}
