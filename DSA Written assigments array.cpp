#include<iostream>
#include<string>
using namespace std;

void buble(int sort[]){
	for (int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(sort[i]>sort[j]){
				int temp=sort[i];
				sort[i]=sort[j];
				sort[j]=temp;
			}
		}
	}
}

int main(){
	int array[5]={9,7,8,12,10};
	int sort[5];
	int pass=0;
	for(int i=0;i<5;i++){
		pass=pass+1;
	}
	cout<<"the length of the array : "<<pass<<endl;
	
	for(int i=0;i<5;i++){
		sort[i]=array[i];
	}
	buble(array);
//	print(array,array);
	cout<<"\nthe array of the elements is : ";
	for(int i=0;i<5;i++){
		
		cout<<sort[i]<<" ";
	}
	cout<<endl;
	cout<<"\nthe sorted array of the elements : ";
	for(int i=0;i<5;i++){
		
		cout<<array[i]<<" ";
	}
	
	cout<<endl<<endl;
	cout<<"position of unsorted elements in a sorted array : ";
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(sort[i]==array[j]){
				cout<<j+1<<" ";
			}
		}
	}
	
}
