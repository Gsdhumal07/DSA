#include <iostream>
using namespace std;

//Linear search method

int linearsearch(int arrey[],int size , int element){
	for (int i=0 ; i < size ; i++){
		if(arrey[i]==element){
			cout<<"element present at index no : "<<i;
		}
		 
	}
//	string a =" is not ";
	return 0;

}

//Binary search method 

int binarysearch(int arrey[],int size , int element){
	int low , high , mid ;
	low = 0;
	high = size -1;
	mid = (low + high)/2;
	while ( low <= high){
		mid=(low  + high) / 2 ;
		if (arrey[mid]==element){
			return mid ;
		}
		if (arrey[mid]<element){
			low = mid +1 ;
		}
		else {
			high = mid -1 ;
			
		}
	}
	return -1;
	
}


int main(){
	int arrey[] ={1,4,6,7,8,9,12,16,45,78,98};
	int size=sizeof(arrey)/sizeof(int);
	int element ;
	cout<<"Enter the element  ";
	cin>>element;

	int searchindex=binarysearch(arrey,size,element);
	cout<<"the number that you entered is at "<<searchindex<<" index position";
	return 0;	
}
		
	
