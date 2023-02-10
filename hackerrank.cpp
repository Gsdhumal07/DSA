#include <iostream>
#include <sstream>
#include<string.h>
using namespace std;

class Student {

  int age , standard; 
  string first_name , last_name;
    public:
    void set_age(int a){
        a=age;
    }  
    int get_age(){
        cout<< age;
    }
    void set_first_name(string name1){
        name1=first_name;
    }
    string get_first_name(){
        cout<< first_name;
    }
    void set_last_name(string str){
        str=last_name;
    }
    string get_last_name(){
        cout<< last_name;
    }
    void set_standard(int a){
        standard=a;
    }
    int get_standard(){
        cout<< standard;
    }
    
    
    
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    st.get_age();
    cout<<"\n";
    st.get_last_name();cout << ", "; st.get_first_name() ;cout<<"\n";
    st.get_standard();
    cout << "\n";
    // cout << st.to_string();
    
    return 0;
}

