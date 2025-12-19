#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Point{
int x;
int y;};

int main(){

int n=20;
struct Point points[n];
struct Point temp;
srand(time(NULL));

for (int i=0; i<n ; i++){
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;
}

for (int i=0;i<n;i++){printf("%d  %d \n",points[i].x,points[i].y);}
printf("New \n");
for(int i=0;i<=n-2;i++){
    for(int j=0;j<=n-2-i;j++){
        if(points[j].x>points[j+1].x){
            temp=points[j];
            points[j]=points[j+1];
            points[j]=temp;
        }
    }
}
for (int i=0;i<n;i++){printf("%d  %d \n",points[i].x,points[i].y);}


return 0;
}
