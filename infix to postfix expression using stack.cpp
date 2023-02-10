#include <iostream>
#include<stack>
#include<math.h>
using namespace std;

int precedance(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else {
		return -1;
	}
}

string infixtopostfix(string s){
	stack<char> st;
	string result;
	
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ){
			result+=s[i];
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty() &&  st.top()!='('){
				result+=st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{
			while(!st.empty() && precedance(st.top()) > precedance(s[i])){
				result+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		
	}
	while(st.empty()){
		result+=st.top();
		st.pop();
	}
	return result;
}


int postfixevolution(string s){
	stack<int > st;
	
	for(int i=0 ;i<s.length();i++){
		if(s[i]>='0' && s[i]<= '9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(s[i]){
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
					
			}
					
		}
	}
	return st.top();
}


int main(){
	string infix;
	cout<<"Enter the infix expression : ";
	cin>>infix;
	cout<<endl<<infixtopostfix(infix);
//	
//	cout<<"The postfix evolution is : ";
//	cout<<postfixevolution("10 5+36 6/*8-");
}



