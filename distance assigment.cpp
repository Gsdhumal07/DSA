#include <iostream>
using namespace std;

class distance1;

class distance2{
	private :
		int sum;
		
	public :
		int meter;
		input(){
			meter=0;
		};
		input(int a){
			meter=a;
		}
		
		friend distance1 addmeter(distance1 , distance2);
		friend distance2 addcentimeter(distance2 ,distance1);
		
		
};

class distance1{
	private:
		int sum;
	public:
		int meter;
		input(){
			meter =0;
		}
		input(int a){
			meter = a;
		}
		
};






int main(){
	int x,y;
	distance1 obj1;
	distance2 obj2;
	cout<<"enter the distance in meter : ";
	cin>>x;
	cout<<"enter the distance in centimeter : ";
	cin>>y;
	obj1.input(x);
	obj2.input(y);
}






