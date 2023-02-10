#include <stdio.h>
#include<stdlib.h>
struct student{
    char name[12];
    int age;
}p1[10];

void getdata(int i){
    printf("\n Enter your name:");
    scanf("%s",p1[i].name);
    printf("\n Enter your age : ");
    scanf("%d",&p1[i].age);
}
void display(int i){
    printf("\n Name ");
    printf("  %s ",p1[i].name);
    printf(" \n age ");
    printf("  %d ",p1[i].age);
    printf("\n *************");
    
}

int main()
{int no;
int ch;
printf("\n enter intial no. of records: ");
scanf("%d",&no);
for(int i=0;i<no;i++){getdata(i);};
do
{printf("\n 1.display\n 2.modify""\n 3.search\n 4.delete\n 5.add  \n 0.exit");
printf("\n enter your choice: ");
scanf("%d",&ch);
switch(ch){
		case 1:for(int i=0;i<no;i++){display(i);};
			break;
		case 2:printf("enter the position you want to modify: ");
		       int mod;
		       scanf("%d",&mod);
		       getdata(mod - 1);
		       break;
		case 3:printf("enter the position you want to search: ");
		       int srch;
		       scanf("%d",&srch);
		       display(srch - 1);
		       break;
		case 4:printf("enter the position you want to delete: ");
		       int del;
		       scanf("%d",&del);
		       for(int i= del-1;i<no;i++){
		       	p1[i]=p1[i+1];
			   }
			   no=no-1;
		       break;
		case 5:printf("enter the position where you want to add: ");
		       int add;
		       scanf("%d",&add);
		       for(int i= no;i>add-1;i--){
		       	p1[i]=p1[i-1];
			   }
			   getdata(add-1);
			   no=no+1;
			   break;
		
		default:printf("\n wrong choice please enter correct one");
	}}while(ch!=0);
	
	return 0;
}

