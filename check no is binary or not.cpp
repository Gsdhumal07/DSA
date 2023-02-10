#include<iostream>
using namespace std;
class binary {
	string s;
public:
	void read(void);
	void check_bin(void);	
	void ones_compliment(void);
	void display(void);
	
};								

void binary::read(){
	cout<<"Enter the binary number :  ";
	cin>>s;
}

void binary::check_bin(){
	for(int i =0; i<s.length();i++){
		if (s.at(i)!='0' && s.at(i)!='1'){
			cout<<endl<<" you entered the wrong number";
			exit(0);
		}
	}
}

void binary::ones_compliment(){
	check_bin();
	for (int i =0; i<s.length();i++){
		if (s.at(i)=='0'){
			s.at(i)='1';
		}
		else{
			s.at(i)='0';
		}
	}
}

void binary::display(){
	cout<<endl<<"the binary number : "<<endl;
	for (int i =0; i<s.length() ; i++){
		cout<<s.at(i);
	}
}

int main(){
	binary b;
	b.read();
//	b.check_bin();
	b.display();
	b.ones_compliment();
	cout<<"\nthe ones compliment of the binary number : ";
	b.display();
	
	return 0;
}










