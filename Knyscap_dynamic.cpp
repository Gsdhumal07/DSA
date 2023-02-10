#include<iostream>
using namespace std;

int main(){
	int p[5]={0,1,2,5,6};
	int wt[5]={0,2,3,4,5};
	
	int m =8, n=4;
	
	int mat[5][8];
	
	for(int i=0;i<=n;i++){
		
		for(int j=0;j<=m;j++){
			
			if(i==0 || j==0){
				mat[i][j]=0;
			}
			else if(wt[i]<=j){
				int a=(p[i]+mat[i-1][j-wt[i]] );
				int b=( mat[i-1][j]);
				if(a>b){
					mat[i][j]=a;
				}
				else{
					mat[i][j]=b;
				}
			}
			else{
				mat[i][j]=mat[i-1][j];
			}
		}
//		cout<<mat[i][j];
	}
	for(int i=0;i<=n;i++){
		cout<<"\n";
		for(int j=0;j<=m;j++){
			cout<<mat[i][j]<<"\t";
		}
	}
	cout<<"\n";
	int i=n+1 , j=m+1;
	while(i>0 && j>0){
		if(mat[i][j]==mat[i-1][j]){
			cout<<i<<" = 0 \t";
			i--;
		}
		else{
			cout<<i<<" = 1 \t";
			i--;
			j=j-wt[i];
		}
	}
	
}
