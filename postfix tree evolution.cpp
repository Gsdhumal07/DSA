#include <iostream>
#include<stack>
using namespace std;

class Stack{
	public:
	string str;
	Stack *left=NULL , *right=NULL;
	Stack(string x){
		x=str;
	}

};

bool oprator(char c){
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

main(){
	
}










