#include<iostream>
#include<string>
using namespace std;

struct student{
	string name;
	int sgpa;
	int roll_no;
};

void add_data(int i,struct student a[]){
	cout<<endl<<"Enter the name of the student :";
	cin>>a[i].name;
	cout<<"Enter the ROLL_No. of the "<<a[i].name<<" :";
	cin>>a[i].roll_no;
	cout<<"Enter the sgpa  of the "<<a[i].name<<" :";
	cin>>a[i].sgpa;
}

void display(int i ,struct student a[]){
	cout<<endl<<"Name of the student : "<<a[i].name<<"\t"<<endl;
	cout<<a[i].name<<" Roll_No. is : "<<a[i].roll_no<<"\t"<<endl;
	cout<<a[i].name<<" has sgpa : "<<a[i].sgpa<<"\t"<<endl;
}

void search(int n ,struct student a[], string names[]){
	int sgpa;
	int temp =0;
	cout<<"\nEnter the sgpa you want to search : ";
	cin>>sgpa;
	for (int i =0; i<n ; i++){
		if (sgpa==a[i].sgpa){
			names[i]=a[i].name;
			temp=1;
			cout<<names[i]<<" ";
//			cout<<endl;
		}

	}
	if (temp==0){
		
		cout<<" Sry you entered sgpa is not in our database"<<endl;
	}	
	else{
//		cout<<" these are the students ";
	}		
	
}



void insertionsort(int n , struct student a[] ,string arnList[])

{
  for (int i=0;i<n ;i++){
  	
  	arnList[i]=a[i].name;
  }		
  
//  int nLength=9;
  string nTemp;
  int i;
//  string arnList;

  for (i = 1; i < n; ++i)
  {
    //the new value to be inserted into a temporary location 
    nTemp = a[i].name;
    // k is the index of the number to the left of the iCv.
    int k;

    for (k = i-1; k >= 0 && (a[k].name > nTemp); k--)
    {
      a[k+1].name = a[k].name;
    }
    a[k+1].name = nTemp;
  }
  for(i=0;i<n;i++) cout<<a[i].name<<" , ";
  cout<<endl;

}

void namesearch(int n,string nam,struct student a[]){
	for(int i=0;i<n;i++){
		if(nam==a[i].name){
			cout<<"the sgpa of the ",a[i].name," is : ",a[i].sgpa;
			cout<<"the roll_no of the ",a[i].name," is : ",a[i].roll_no;
		}
		else{
			cout<<"Wrong Entry please try again :";
		}
	}
}



void sortingrollno(int n , struct student a[] ,int numbers[]){
	int i , j ;
	int temp;
	int pass = 0;
//	int numbers[n];
	for (int i=0;i<n;i++){
		
		a[i].roll_no=numbers[i];
//		cout<<numbers[i]<<" ";
	}
//	cout<<"the array of roll no. "<<endl;
//	for (int i = 0 ; i< n ;i++){
//		cout<<numbers[i]<<" ";
		
//	}
for (int i =0 ; i< n ; i++){
	for(int j =i+1 ;j<n ; j++){
		if (numbers[j]<numbers[i]){
			temp=numbers[i];
			numbers[i]=numbers[j];
			numbers[j]=temp;
		}
	}
pass++;	
}
cout<<endl;
cout<<"\n The sorted arrey of roll no. is :"<<endl;
for(int i =0 ; i< n;i++){
	cout<<numbers[i]<<"\t";
//	cout<<endl;
}

}

void sortingsgpa(int n , struct student a[] ){
	int i , j ;
	string swap;
	int pass = 0;
	string name[n];
	int numbers[n];
	for (int i=1;i<n;i++){
		if(a[i].sgpa>a[i-1].sgpa){
			cout<<a[i].name<<endl;
		}
		
		
//		cout<<numbers[i]<<" ";
	}
	
//	
	
for (int i =0 ; i< n ; i++){
	for(int j =i+1 ;j<n ; j++){
		if (numbers[j]<numbers[i]){
			swap=name[i];
			name[i]=name[j];
			name[j]=swap;
		}
	}
pass++;	
}
cout<<endl;
cout<<"\n The Toppers of the class are :"<<endl;
for(int i =0 ; i< n ; i++){
	cout<<name[n-i]<<"\t";
//	cout<<endl;
}
}

void roll_no_list(int n , int numbers[] , struct student a[]){
	for (int i =0; i<n ; i++){
		numbers[i]= a[i].roll_no;
		cout<<numbers[i]<<" , ";
//		cout<<endl;
	}
}

void top10(struct student a[] , int p , int q){
	struct student temp;
	if (p<q){
		struct student pivot=a[p];
		int b=p+1;
		int r=q;
		while(b<r){
			while(a[b].sgpa<=pivot.sgpa&&b<r){
				b++;
			}
			while(a[r].sgpa>pivot.sgpa&&r>0){
				r--;
			}
			if (b<r){
				temp=a[p];
				a[b]=a[r];
				a[r]=temp;
			}
		}
		if(a[p].sgpa>=a[r].sgpa){
			temp=a[p];
			a[p]=a[r];
			a[r]=temp;
			top10(a,p,r-1);
			top10(a,r+1,q);
		}
	}
}



void binarysearch(int n ,struct student a[],int element ){
	
//	for (int i=0;i<n;i++){
//		a[i].sgpa=numbers[i];
////		cout<<numbers[i];
//	}
	int low , mid , high ;
	low=0;
	high=n-1;
	cout<<"\nEnter the sgpa : ";
	cin>>element;
	while(low <=high){
		mid=(low+high)/2;
		if (a[mid].sgpa==element){
//			return mid;
			cout<<a[mid].name;
		}
		if (a[mid].sgpa<element){
			low=mid+1;
		}
		else{
			high=mid-1;
		}				
	}
	cout<<endl;
}



int main(){
	int n , p;
	struct student a[15];
	cout<<"\nEnter the no.of students that you want to add in your Database : ";
	cin>>n;
	string names[n];
	int numbers[n];
	int element;
	string arnList[n];
	int data[n];
	for (int i=0 ; i<n ; i++){
		data[i]=a[i].sgpa;
	}
	do{
		cout<<"\n01.Add data \n02.display data \n03.Search sgpa \n04.list of roll no. \n05.Sorted list of roll no . \n06.Search student by sgpa.  \n07.Arrange the student alphabetically  \n08.Toppers of the class \n09.Search by Name \n00.Exit"<<endl<<endl ;
		cout<<endl<<"Enter your choice :";
		cin>>p;
		switch(p){
			case 1:
				for (int i =0; i<n ;i++){
					add_data(i,a);
					
				}
				break;
			case 2:
				for (int i =0 ; i<n ; i++){
					display(i,a);
				}
				break;
			case 3:
				search(n,a,names);
				break;
			
			case 4:
				roll_no_list(n,numbers,a);
				break;
	
			case 5:
				sortingrollno(n ,a ,numbers);
				break;
				
			case 6:binarysearch(n , a , element);
				break;
					
			case 7:
				insertionsort(n , a ,arnList);
				break;
				
			case 8:
				sortingsgpa(n,a);
				break;
			case 9:
				string nam;
				cout<<"enter the name of Student : ";
				cin>>nam;
				namesearch(n,nam,a);	

				
//			default:
				cout<<endl<<"-------";}}
			while (p!=0);
		
}
