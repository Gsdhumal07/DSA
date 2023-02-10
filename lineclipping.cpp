#include<iostream>
using namespace std;

struct lineclipping {
	int x,y ;
	int binary[4];
	int outcode[4];
} p1 , p2;

void calculate(struct lineclipping *p , int Xmin ,int Ymin,int Xmax ,int Ymax){
	
	for (int i=0;i<4;i++){
		p->binary[4];
	}
	if(p->x<Xmin){
		p->binary[3]=1;
	}
	if(p->x>Xmax){
		p->binary[2]=1;
	}
	if(p->y<Ymin){
		p->binary[1]=1;
	}
	if (p->y>Ymax){
		p->binary[0]=1;
	}
	
}

void check(){
	int flag;
	for (int i=0 ; i<4;i++){
		if(p1.binary[i]==0 &p2.binary[i]==0){
			flag=0;
		}
		else {
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"Values are Acceptable  ";
	}
	else{
		cout<<"Values are partially accepted or Rejected ";
	}
}

void find_intersection( struct lineclipping *p, int x1 , int y1 ,int Xmin ,int Ymin,int Xmax ,int Ymax , int m){
	int x,y;
	if(p->outcode[0]==1){
		
		cout<<"Cut left boundary ";
		x=Xmin;
		y=y1+m*(x-x1);
		cout<<"Points are ("<<x<<" "<<y<<")";
	}
	if(p->outcode[1]==1){
		cout<<"Cut lower boundary ";
		y=Ymin;
		x=x1+y-y1/m;
		cout<<"Points are ("<<x<<" "<<y<<")";
	}
	if (p->outcode[2]==1){
		cout<<"cut right boundary";
		x=Xmax;
		y=y1+m*(x-x1);
		cout<<"Points are ("<<x<<" "<<y<<")";
	}
	if(p->outcode[3]==1){
		cout<<"Cut the Upper boundary";
		y=Ymax;
		x=x1+(y-y1)/m;
		cout<<"Points are ("<<x<<" "<<y<<")";
	}
	
}

void calculate_outcode(){
	find_intersection(&p1);
	find_intersection(&p2);
	
	
}

void find(){
	int outcode[4] ,flag;
	for(int i=0;i<4;i++){
		outcode[i]=p1.binary[i] && p2.binary[i];
		if(outcode[i]==1){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"--Rejected--";
	}
	else {
		calculate();
	}
}

int main(){
	
}
