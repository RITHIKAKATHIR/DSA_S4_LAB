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

struct node* create_node(char* k){
    struct node* newnode ;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->word=(char*)malloc(sizeof(char)*strlen(k));
    if(newnode==NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    strcpy(newnode->word,k);
    newnode->node_pointer=NULL;
    return newnode;
}

int chaining_hashing(char* str,int k){
    int len=0;
    len=strlen(str);
    int hash_index=0;
    hash_index=(len*len)%k;
    return hash_index;
}

int list_search(struct head_pointer* L,char* k)
{ 
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=L->head;
  
  while(temp!=NULL && strcmp(temp->word,k)!=0)
    temp=temp->node_pointer;
    
 if(temp==NULL) return 1;
  return 0;    
    
}

void LIST_INSERT_FRONT(struct head_pointer* LL,char* key){
    //struct node* checker;
    //checker=(struct node*)malloc(sizeof(struct node));
    //checker=list_search(LL,key);
    //if(checker!=NULL) return;
    struct node* to_be_inserted;
    to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);
    to_be_inserted=create_node(key);
    if(LL->head==NULL)
    {
        LL->head=to_be_inserted;
        
    }
    else
    {
        to_be_inserted->node_pointer=LL->head;
        LL->head=to_be_inserted;
    }

}

void LIST_INSERT_TAIL(struct head_pointer* LL,struct node* to_be_inserted){
   /*struct node* to_be_inserted;
   to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);*/
   struct node* temp;
   temp=LL->head;
    //to_be_inserted=create_node(key);
    if(LL->head==NULL)
       LL->head=to_be_inserted;
    else
    {
        while(temp->node_pointer!=NULL)
         temp=temp->node_pointer;

    temp->node_pointer=to_be_inserted;
    }
}

void PRINT_LIST(struct head_pointer* LL){
  struct node* selected=LL->head; 
  if(LL->head==NULL) {
      printf("null\n");
      return ;
  }
  printf("%s",selected->word); 
  selected=selected->node_pointer;
  while(selected!=NULL) {
       printf("-%s",selected->word); 
       selected=selected->node_pointer; 
       }
       printf("\n");
 }

int main(){
    int size;
  char str[500];
	//str=malloc(sizeof(char)*500);
    struct head_pointer* array_of_headpointer;
  array_of_headpointer=(struct head_pointer*)malloc(size*sizeof(struct head_pointer));
   struct node* node_to_be_inserted;
  node_to_be_inserted=(struct node*)malloc(sizeof(struct node));
  
 scanf("%d %[^\n]s",&size,str);
	//scanf("%s",str);
    int k=0;
  //printf("%s\n",str);
    array_of_headpointer=create_hash_table(size);
    char* word;
    word=(char*)malloc(sizeof(char)*200);
    int i=0;
    int p=0;
    while(str[i]!='\0' && str[i]!='\n' && i<=strlen(str))
    {
    //printf("inloop");
    while(str[i]!='\0' && str[i]!='\n' && i<=strlen(str))
    {
        if(str[i]==' ')
        {
            word[p]='\0';
            break;
        }
        word[p++]=str[i];
        i++;
    }
    if(str[i]=='\0' || str[i]=='\n'){
        //printf("in inside if loop");
        word[p]='\0';
    }
      i=i+1;
      p=0;
      //printf("%s ",word);
      k=chaining_hashing(word,size);
      //printf("%d\n",k);
      if(list_search(array_of_headpointer+k,word)==1)
      {
      node_to_be_inserted=create_node(word);
      //printf("word in struct: %s",node_to_be_inserted->word);
      LIST_INSERT_TAIL(array_of_headpointer+k,node_to_be_inserted);
      //printf("\n");
     //printf("entered");
      }

  }
  //printf("\noutside");
  for(int i=0;i<size;i++){
      printf("%d:",i);
      /*if((array_of_headpointer+i)==NULL){
              printf("null\n");
			  continue;
      }*/
    
     PRINT_LIST(array_of_headpointer+i);

     // printf("\n");

 }


  return 0;
}