#include<iostream>
using namespace std;

class constructor{
	int sum,a,b;
	
	public:
		constructor();
		constructor(int ,int);
		void input(){
			int a,b;
			cout<<"the distance in meter : ";
			cin>>a;
			cout<<"the distance in centimeter : ";
			cin>>b;
		}
		void display(){
			cout<<"\nThe total distance is : ";
			cout<<sum;
		}
		
			
		
		
};

constructor::constructor(){
	int a,b;
	sum=a+b/100;
}

constructor::constructor(int p,int q){
	p=a;
	q=b;
	sum=p*100+q;
}

int main(){
	int x,y, ch;
	constructor c;
	c.input();
	do{
		cout<<"\n01.distance in meter "<<endl<<"02.distance in centimeter "<<endl;
		cout<<"\nEnter the choice : ";
		cin>>ch;
		
	switch(ch){
		
		
		case 01:
			constructor();
			c.display();
			cout<<endl;
			break;
			
		case 02:
			constructor(x,y);
			c.display();
			cout<<endl;
			break;
	}
	}while(ch!=0);
	return 0;

}
