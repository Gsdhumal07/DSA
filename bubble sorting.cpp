#include<iostream>
using namespace std;

int main(){
	int sort[8];
	int i , j , temp , pass=0;
	int array[8]={10,2,40,11,3,1,9,7};
//	cout<<array[0];
	cout<<"---Input list ---"<<endl;
	for (int i =0; i<8 ; i++){
		cout<<array[i]<<"\t";
	}
	
//	{ 1 2 3 7 9 10 11 40 }
//  { 5 1 7 6 2 0 4 3 
cout<<endl<<"\n------------------------------------------------------------------"<<endl;

for(int i=0; i<7;i++){
	for (int j=i+1;j<8;j++){
		if (array[j]<array[i]){
//			cout<<i<<" ";
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			
		}
		
	}
pass++;	
}

cout<<endl;	
cout<<"\n ---------Sorted number list----- :"<<endl;
for(int i=0; i<8;i++){
//	cout<<i<<" "<<endl;
	cout<<array[i]<<"\t";
}
cout<<endl<<"\nNumber of passes taken to sort the list : "<<pass<<endl;

return 0;	
}
