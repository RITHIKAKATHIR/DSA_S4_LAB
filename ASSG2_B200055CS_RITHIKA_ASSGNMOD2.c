#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node{
  char *word; // word to be store
  struct node *node_pointer; //pointer to the next node
};

struct head_pointer{
    struct node* head;
};

struct head_pointer* create_hash_table(int size){
    struct head_pointer* LL;
    LL=(struct head_pointer*)malloc(size*sizeof(struct head_pointer));
    if(LL==NULL)
        exit(0);
    for(int i=0;i<size;i++){
        LL[i].head=NULL;
    }

    return LL;
}

int hash_func(char* name, int size){
   int sum=0;
   int i=0;
   int len=strlen(name);
   int look;
   for(int i=0;i<=len;i++){
       look=name[i];
       if(name[i]>=65 && name[i]<=90)
           look=look-64;
       if(name[i]>=97 && name[i]<=122)
           look=look-96;

        sum=sum+(look*pow(3,i));

    }
    int hash;
    hash=sum%size;
    return hash;
        
}

void insert_function(struct head_pointer* LL,char* word,int size){
    int index=hash_func(word,size);
   // printf("\nindex: %d\n",index);
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        exit(0);
    newnode->word=word;
    newnode->node_pointer=NULL;
    if(LL[index].head==NULL){
        LL[index].head=newnode;
    }
    else{
        struct node* temp;
        temp=LL[index].head;
        while(temp->node_pointer!=NULL){
            temp=temp->node_pointer;
        }
        temp->node_pointer=newnode;
    }
}

int search_table(struct head_pointer* LL,char* word,int size){
    int index=hash_func(word,size);
    struct node* temp;
    temp=LL[index].head;
    while(temp!=NULL){
        if(strcmp(temp->word,word)==0){
            return 1;
        }
        temp=temp->node_pointer;
    }
    return 0;
}

void delete_table_ele(struct head_pointer* LL,char* word,int size){
    int index=hash_func(word,size);
    struct node* temp;
    temp=LL[index].head;
    if(strcmp(temp->word,word)==0){
        LL[index].head=temp->node_pointer;
        free(temp);
        return;
    }
    while(temp->node_pointer!=NULL){
        if(strcmp(temp->node_pointer->word,word)==0){
            struct node* temp1;
            temp1=temp->node_pointer;
            temp->node_pointer=temp1->node_pointer;
            free(temp1);
            return;
        }
        temp=temp->node_pointer;
    }
}

int check_one(struct node* node){
    if(node->node_pointer!=NULL)
        return 1;
    else
        return 0;
}

void check_onetoone(struct head_pointer* LL,int size){
    int flag=0;
     for(int i=0;i<size;i++)
     { //printf("hey");
       //node=LL[i].head;
        if(LL[i].head==NULL)
       {  continue;
       }
       if(LL[i].head->node_pointer!=NULL)
       {    flag=1;
            printf("%d\n",-1);
            
            
       }
    }
    if(flag==0)
    printf("%d\n",1);
}


int main(){
    int size;
     scanf("%d",&size);
     char str[500];
	//str=malloc(sizeof(char)*500);
    struct head_pointer* array_of_headpointer;
    array_of_headpointer=(struct head_pointer*)malloc(size*sizeof(struct head_pointer));
    struct node* node_to_be_inserted;
    node_to_be_inserted=(struct node*)malloc(sizeof(struct node));
    array_of_headpointer=create_hash_table(size);
    char op;
    int res;
	scanf("%c",&op);
	while(op!='t')
	{ 	switch(op)
		{
		 case 'i': scanf(" %s",str);
		 	       insert_function(array_of_headpointer,str,size);
		 	       break;
		 case 'p': check_onetoone(array_of_headpointer,size);
		 	       break;
		 case 'd': scanf(" %s",str);
                   res=search_table(array_of_headpointer,str,size);
                   if(res==1)
		           delete_table_ele(array_of_headpointer,str,size);
		 	       break;

          
		}
		scanf("%c",&op);
	}
		
	return 0;
}
