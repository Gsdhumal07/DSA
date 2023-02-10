

#include <stdio.h>
#include<stdlib.h>

int Round(float a){
    return (int)(a +0.5);
}

void DDAline(int x1 ,int y1 ,int x2, int y2){
    int dx,dy ,steps;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        steps=abs(dx);
    }
    else{
        steps=abs(dy);
    }
    float xincrement , yincrement;
    xincrement=(float)(dx)/steps;
    yincrement=(float)(dy)/steps;
    
    float x=x1,y=y1;
    
    
    for(int i=0;i<steps;i++){
        x=x+xincrement;
        y=y+yincrement;
        printf("%f\t%f\t%d\t%d\n",x,y,Round(x),Round(y));
    }
}
int main()
{
    int a,b,c,d;
    printf("Enter x1 y1 : ");
    scanf("%d,%d ",&a,&b);
    printf("Enter x2 y2 : ");
    scanf("%d %d ",&c,&d);
    DDAline(a,b,c,d);
    
    return 0;
}

