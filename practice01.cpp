#include <stdio.h>
#include<iostream>
using namespace std;

void update() {
    int num1 ,num2;
    int *a, *b;
    a=&num1;
    b=&num2;
    int sum;
	*a+*b=&sum;
    int sub=*a-*b;
    cout<<sum;
    // Complee this function    
}

int main() {
    int a, b;
    cin>>a>>b;
    
    update();
    
    
    

    return 0;
}
