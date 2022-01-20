#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node_bt{
    int value;
    struct node_bt* leftchild;
    struct node_bt* rightchild; 
};

struct queue_elements{
    struct node_bt* element;
    struct queue_elements* connection;
};

struct queue{
     struct queue_elements* head;
     struct queue_elements* tail;
};

struct tree{
    struct node_bt* root_tree;
};

struct queue* create_queue(){
   struct queue* que;
   que=(struct queue*)malloc(sizeof(struct queue));
   que->head=NULL;
   que->tail=NULL;
   return que;
} 

struct queue_elements* create_que_ele(struct node_bt* n){
    struct queue_elements* que_ele;
    que_ele=(struct queue_elements*)malloc(sizeof(struct queue_elements));
    que_ele->element=n;
    que_ele->connection=NULL;
    return que_ele;
}
void enqueue(struct queue* que, struct queue_elements* que_ele){
    if(que->head==NULL)
    {
        que->head=que_ele;
        que->tail=que_ele;
    }
    else {que->tail->connection=que_ele;
          que->tail=que_ele;
        }
}

struct queue_elements* dequeue(struct queue* que){
    if(que->head==NULL) return NULL;
    struct queue_elements* nodeinque;
    nodeinque=(struct queue_elements*)malloc(sizeof(struct queue_elements));
    nodeinque=que->head;
    if(que->head->connection)
    {
         que->head=que->head->connection;
    }
    else{
        que->head=NULL;
        que->tail=NULL;
    }

    return nodeinque;

}

struct node_bt* create_node(int k){
    struct node_bt* newnode;
    newnode=(struct node_bt*)malloc(sizeof(struct node_bt));
    if(newnode==NULL)
    exit(0);

    newnode->value=k;
    newnode->leftchild= NULL;
    newnode->rightchild=NULL;
    

   return newnode;
}

void insert(struct node_bt* root_tree,int k){
    struct node_bt* node=create_node(k);
    struct queue* que=create_queue();
    struct queue_elements* que_ele=create_que_ele(root_tree);
    enqueue(que,que_ele);
    while(que->head!=NULL)
    {
        struct queue_elements* del=dequeue(que);
        if(del->element->leftchild==NULL && del->element->rightchild){
            del->element->leftchild=node;
            return ;
        }
        else if(del->element->leftchild==NULL){
           del->element->leftchild=node;
            return ;
        }
        else if(del->element->rightchild==NULL){
            del->element->rightchild=node;
            return ;
        }
        else{
            struct queue_elements* new=create_que_ele(del->element->leftchild);
            enqueue(que,new);
            struct queue_elements* new1=create_que_ele(del->element->rightchild);
			enqueue(que,new1);
        }
    }
}


void paranthesis_Representation(struct node_bt* root_node){
 printf("( ");
 if(root_node!=NULL){
   printf("%d ",root_node->value); 
   paranthesis_Representation(root_node->leftchild);
   paranthesis_Representation(root_node->rightchild);
    }
  printf(") ");
}

 int main(){ 
    char ch;
    struct tree* tree_root;
    tree_root=(struct tree*)malloc(sizeof(struct tree));
    tree_root->root_tree=NULL;
    long n;

    while(1){
        scanf("%c",&ch);

        switch(ch){
           
           case 'i': 
                     scanf(" %d",&n);
                     if(tree_root->root_tree==NULL) tree_root->root_tree=create_node(n);
                     else insert(tree_root->root_tree,n);
                     break;

           case 'p':  paranthesis_Representation(tree_root->root_tree);
                      break;

           case 'e': return 1;

        }

    }
    return 0;

}
