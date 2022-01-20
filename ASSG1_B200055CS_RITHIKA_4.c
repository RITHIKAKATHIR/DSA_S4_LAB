#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node_bt{
    long int value;
    struct node_bt* leftchild;
    struct node_bt* rightchild; 
};

struct stack
{
	long int A[10000];
	int top;
	int size;
};

int STACK_EMPTY(struct stack *S)
{
	if(S->top==-1)
		return -1;
	else
		return 1;
}
int STACK_FULL(struct stack *S)
{
	if(S->top==S->size-1)
		return 1;
	else
		return 0;
}
void PUSH(struct stack *S,long int k)
{
 	if(STACK_FULL(S)==1)
 		;
 	else
 	{	
 		//printf("%d\n",S->top);
 		
 		S->top=S->top+1;
 		//printf("%d\n",S->top);
 		S->A[S->top]=k;
 	}
}
void POP(struct stack *S)
{
 	if(STACK_EMPTY(S)==-1)
 		printf("-1\n");
 	else
 	{	
 		//printf("%d\n",S->top);
 		//printf("%ld\n",S->A[S->top]);
 		S->top=S->top-1;
 		//printf("%d\n",S->top);
 		
 	}
}
/*int ret_POP(struct stack *S)
{
 	int ret;
 	ret=S->A[S->top];
 	S->top=S->top-1;
 	return ret;
 		
 		//printf("%d\n",S->top);
 		//printf("%ld\n",S->A[S->top]);
 		
 		//printf("%d\n",S->top);	
}*/

/*struct node_bt* tree_making(char* str, int* begin){
    if(strlen(str)==0 || *begin>=strlen(str))
     return NULL;
    
    long int n=0;
    while(*begin<strlen(str) && str[*begin]!='(' && str[*begin]!=')' && str[*begin]!='-'){
         
           n=(n*10)+(str[*begin]-48);
           *begin=*begin+1;
         
    }
     if(str[*begin]=='-'){
            n=-10000000;
           *begin=*begin+1;
     }
     printf("%d\n",n);
    struct node_bt* root=create_node(n);
  
    // check if start has reached the end of the string
    if (*begin>=strlen(str))
        return root;
 
    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (*begin<strlen(str) && str[*begin] == '(') {
        *begin = *begin + 1;
        root->leftchild = tree_making(str,begin);
    }
    if (*begin < strlen(str) && str[*begin] == ')')
        *begin = *begin + 1;
 
    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (*begin < strlen(str) && str[*begin] == '(') {
        *begin = *begin + 1;
        root->rightchild = tree_making(str,begin);
    }
    if (*begin < strlen(str) && str[*begin] == ')')
        *begin = *begin + 1;

    return root;

}*/

struct node_bt* create_node(int k){
    struct node_bt* newnode;
    newnode=(struct node_bt*)malloc(sizeof(struct node_bt));
    if(newnode==NULL)
    exit(0);

    newnode->value=k;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    

   return newnode;
}

void extract_str_withoutspace(char* str, char* str2){

	int i;
	int j=0;
	for(i=1;i<(strlen(str)-2);i++)
	{  
		if(str[i]!=' ')
		{    //printf("%d %c\n",i,str[i]);
			if(str[i]=='(' && str[i+1]==' ' && str[i+2]==')')
			
				{
					str2[j]=str[i];
					str2[j+1]='N';
					str2[j+2]=str[i+2];
					i=i+2;
					j=j+3;
				}
			else
				{
				str2[j]=str[i];
				j++;
				}
		}
	}
    str2[j]='\0';
    /*char* str3[3000];
    int k=0;
	for(int i=0;str2[i]!='\0';i++)
	  str3[k++]=str2[i];

      str3[k]='\0';
      printf("\n");
	  printf("%s",str3);*/

    

}

int index_tree(char str[],int start,int end)
{
	struct stack *S;
	int i;
	S=(struct stack*)malloc(sizeof(struct stack));
	S->size=500;
	S->top=-1;
	if(start>end)
		return -1;
	for(i=start;i<=end;i++)
	{
		if(str[i]=='(')
			PUSH(S,str[i]);
		else if(str[i]==')')
			if(S->A[S->top]='(')
				{
				POP(S);
				if(STACK_EMPTY(S)==-1)
					return i;
				}
	}
	return -1;
}
		
struct node_bt* tree_insert(char str2[], int start, int end)
{
	
	
	if(start>end)
		return NULL;
	struct node_bt *root;
	root=(struct node_bt*)malloc(sizeof(struct node_bt));
	int num=0;
	int neg=0;
	
	
	int k;
	if(str2[start]=='-')
		{
		neg=1;
		start++;
		//printf("in neg\n");
		}
	while(str2[start]>='0' && str2[start]<='9')
		{
		num*=10;
		num=num+(str2[start]-'0');
		start++;
	    }
	start--;
	
	if(neg==1)
		num=num*-1;
	//printf("%d ",num);
	if(str2[start+1]=='N')
		root=create_node(-9999999);
	else
		root=create_node(num);
	int i=-1;
	if(start+1<=end && str2[start+1]=='(')
		i=index_tree(str2,start+1,end);
	if(i!=-1)
		{
		root->leftchild=tree_insert(str2,start+2,i-1);
		root->rightchild=tree_insert(str2,i+2,end-1);
		}
	return root;
}
struct node_bt* findslca(struct node_bt* node,int m, int n){
      if(node==NULL) return NULL;
     // if(node!=NULL && node->value=-9999999) return NULL;
      // if(node->value=-9999999) return NULL;
      if(node->value==m||node->value==n) return node;

    struct node_bt* left_lca_node=findslca(node->leftchild,m,n);
    struct node_bt* right_lca_node=findslca(node->rightchild,m,n);
    if(left_lca_node && right_lca_node)  return node;

    // Otherwise check if left subtree or right subtree is LCA
    return ((left_lca_node!=NULL)? left_lca_node: right_lca_node);

}
int main(){
    char str[100000];
    fgets(str,100000,stdin);
    //printf("%s\n",str);
    int n1,n2;
    scanf("%d %d",&n1,&n2);
   
    char* str_p;
    str_p=(char*)malloc(100000*sizeof(char));
    
    extract_str_withoutspace(str,str_p);

    //printf("in main: %s\n",str_p);
    struct node_bt* root;
	root=(struct node_bt*)malloc(sizeof(struct node_bt));
	root=NULL;
    root=tree_insert(str_p,0,strlen(str)-1);
    struct node_bt* root_1;
	root_1=(struct node_bt*)malloc(sizeof(struct node_bt));
    root_1=findslca(root,n1,n2);

    printf("%d",root_1->value);

}

