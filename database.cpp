#include <iostream>
using namespace std;

class  database{
	string name;
	int roll_no;
	int marks;
	friend database avg();
};

void getdata(){
	int mark[5];
	
	for (int i=1; i<6;i++){
		cout<<"enter the marks in subject  "<<i<<" : ";
		cin>>mark[i];
	}

}


void display(){
	int mark[5];
	for(int i=1;i<6;i++){
		cout<<mark[i]<<" ";
		cout<<endl;
	}
	
}

database avg(){
	int mark;
	int marks[5];
	cout<<"the average of the marks : ";
	for (int i=1;i<6;i++){
		mark=mark+marks[i];
		
		
	}
	cout<<(mark-6)/5;
}

int main(){
	string name;
	int roll_no;
	cout<<" enter the name of the student : ";
	cin>>name;
	cout<<" enter the roll no of "<<name<<" : ";
	cin>>roll_no;
	getdata();
	display();
	avg();
}


