#include<iostream>
using namespace std;
int count=0;
class num{
	public:
		num(){
			count++;
			cout<<"this is the time you call constructur  no  : "<<count<<endl;
		}
		
		~num(){
			cout<<"this time you callede the destructor : "<<count<<endl;
			count--;
		}
};

int main(){
	cout<<"now we are in main function "<<endl;
	cout<<"creating two objects n1 "<<endl;
	num n1;
	{
		cout<<"entering this block"<<endl;
		cout<<"creating two more objects"<<endl;
		num n2 ,n3;
		cout<<"exiting the block"<<endl;
	}
	
	cout<<"Back to the main function"<<endl;
	return 0;
}

