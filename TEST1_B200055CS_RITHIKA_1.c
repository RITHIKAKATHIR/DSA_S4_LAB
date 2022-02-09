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

int hash_func_h(char* w, int n){
    int len=0;
    len=strlen(w);
    int word;
    int hash_index=0;
   if(len==1){
       word=w[0];
       hash_index=(2*word)%n;
   }
   else{
      // printf("\n%s %c %c",w,w[len-2],w[len-1]);
       word=w[0]+w[1]+w[len-2]+w[len-1];
       hash_index=ceil((word/len)%n);

   }
    return hash_index;
}
int hash_func_g(char *w, int n){
    int len=0;
    len=strlen(w);
    int word;
    int hash_index=0;
    for(int i=0;i<=len;i++){
         word=word+w[i];
      }
   hash_index=floor((word/len)%n);
    return hash_index;
}

int length_of_linked_list(struct node* head){
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->node_pointer;
    }
    return count;
}

void insert_in_hash_table(struct head_pointer* LL,struct node* to_be_inserted){
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

void store_word(struct head_pointer* array_of_headpointer,char* str,int size){
    struct node* node_to_be_inserted;
    node_to_be_inserted=(struct node*)malloc(sizeof(struct node));
    //char op;
    char* word;
    int k1,k2;
    int len_chain=0;
    int len_chain_1=0;
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
     k1=hash_func_h(word,size);
     k2=hash_func_g(word,size);
     
     len_chain=length_of_linked_list(array_of_headpointer[k1].head);
     len_chain_1=length_of_linked_list(array_of_headpointer[k2].head);
     
     if(len_chain<len_chain_1){ 
         //printf("k1: %d",k1);
          node_to_be_inserted=create_node(word);
         insert_in_hash_table(array_of_headpointer+k1,node_to_be_inserted);
     }
     else if(len_chain_1<len_chain_1){
          //printf("k2: %d",k2);
          node_to_be_inserted=create_node(word);
         insert_in_hash_table(array_of_headpointer+k2,node_to_be_inserted);
     }
     else if (len_chain==len_chain_1){
          //printf("k1: %d",k1);
          node_to_be_inserted=create_node(word);
          insert_in_hash_table(array_of_headpointer+k1,node_to_be_inserted);
     }

    }
}

void print_linked_list(struct node* head){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%s ",temp->word);
        temp=temp->node_pointer;
    }
}

void print_table(struct head_pointer* array_of_headpointer,int size){
    for(int i=0;i<size;i++){
        //printf("%d\n",i);
        if(array_of_headpointer[i].head!=NULL){
            print_linked_list(array_of_headpointer[i].head);
        }
        else{
            printf("NULL");
        }
        printf("\n");
    }
}

int main(){
  int size;
     //scanf("%d",&size);
     char str[500];
     scanf("%d %[^\n]s",&size,str);
	//str=malloc(sizeof(char)*500);
    struct head_pointer* array_of_headpointer;
    array_of_headpointer=(struct head_pointer*)malloc(size*sizeof(struct head_pointer));
    array_of_headpointer=create_hash_table(size);
    /*struct node* node_to_be_inserted;
    node_to_be_inserted=(struct node*)malloc(sizeof(struct node));
    //char op;
    char* word;
    int k1,k2;
    int len_chain=0;
    int len_chain_1=0;
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
     k1=hash_func_h(word,size);
     k2=hash_func_g(word,size);
     
     len_chain=length_of_linked_list(array_of_headpointer[k1].head);
     len_chain_1=length_og_linked_list(array_of_headpointer[k2].head);
     
     if(len_chain<len_chain_1){
          node_to_be_inserted=create_node(word);
         insert_in_hash_table(array_of_headpointer[k1].head,word);
     }
     else if(len_chain_1<len_chain_1){
          node_to_be_inserted=create_node(word);
         insert_in_hash_table(array_of_headpointer[k2].head,word);
     }
     else if (len_chain==len_chain_1){
          node_to_be_inserted=create_node(word);
          insert_in_hash_table(array_of_headpointer[k1].head,word);
     }

    }*/
    store_word(array_of_headpointer,str,size);
    print_table(array_of_headpointer,size);
   
		
	return 0;
}
