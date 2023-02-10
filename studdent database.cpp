#include<iostream>
using namespace std;
struct student{
    char name[5];
    int roll_no;
    float sgpa;
}s[5];

void getdata(int i){
    cout<<"\n Enter your name:";
    cin>>s[i].name;
    cout<<"\n Enter your roll_no :";
    cin>>s[i].roll_no;
    cout<<"\n Eenter your sgpa";
    cin>>s[i].sgpa;
}
void display(int i){
   	cout<<"Name :";
	cout<<s[i].name;
	cout<<"ROll no :";
	cout<<s[i].roll_no;
	cout<<"SGPA :";
	cout<<s[i].sgpa;
    }
 void search(int i)  {
     
 }   
int main()   {
    int i;
    int sgpa;
    char name;
    for(i=1;i<=5;i++)   {
        getdata(i);
    if (i==5)   {
//        cout<<"stop";
        break;
    }
    }
    for (int i ; i<5 ; i++){
    	display(i);
	}
	if (s[i].sgpa==s[i+1].sgpa){
		cout<<s[i].name <<s[i+1].name;
	}
    return 0;
   
}
