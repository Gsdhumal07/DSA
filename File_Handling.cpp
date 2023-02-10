#include <iostream>
#include <fstream>
using namespace std;
class student{
	int roll,age;
	string email,name,address;
	public:
		void getdata();
		void display();
};
void student::getdata(){
	cout<<"\nEnter your Name:";
	cin>>name;
	cout<<"Enter your roll no.:";
	cin>>roll;
	cout<<"Enter your age:";
	cin>>age;
	cout<<"Enter your address:";
	cin>>address;
	cout<<"Enter your email:";
	cin>>email;
	
}
void student::display(){
	cout<<"\nName:"<<name;
	cout<<"\nRoll no.:"<<roll;
	cout<<"\nage:"<<age;
	cout<<"\naddress:"<<address;
	cout<<"\nEmail:"<<email;
}

int main(){
	student s;
	fstream file;
	int ch;
	do{
		cout<<"\n1.create database \n2.add record \n3.search \n4.Modify \n5.delete \n6.Display \n7.exit\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				file.open("student.doc",ios::out);
				int rec1;
				cout<<"Enter number of records:";
				cin>>rec1;
		        file.seekp(0,ios::end);
		        for(int i=0;i<rec1;i++){
		        	s.getdata();
		        	file.write((char*)&s,sizeof(s));
				}
				file.close();
				break;
			case 2:
				file.open("student.doc",ios::app);
				cout<<"Enter the no.of record you want to add:";
				int rec;
				cin>>rec;
				file.seekp(0,ios::end);
				for(int i=0;i<rec;i++){
				s.getdata();
		        file.write((char*)&s,sizeof(s));
				}
				file.close();
				break;		
			case 3:
				int  ser,loc;
				file.open("student.doc",ios::in);
				cout<<"Enter the record you want to search:";
				cin>>ser;
				file.seekp(0);
				loc=(ser-1)*sizeof(s);
				file.seekg(loc,ios::beg);
				file.read((char*)&s,sizeof(s));
				s.display();
				file.close();
				break;
			case 4:
				int  mod,loc1;
				file.open("student.doc",ios::in|ios::out);
				cout<<"Enter the record you want to modify:";
				cin>>mod;
				loc1=(mod-1)*sizeof(s);
				file.seekp(loc1,ios::beg);
				s.getdata();
				file.write((char*)&s,sizeof(s));
				file.close();
				break;
			case 5:{
				
			    int del;
			    int k=1;
			    file.open("student.doc",ios::in|ios::out);
				cout<<"Enter the record you want to delete:";
				cin>>del;
				fstream temp;
				temp.open("temp.doc",ios::out);
		
				while(file.read((char*)&s,sizeof(s))){
	
					if(del==k){
						
					}
					else{
						temp.write((char*)&s,sizeof(s));
					}
					k++;}
				file.close();
				temp.close();
				remove("student.doc");
				rename("temp.doc","student.doc");
				break;}
			case 6:
				int rec2;
				cout<<"Enter no. of record:";
				cin>>rec2;
				file.open("student.doc",ios::in);
				file.seekg(0,ios::end);
				for(int j=0;j<rec2;j++){
					file.read((char*)&s,sizeof(s));
					s.display()	;
				}
				file.close();
				break;}
				}while(ch!=0);
							
					}
			
