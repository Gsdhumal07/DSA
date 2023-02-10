#include<iostream>
using namespace std;

struct Student {
	string name;
	int roll_no;
	int sgpa;
	
}a[10];


void display(int i){
	
	cout<< "\nName :"<<a[i].name<<"\tt"<<"\nRoll no. : "<<a[i].roll_no<<"\tt"<<"\nSGPA :"<<a[i].sgpa;
	
}

void getdata(struct Student){
//	int i ;
	for (int i = 1 ; i<5; i++){
	cout<<"\nEnter the name  :";
	cin>>a[i].name;
	cout<<"\nEnter the number :";
	cin>>a[i].roll_no;
	cout<<"\nEnter the SGPA :";
	cin>>a[i].sgpa;		
	}
	
		
}


int main()
{
	int i;
	struct Student a;
	
	
	
	getdata(a);
	
	for (int i = 1; i < 5 ; i++){
	display(i);
	}
	
	return 0;
}
