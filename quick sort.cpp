#include <iostream>
using namespace std;
#include <stdio.h>

void printArray(int *A , int n){
	for (int i=0 ;i<n ; i++){
		cout<<A[i]<<" ";
	}
	cout<<"\n";
}

int partition(int A[] , int low , int high){
	int pivot=A[low];
	int i=low+1;
	int j=high;
	int temp;
	do{
	
	while(A[i]<=pivot){
		i++;
	}
	
	while(A[j]>pivot){
		j--;
	}
	if (i<j){
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;
	}
	}while(i<j);
	
//	swap A[low] and A[j]
	temp=A[low];
	A[low]=A[j];
	A[j]=temp;
	return j;
	
}




void quicksort(int A[],int low , int high){
	int partitionindex;      //index of pivot after partition
	
	if (low< high){
		partitionindex=partition(A, low ,high);
//		printArray(A,10);
		quicksort(A ,low ,partitionindex-1);             //sort left subarray
		quicksort(A , partitionindex+1 ,high);           //sort right subarray
	}
}

int main(){
	
	int A[]={2,4,3,9,1,4,8,7,5,6};
	
	int n=10;
	printArray(A,n);
	quicksort(A,0,n-1);
	printArray(A ,n);
	return 0;
}
