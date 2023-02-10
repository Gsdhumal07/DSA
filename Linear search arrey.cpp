#include <iostream>
using namespace std;

int linearsearch(int arrey[],int size , int element){
	for (int i=0 ; i < size ; i++){
		if(arrey[i]==element){
			return i;
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

	int searchindex=linearsearch(arrey,size,element);
	cout<<"the number that you entered is at "<<searchindex<<" index position";
	return 0;	
}
		
	
