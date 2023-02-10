#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
   private :
   
  	int items[SIZE], front, rear;

   public:
  	Queue() {
    front = -1;
    rear = -1;
  }
  
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  
  void enqueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
      cout << endl
         << "Inserted " << element << endl;
    }
  }
  
  int dequeue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
  
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display() {

    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      
      cout << endl
         << "Items -> "<<" ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i]<<" ";
      cout << items[i]<<" .;''";
      
        
    }
  }
};


int main(){
	int ch;
	Queue q;
	
	do{
		cout<<"\n01.Enqueue the elements : "<<"\n02.Dequeue the elements : "<<"\n03.Display"<<"\n00.EXIT : "<<endl;
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 01:
				int n;
				int arr[5];
				cout<<"enter the element that u want to add in Queue : ";
				cin>>n;
				q.enqueue(n);
//				display();
				break;
				
			case 02:
				q.dequeue();
//				display();
				break;
				
			case 03:
				q.display();
					
		}
	}while(ch!=0);
	
}
