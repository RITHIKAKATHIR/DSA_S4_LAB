#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int isempty(int* top){
    if(*top==-1) return 1;
    else return -1;
}
int isfull(int* n,int* top){
    if(*top==(*n-1)) return 1;
    else return -1;
}
void pop(int* n, int* top, int* A){
  int p;
  p=isempty(top);
  if(p==1) printf("%d\n",-1);
  else{
      (*top)=(*top)-1;
      printf("%d\n",A[*(top)+1]);
  }
}
int* push(int* n, int* top, int* A, int* num){
    int p;
    p=isfull(n,top);
    if(p==-1){
        *top=*top+1;
          A[*top]=*num;
          return A;
    }
    else{printf("%d\n",p);
        int* B;
        //printf("%d",*n);
        int sizeb;
        sizeb=(*n)*2;
        B=(int*)malloc(sizeb*sizeof(int));
        int k=0;
        for(int i=0;i<=(*top);i++)
        {
            B[k++]=A[i];
        }
       
       *n=sizeb;
       A=(int*)realloc(A,sizeb*sizeof(int));
       A=B;
       /*if(A==NULL) printf("joj");
       else printf("else");
       for(int i=0;i<sizeb;i++)
       {
           printf("%d",i);
           printf("num:%d",A[i]);
       }*/
         if(*top!=(*n-1))
         {
          *top=*top+1;
          A[*top]=*num;  
         }  
       /* for(int i=0;i<sizeb;i++){
           printf(" %d ",i);
           printf(" num:%d ",A[i]);
       }
       printf("%d",*top);
       printf("%d",*n);*/

        
    }


    /*printf("%d",*top);
    printf("%d",*n);

      for(int i=0;i<*n;i++){
           printf(" %d ",i);
           printf(" num:%d ",A[i]);
       }*/
       return A;

}


int main()
{   
    int* array;
    
    int n;
   
    int top;
    
    top=-1;
   
    //printf("%d",top);
    
    scanf("%d",&n);
  
    array=(int*)malloc(n*sizeof(int));
    char ch;
    int num;
    
  
    while(1)
    {
         scanf("%c",&ch);

         switch(ch)
         {
            case 'i': 
                     scanf(" %d",&num);
                     array=push(&n,&top,array,&num);
                     /*printf("\n\ninmain");
                       for(int i=0;i<n;i++){
                       printf(" %d ",i);
                       printf(" num:%d ",array[i]);
                     }*/
                     break;
                     
            case 'd': 
                     pop(&n,&top,array);
                     break;


             case 't': return 1;
        
       }

    }

    return 0;
}