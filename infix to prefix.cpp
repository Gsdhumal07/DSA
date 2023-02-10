#include <iostream>
#include<stack>
#include<algorithm>
using namespace std;


bool isOprator(char c){
	if(c=='/' || c=='*' || c=='+' || c=='-' )
		return true;
	}
//	else{
//		return false;
//	}

int precedance(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='/' || c=='*'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

string infixtoprefix(stack<char> s, string infix){
	string prefix;
	reverse(infix.begin() , infix.end());
	
	for(int i=0;i<infix.length();i++){
		if(infix[i]=='('){
			infix[i]==')';
		}
		else if(infix[i]==')'){
			infix[i]='(';
		}
		
	}
	
	for (int i=0;i<infix.length();i++){
		if(isalnum(infix[i])){
			prefix+=infix[i];
		}
		else if(infix[i]=='('){
			s.push(infix[i]);
		}
		else if(infix[i]==')'){
			while(s.top()!='(' && !s.empty()){
				prefix+=s.top();
				s.pop();
			}
		}
		else if(isOprator(infix[i])){
			if(s.empty()){
				s.push(infix[i]);
			}
			else{
				if(precedance(infix[i] > precedance(s.top()))){
					s.push(infix[i]);
				}
				else{
					if(precedance(infix[i]==precedance(s.top())) && infix[i]=='^'){
						while(precedance(infix[i]==precedance(s.top())) && infix[i]=='^'){
							prefix+=s.top();
							s.pop();
						}
						s.push(infix[i]);
					}
					else{
						if(precedance(infix[i]==precedance(s.top()))){
							s.push(infix[i]);
						}
						else{
							while(!s.empty() && precedance(infix[i])==precedance(s.top())){
								prefix+=s.top();
								s.pop();
								
							}
							s.push(infix[i]);
						}
					}
					
				}
			}
			while(!s.empty()){
				prefix+=s.top();
				s.pop();
			}
			reverse(prefix.begin() , prefix.end());
			return prefix;
		}
	}
}

int main(){
	string infix , prefix;
	cout<<"Enter your infux opration :"<<endl;
	cin>>infix;
	stack<char> s;
	cout<<"infix expression : "<<infix<<endl;
	prefix=infixtoprefix(size(10) , infix);
	cout<<" prefix expression : "<<prefix;
}




