#include <iostream>
using namespace std;

class circularqueue {
	private:
		
		int rear;
		int front;
		int arr[];
	
	public:
	circularqueue()
	{
		front = -1;
		rear = -1;
		cout<<"Enter the number of element you want to add in queue : ";
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			arr[i]=0;
		}	
	}
	
	bool isempty()
	{
		if(front==-1&&rear==-1)
		 return true;
		else
		 return false;
	}
	
	bool isfull()
	{
		if((rear+1)%5==front)
		 return true;
		else
		 return false;
	}
	
	void enqueue(int val)
	{
    	if(isfull())
	    {
	    	cout<<"queue full"<<endl;
	    	return;
		}
		else if(isempty())
		{
			rear=0;
			front=0;
			arr[rear]=val;
		}
		else
		{
			rear=(rear+1)%5;
			arr[rear]=val;
		}		
	}
	
	int dequeue(int val)
	{
		int x;
      	if(isempty())
	    {
	    	cout<<"queue empty"<<endl;
	    	return x;
	    }
	    
		else if(front==rear)
	    {
	        x= arr[front];
			arr[front]=0;
			rear=-1;
			front=-1;
			return x;	
		}
		
		else
		{
		    x= arr[front];
			arr[front]=0;
			front=(front+1)%5;
			return x;	
		}
	}
	
	int display()
	{  
	   for(int i=0;i<5;i++)
	   {
	   	cout<<arr[i]<<" ";
	   }	
	}	
};


int main()
{
	circularqueue q1;
	int ch,val,n;
	do 
	{
		cout<<"\n enter the choice"<<endl;
		cout<<"\n 1.enqueue \n 2.dequeue \n 3.display"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				 cout<<"How many values you want to enqueue in queue : ";
			    cin>>n;
			    for (int i=0;i<n;i++){
			        cout<<"enter the "<<i<<" value : ";
			        cin>>val;
					q1.enqueue(val);
				}      
				break;
			
			case 2: 
				cout<<"dequeued"<<q1.dequeue(val)<<endl;
				break;	
				
			case 3:
				cout<<"values are"<<endl;
			    q1.display();
				break;
			
			default:
				cout<<"invalid"<<endl;
			    break;		
		}
	}
	while(ch!=0);
	return 0;
}
