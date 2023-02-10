////#include<bits/stdc++.h>
////using namespace std;
////
////
//////function to print the array
////void print(vector<string>names){
////	cout<<"printing...........\n";
////	for(int i =0;  i<names.size();i++){
////		cout<<names[i]<<endl;
////		cout<<endl;
////	}
////}
////
////bool mycomp(string a , string b){
//////	return 1 if string a is alphabetically less than string b
//////	quit similar to strcmp opration
////	return a<b;
////	
////}
////
////vector<string> alphabeticallysort(vector<string> a){
////	int n= a.size();
//////	mycomp function is the defined function which sort the string in alphabetical order
////	sort(a.begin(),a.end(),mycomp);
////	return a;
////	}
////
////
////int main(){
////	int n;
////	cout<<" enter the names to be added : " ;
////	cin>>n;
////	
//////	creating a vector of strings 
//////	vector to store strings(names)
////	vector<string> names;
////	string name;
////	cout<<"enter the names : \n";
//////	taking input
////	for (int i =0; i<n;i++){
////		cin>>name;
//////		insert names into the vector
////		names.push_back(name);
////	}
////	
////	cout<<"\nbefout sorting \n : ";
////	cout<<name;
////	
//////	functio to sort names alphabetically
////	names=alphabeticallysort(names);
////	cout<<"\nalphabetically sorted  \n";
////	cout<<name;
////	
////	return 0;
////}
//
//
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//
//int main(){
//	string arnlist[5]={"ganesh","shard","kumbhakarn","hari","athvle"};
//	int length=5;
//	string temp;
//	int i;
//	for(i=1;i<length;i++){
////		the new value inserted into a temporary location 
//	temp=arnlist[i];
////	k is the index of number to the left of the i
//	int k;
//	for(int k=i-1;k>=0 && arnlist[k]>temp; k--){
//		arnlist[k+1]=arnlist[k];
//	}
//	arnlist[k+1]=temp;
//	}
//	for(i=0;i<length;i++){
//		cout<<arnlist[i]<<" ";
//		cout<<endl;
//		return 0;
//	}
////}



//#include <bits/stdc++.h>
//using namespace std;
//
////function to print the array
//void print(vector<string> names){
//	printf("printing ........\n");
//	for(int i=0;i<names.size();i++)
//		cout<<names[i]<<endl;
//	printf("\n");
//}
//
//bool mycomp(string a, string b){
//	//returns 1 if string a is alphabetically 
//	//less than string b
//	//quite similar to strcmp operation
//	return a<b;
//}
//
//vector<string> alphabaticallySort(vector<string> a){
//	int n=a.size();
//	//mycomp function is the defined function which 
//	//sorts the strings in alphabatical order
//	sort(a.begin(),a.end(),mycomp);
//	return a;
//}
//
//int main()
//{   
//	int n;
//	printf("enter number of names to be added: ");
//	scanf("%d",&n);
//
//	//creating a vector of strings
//	//vector to store strings(names)
//	vector<string> names;
//	string name;
//	printf("enter names: \n");
//	//taking input
//	for(int i=0;i<n;i++){
//		cin>>name;
//		//insert names into the vector
//		names.push_back(name); 
//	}
//
//	printf("\nbefore sorting\n");
//	print(names);
//
//	//function to sort names alphabetically
//	names=alphabaticallySort(names);
//
//	printf("after alphabetical sorting\n");
//	print(names);
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string arnList[9]={"John", "Dave", "Steve", "Kevin","Andrew","Scott","Colin","Timothy","Zenon"};
  int nLength=9;
  string nTemp;
  int iCv;

  for (iCv = 1; iCv < nLength; ++iCv)
  {
    //the new value to be inserted into a temporary location 
    nTemp = arnList[iCv];
    // k is the index of the number to the left of the iCv.
    int k;

    for (k = iCv-1; k >= 0 && arnList[k] > nTemp; k--)
    {
      arnList[k+1] = arnList[k];
    }
    arnList[k+1] = nTemp;
  }
  for(iCv=0;iCv<nLength;iCv++) cout<<arnList[iCv]<<" , ";
  cout<<endl;

  return 0;
}


















