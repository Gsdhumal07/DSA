#include<iostream>
using namespace std;

int main(){
	int n,maxw;
	float p;
	
	cout<<"Enter the no of process :";
	cin>>n;
	cout<<"Enter the max Wait : ";
	cin>>maxw;
	int wt=maxw;
	float profit[n];
	float wait[n];
	float ratio[n];
	cout<<"Enter the Profit : ";
	for(int i=0;i<n;i++){
		cin>>profit[i];
	}
	cout<<"Enter the wait : ";
	for(int i=0;i<n;i++){
		cin>>wait[i];
		ratio[i]=profit[i]/wait[i];
	}
	cout<<"Profit : ";
	for(int i=0;i<n;i++){
		cout<<profit[i]<<"\t";
	}
	cout<<"\n";
	cout<<"Wait : ";
	for(int i=0;i<n;i++){
		cout<<wait[i]<<"\t";
	}
	cout<<"\n";
	cout<<"Ratio : ";
	for(int i=0;i<n;i++){
		cout<<ratio[i]<<"\t";
	}
	cout<<"\n";


	for(int i=0;i<n;i++){
	for (int j =0;j<n;j++){
		if(ratio[i]>ratio[j]){
			float temp= ratio[i];
			ratio[i]=ratio[j];
			ratio[j]=temp;
			float ptemp=profit[i];
			profit[i]=profit[j];
			profit[j]=ptemp;
			float wtemp=wait[i];
			wait[i]=wait[j];
			wait[j]=wtemp;
		}
	}
}
cout<<"Profit : ";
	for(int i=0;i<n;i++){
		cout<<profit[i]<<"\t";
	}
	cout<<"\n";
	cout<<"Wait : ";
	for(int i=0;i<n;i++){
		cout<<wait[i]<<"\t";
	}
	cout<<"\n";
	cout<<"Ratio : ";
	for(int i=0;i<n;i++){
		cout<<ratio[i]<<"\t";
	}
	cout<<"\n \t";
	
	for(int i=0;i<n;i++){
		if(wt-wait[i]>=0){
			wt=wt-wait[i];
			p=p+wait[i];
			
		}
	}
	
}
	
	
	

