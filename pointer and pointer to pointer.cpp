#include <iostream>
using namespace std;

int main(){
//	int b;
	
	int a=5;
	int *b;
	int **c;
	b=&a;
	c=&b;
	cout<<"the value of a : "<<a;
	cout<<"\nthe value of *b : "<<*b;
	cout<<"\nthe address of *b : "<<b;
	cout<<"\nthe number : "<<**c;
	cout<<"\nthe address of **c : "<<c;

	
}
