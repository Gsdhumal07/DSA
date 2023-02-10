#include<iostream>

// when you are accepting values from the user the values need to convert into radiens


using namespace std;
int v;
void mul(int output[3][10], int t[3][3], int input[3][10])  //call by value
{
	for(int i=0;i<3;i++){
		for (int j=0;j<v;j++){
			output[i][j]=0;
			for(int k=0;k<3;k++){
				output[i][j]+=t[i][k]*input[k][j];
			}
		}
	}
}

int main(){
	int input[3][10];
	int v;
	
	
	
	printf("\nVertices ");
	scanf("%d",&v);for (int i=0;i<v;i++){
		printf("\nX-Co-ordinates : ");
		scanf("%d",&input[0][i]);
		printf("\nY-Co-ordinates : ");
		scanf("%d",&input[1][i]);
		input[2][i]=1;
		
	}
//	for(int i=0;i<3;i++){
//		for (int j=0;j<v;j++){
//			printf("%d\t",input[i][j]);
//		}
//		printf("\n");
//	}
	
	int t[3][3];
	int tx ,ty;
	printf("\ntx : ");
	scanf("%d",&tx);
	printf("\nty : ");
	scanf("%d",&ty);
	
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if(i==j){
				t[i][j]=1;
			}
			else {
				t[i][j]=0;
			}
		}
	}
	t[0][2]=tx;
	t[1][2]=ty;
	for(int i=0;i<3;i++){
		for (int j=0;j<v;j++){
			printf("%d\t",input[i][j]);
		}
		printf("\n");
	}
	
	int output[3][10];
	mul(output, t ,input);
}
