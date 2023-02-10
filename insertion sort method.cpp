#include<iostream>
using namespace std;

void display(int array[], int size){
	for (int i =0; i<size ; i++){
		cout<<array[i]<<" ";
//	cout<<endl;	
	}
	
}
void insertionsort(int*array ,int size){
	int key , j;
	for(int i =1 ; i<size ;i++){
		key=array[i];           //take value
		j=i;
		while(j>0 && array[j-1]>key){
			array[j]=array[j-1];
			j--;
		}
		array[j]=key;            //insertion in right place
	}
}

int main(){
	int n;
	cout<<" Enter the no of elements : ";
	cin>>n;
	int arr[n];            //create an array with given number of element
	cout<<"Enter the elements  : "<<endl;
	for(int i =0 ; i<n ; i++){
		cin>>arr[i];
	}
	cout<<"Array befour sorting : "<<endl;
	display(arr , n);
	insertionsort(arr , n);
	cout<<"\narray after sorting : "<<endl;
	display(arr , n);
}












