#include<iostream>
using namespace std;
struct student{
	char name[20];
	int age;
}p[10];

void  getdata(int i){
	cout<<"Enter the Name : ";
	cin>>p[i].name;

}
int main(){
	int n ,i;
	int ch;
	
	cout<<"Enter the number of student ";
	cin>>n;
	cout<< "01.Create Database "<<endl<< "02. Display Database"<<endl<<"03. Add a record"<<endl<<"04. Delete a record"<<endl<<"05. Modify a record "<<endl<<"06. Search record "<<endl<<"07. Exit";                                      
	cout<<" Enter your choice  ";
	cin>>i;
	

	switch (ch){
		case 01 :
		for(i=0;i<n;i++){
			getdata(i);
		}
	return 0;
	
	
}



