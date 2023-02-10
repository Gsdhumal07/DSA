#include<iostream>
using namespace std;

void Max_heap(int arr[] , int i , int n){
	int largest =i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && arr[left > arr[largest]]){
		largest=left;
	}
	else{
		largest=i;
	}
	if(right<n && arr[right] > arr[largest]){
		largest= right;
	}
	if(largest!=i){
		int temp= arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		M[]ax_heap()
	}
	
	
	
	
}
