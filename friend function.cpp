#include<iostream>
using namespace std;

class test{
	int a,b,sum;
	public:
		
		void input(){
			cout<<"enter the value in meter : ";
			cin>>a;
			cout<<"\nenter the value in centimeter : ";
			cin>>b;
		}
		
		friend void addmeter(test &t);
		friend void addcentimeter(test &t);
		void display(){
	cout<<"\nthe addition of the distance is : "<<endl<<sum;
		}
};

void addmeter(test &t){
	t.sum=t.a+(t.b)/100;
}

void addcentimeter(test &t){
	t.sum=(t.a)*100+(t.b);
}

int main(){
	int ch;
	test t;
	t.input();
	do{
		cout<<"\n01.distance in meter "<<endl<<"02.distance in centimeter "<<endl;
		cout<<"\nEnter your choice  : ";
		cin>>ch;
	
	switch(ch){
		
		
		
		case 01:
			addmeter(t);
			t.display();
			break;
			
		case 02:
			addcentimeter(t);
			t.display();
			break;	
	}
		
	}while(ch!=0);
//	addmeter(t);
	
	return 0;
}
