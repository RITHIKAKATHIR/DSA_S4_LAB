#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int queuefull(int* front, int* rear,int*n){
  if(*rear==*n-1) return 1;
  else return -1;
}
int queueempty(int* front,int* rear){
    if(*front==-1 || *front>*rear) return 1;
    else return -1;
}
void enqueue(int* que,int* front, int* rear, int num, int* n)
{
    int p;
    p=queuefull(front,rear,n);
    if(p==1) printf("%d\n",1);
    else{ 
          if(*front==-1) *front=*front+1;
         *rear=*rear+1;
          que[*rear]=num;
         
    }
}
void dequeue(int* que,int* front, int* rear,int* n){
    int p;
    p=queueempty(front,rear);
    printf("\nfronttt:");
    printf("%d %d %d",*front,*rear,p);
   
    if(p==1) printf("%d\n",p);
    else{
        
        printf("%d\n",que[*front]);
        *front=*front+1;
    }
}

int main(){
    int* que;
    int front=-1;
    int rear=-1;
    int n;
    scanf("%d",&n);
    que=(int*)malloc(n*sizeof(int));
    char ch;
    int num;
    int w;
    while(1){
        scanf("%c",&ch);
        switch(ch){
                          case 'i': scanf(" %d",&num);
                                    enqueue(que,&front,&rear,num,&n);
                                    break;
                          case 'd': dequeue(que,&front,&rear,&n);
                                    break;
                          case 'f': w=queuefull(&front,&rear,&n);
                                    if(w==1) printf("%d\n",1);
                                    else printf("%d\n",-1);
                                    break;
                         case 'e':  
                                    w=queueempty(&front,&rear);
                                    if(w==1) printf("1\n");
                                    if(w==-1) printf("-1\n");
                                    break;

                         case 't': return 1;
                  }

    }
    return 0;

}