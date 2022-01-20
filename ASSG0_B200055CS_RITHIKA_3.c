#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct top{
    struct node* top_pointer;
};
struct node* create_node(int k){
    struct node* newnode ;        //creation of new node
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
     exit(0);
    newnode->data=k;
    newnode->next=NULL;
    return newnode;
}
void push(struct top* top, struct node* nodenow){
    if(top->top_pointer==NULL){         //checking if top is pointing to null
        top->top_pointer=nodenow;       //if top is pointing to null, assigning new node to top
    }
    else{
        struct node* to_push;
        to_push=(struct node*)malloc(sizeof(struct node));
        to_push=top->top_pointer;

        while(to_push->next!=NULL)
           to_push=to_push->next;

           to_push->next=nodenow;
    }

 
    }

/*void print(struct top* top){
        struct node* to_push;
        to_push=(struct node*)malloc(sizeof(struct node));
        to_push=top->top_pointer;
        while(to_push!=NULL){
            printf("%d ",to_push->data);
            to_push=to_push->next;
        }
}*/

void klast(struct top* top, int k){
  struct node* to_push;
  to_push=(struct node*)malloc(sizeof(struct node));
        to_push=top->top_pointer;
        int num=0;
        while(to_push!=NULL)
        {
            num=num+1;
           to_push=to_push->next;
        }
        //printf("num is: %d",num);
        if(k>num)
        {  printf("-1");
            return ;
        }

     int place;
     place=num-k+1;
     int j=1;
     to_push=top->top_pointer;
     while(j<place && to_push!=NULL)
     {
       to_push=to_push->next;
       j++;
     }

     printf("%d",to_push->data);
 }


int main(){
    
    struct top* top_s;  //creation of top
    top_s=(struct top*)malloc(sizeof(struct top));
    top_s->top_pointer=NULL;
     int num;
     struct node* temp;
     temp=(struct node*)malloc(sizeof(struct node));
     char ch_1;
     ch_1='f';
     while((ch_1!='\n' && ch_1==' ')||ch_1=='f'){
         ch_1='s';
        scanf("%d",&num);
        scanf("%c",&ch_1);
        temp=create_node(num);
        push(top_s,temp);
    }

   /* printf("out of the func");
    print(top_s);*/

    int k;
    scanf("%d",&k);

    klast(top_s,k);
   
   return 0;

}