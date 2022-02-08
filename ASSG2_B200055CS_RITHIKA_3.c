#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node_bst{
    char first_name[200];
    char last_name[200];
    int key;
    struct node_bst* leftchild;
    struct node_bst* rightchild;
    struct node_bst* parent;
};
struct tree{
     struct node_bst* root;
};

struct node_bst* create_node(char* fn, char* ln, int k){
    struct node_bst* newnode;
    newnode=(struct node_bst*)malloc(sizeof(struct node_bst));
    if(newnode==NULL)
    exit(0);
    strcpy(newnode->first_name,fn);
    strcpy(newnode->last_name,ln);
    newnode->key=k;
    newnode->leftchild= NULL;
    newnode->rightchild=NULL;
    newnode->parent=NULL;

   return newnode;
}
int hash_func(char* word){
   //str to ascii
   int a=0;
   for(int i=0;i<=strlen(word)&&word[i]!='\0';i++){
         a=a+word[i];
   }
 
  return a%128;
}
 void insert_func(struct node_bst* newnode,struct tree* tree){
    struct node_bst* y;
    struct node_bst* x;
    y=(struct node_bst*)malloc(sizeof(struct node_bst));
    x=(struct node_bst*)malloc(sizeof(struct node_bst));
    y=NULL;
    x=tree->root;
    while(x!=NULL){
        y=x;
        if(newnode->key<x->key)
            x=x->leftchild;
        else x=x->rightchild;
    }
    newnode->parent=y;
    if(y==NULL) tree->root=newnode;
    else if (newnode->key<y->key) y->leftchild=newnode;
    else y->rightchild=newnode;
}
/*int age_return(struct node_bst* node, char* word, char* word1){
    if(node==NULL) return 0;
    if(strcmp(node->first_name,word)==0 && strcmp(node->last_name,word1)==0) return node->key;
    else {

    }
}*/

struct node_bst* search(struct node_bst* tree,char* word,char* word1){
   if(tree==NULL || (strcmp(tree->first_name,word)==0 && strcmp(tree->last_name,word1)==0))
    return tree;
   struct node_bst* temp;
    temp=(struct node_bst*)malloc(sizeof(struct node_bst));
    temp=tree;
    struct node_bst* temp1;
    temp1=(struct node_bst*)malloc(sizeof(struct node_bst));
    temp1=search(temp->leftchild,word,word1);
    if(temp1==NULL)
    return search(temp->rightchild,word,word1);
    else return temp1;
}
/*void inorder(struct node_bst* node){
   if(node!=NULL)
   {inorder(node->leftchild);
   printf("%s %s %d\n",node->first_name,node->last_name,node->key);
   inorder(node->rightchild);
   }
 
}*/

/*void inorder_print(struct node_bst* node, struct node_bst* to_print_till){
 if(node!=NULL)
 {
      if(strcmp(node->first_name,to_print_till->first_name)!=0)
      { inorder_print(node->leftchild,to_print_till);
        if(strcmp(node->first_name,to_print_till->first_name)==0 && strcmp(node->last_name,to_print_till->last_name)==0) 
        {
         printf("%s %s %d\n",node->first_name,node->last_name,node->key);
         return ;
        }
         printf("%s %s %d\n",node->first_name,node->last_name,node->key);
         inorder_print(node->rightchild,to_print_till);
      }
  }
}*/
/*int printrelatives(struct node_bst* node, struct node_bst* to_print_till){
    if(node==NULL) return 0;
    else{
        if(strcmp(node->first_name,to_print_till->last_name)==0){
            printf("%s %s %d",node->first_name,node->last_name,node->key);
            return 1 ;
        }
        
        if(printrelatives(node->leftchild,to_print_till) || printrelatives(node->rightchild,to_print_till)){
                printf("%s %s %d",node->first_name,node->last_name,node->key);
                return 1;
        }

        }

        return 0;
}*/
void inorder_printrelatives(struct node_bst* tree,char* word,char* word1){
    if(tree==NULL) return ;
   // printf("\nin func:%s %s %d\n",tree->first_name,tree->last_name,tree->key);
    if(strcmp(tree->first_name,word)==0 && strcmp(tree->last_name,word1)==0){
       printf("%s %s %d\n",tree->first_name,tree->last_name,tree->key); 
       return ;
       }//return tree; 
    struct node_bst* parent;
    parent=(struct node_bst*)malloc(sizeof(struct node_bst));
    parent=tree;
    int flag=0;
    struct node_bst* current_node;
    current_node=search(tree->leftchild,word,word1);
    if(current_node==NULL) {
        flag=1;
        current_node=search(tree->rightchild,word,word1);
    }
    if(current_node!=NULL) printf("%s %s %d\n",parent->first_name,parent->last_name,parent->key);
    if(flag!=1) inorder_printrelatives(tree->leftchild,word,word1);
    inorder_printrelatives(tree->rightchild,word,word1);
}


int main()
{
    int size=128;
    struct tree* tree_array;
    tree_array=(struct tree*)malloc(size*sizeof(struct tree));
    for(int i=0;i<size;i++){
        tree_array[i].root=NULL;
    }
    char ch;
    char* word;
    word=(char*)malloc(size*sizeof(char));
    int age;
    char* word1;
    int hash_index;
    word1=(char*)malloc(size*sizeof(char));
     while (1)
	{
		scanf("%c",&ch);

		switch (ch)
		{
			case 'i':	scanf(" %s %s %d",word,word1,&age);
                        struct node_bst* newnode;
                        newnode=create_node(word,word1,age);
                        hash_index=hash_func(word1);
                        insert_func(newnode,&tree_array[hash_index]);
                        break;
			case 'p':   scanf(" %s %s",word,word1);
                        hash_index=hash_func(word1);
                        //printf("%d\n",hash_index);
                        struct node_bst* node_bst;
                        node_bst=(struct node_bst*)malloc(sizeof(struct node_bst));
                        node_bst=search(tree_array[hash_index].root,word,word1);
                        if(node_bst==NULL) printf("-1\n");
                        else{
                             inorder_printrelatives(tree_array[hash_index].root,word,word1);
                             //inorder_print(tree_array[hash_index].root,node_bst);
                        }
                        break;

			case 't':	return 1;

		}
	}

 return 0;
}


