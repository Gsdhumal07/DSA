#include <iostream>
using namespace std ;
/* factorial of any number is just like 
   
   n! = n * (n-1)!....so on */
   
int factorial(int n )
{
	if (n<=1){
		return 1;
	}
	return n * factorial(n-1);
}

int fibonacii(int n){
	if (n<2){
		return 1;
	}

//	for (int i =1;i<n;i++){
//		i= (i-1) +(i-2);
//	for (int i=1;i<n;i++){
//		return  fibonacii(i-2)+fibonacii(i-1); 
//	}
	return  fibonacii(n-2)+fibonacii(n-1);
}
int main(){
	int a;
	cout<<"Enter the number  ";
	cin>>a;
	cout<<"the  of the number is  "<<fibonacii(a);
	
	return 0;
}


#include <iostream>
using namespace std;
void fib(int num) {
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < num; i++) {
      cout << x << " ";
      z = x + y;
      x = y;
      y = z;
   }
}
int main() {
   int num;
   cout << "Enter the number : ";
   cin >> num;
   cout << "\nThe fibonacci series : " ;
   fib(num);
   return 0;
}
