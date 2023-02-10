#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number ";
	cin>>n;
	string p[n] , x;
	cout<<"Enter your numbers ";
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for (int i=0;i<n;i++){
		string a=p[i];
		for(int j=a.length()-1;j>=0;j--){
			cout<<a[j];
		}
		cout<<endl;
	}
	
}
