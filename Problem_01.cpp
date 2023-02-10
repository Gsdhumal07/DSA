#include<iostream>
using namespace std;

int main(){
	int n;
	int count=0;
	cout<<"Enter the number : ";
	cin>>n;
	for(int i=1;i<=n;i++){
			if(i==2){
				cout<<2<<" ";
				count++;
			}
			else if(i==3){
				cout<<3<<" ";
				count++;
			}
			else if(i%2!=0 && i%3!=0 && i%n/2) {
				cout<<i<<" ";
				count++;	
			}		
		
	}
	if(count==0){
		cout<<"No prime number present befout this number";
	}
	return 0;
}
