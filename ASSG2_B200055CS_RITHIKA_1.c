#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct hash_table{
    int size_table;
    int c1;
    int c2;
    int* table;
    char table_type;
};
int quadratic_prob_hash_function(struct hash_table* hasht,int num){
      
      if(hasht->table_type=='a'){
       int hash_index;
       hash_index=num%(hasht->size_table);
       if(hasht->table[hash_index]==num) return hash_index;
       else{
           int i=0;
           while(i<hasht->size_table)
           {
              int hash_new;
              hash_new=(hash_index+(hasht->c1*i)+hasht->c2*i*i)%hasht->size_table;
              if(hasht->table[hash_new]==num)
					{
				    return hash_new;
					}
                    i++;
           }
           }
   }

}
int check_prime(int n)
{
	if(n<=1)
		return 0;
	for(int i=2;i<n;i++){
		if(n%i==0)
			return 0;
    }
	return 1;
	
}
int prime_func(struct hash_table* hasht){
    
    int array_prime[25];
    int size=0;
    for(int i=2;i<hasht->size_table;i++){
        //printf("in loop");
        if(check_prime(i)) {
            
            array_prime[size++]=i;
            
        }
    }
    //printf("%d ",array_prime[size-1]);
    return array_prime[size-1];
}
// largest Prime number less than the size of hash table
/*int prime_func(struct hash_table* hasht){
    int array_prime[1000];
    int num=2;
    int i;
    for(i=0;num<hasht->size_table; )
    {
        if(num==2){
            array_prime[i++]=num;
            num++;
        }
        else if(num%2!=0){
            int res_1;
            res_1=check_prime(num);
            if(res_1==1) array_prime[i++]=num;
            num++;
        }
    }
    return array_prime[i-1];
}*/

//complete_here
int double_hashing_hash_function(struct hash_table* hasht,int num)
{
      /* if(hasht->table_type=='b')
       {
           int hash_index;
           hash_index=num%(hasht->size_table);
           if(hasht->table[hash_index]==-99) return hash_index;
           else{
               for(int i=1;i<hasht->size_table;i++)
               {
                   int hash_new;
                   int r;
                   r=prime_func(hasht);
                   hash_new=(hash_index+(i*(r-num%r)))%hasht->size_table;
                   if(hasht->table[hash_new]==-99) return hash_new;
                   }
           } 
       }*/


       if(hasht->table_type=='b')
       {
           int hash_index;
           hash_index=num%(hasht->size_table);
           if(hasht->table[hash_index]==num) return hash_index;
           else{
               for(int i=1;i<hasht->size_table;i++)
               {
                   int hash_new;
                   int r;
                   r=prime_func(hasht);
                   hash_new=(hash_index+(i*(r-num%r)))%hasht->size_table;
                   if(hasht->table[hash_new]==num) return hash_new;
                   }
           } 
       }
}

void insert_table(struct hash_table* hasht, int num){
   if(hasht->table_type=='a'){
       int hash_index;
       hash_index=num%(hasht->size_table);
       if(hasht->table[hash_index]==-99) hasht->table[hash_index]=num;
       else{
           int i=0;
           while(i<hasht->size_table)
           {
              int hash_new;
              hash_new=(hash_index+(hasht->c1*i)+hasht->c2*i*i)%hasht->size_table;
              if(hasht->table[hash_new]==-99)
					{
					hasht->table[hash_new]=num;
					break;
					}
                    i++;
           }
           }
   }
   
    if(hasht->table_type=='b')
       {
           int hash_index;
           hash_index=num%(hasht->size_table);
           if(hasht->table[hash_index]==-99) hasht->table[hash_index]=num;
           else{
               for(int i=1;i<hasht->size_table;i++)
               {   //printf("entered");
                   int hash_new;
                   int r;
                   r=prime_func(hasht);
                  // printf("R=%d ",r);
                   hash_new=(hash_index+(i*(r-num%r)))%(hasht->size_table);
                   if(hasht->table[hash_new]==-99){
                        hasht->table[hash_new]=num;
                        break;
                   }
               }
           } 
       }
}


int search_table(struct hash_table* hasht, int num){
    int present_in_table=0;
    int in_hash;
    if(hasht->table_type=='a'){
      in_hash=quadratic_prob_hash_function(hasht,num);
      if(hasht->table[in_hash]==num) present_in_table=1;
      else present_in_table=-1;
     }
     if(hasht->table_type=='b'){
       int hash; 
       hash=double_hashing_hash_function(hasht,num);
       if(hasht->table[hash]==num) present_in_table=1;
       else present_in_table=-1; 
   }
    return present_in_table;
}


void print_table(struct hash_table* hasht)
{
	for(int i=0;i<hasht->size_table;i++)
		if(hasht->table[i]!=-99)
			printf("%d (%d)\n",i,hasht->table[i]);
		else
			printf("%d ()\n",i);
}


void delete_table_ele(struct hash_table* hasht, int num){
    int in_hash;
    if(hasht->table_type=='a'){
      in_hash=quadratic_prob_hash_function(hasht,num);
      if(hasht->table[in_hash]==num) hasht->table[in_hash]=-99;
    }
    if(hasht->table_type=='b'){
       int hash; 
       hash=double_hashing_hash_function(hasht,num);
       if(hasht->table[hash]==num) hasht->table[hash]=-99;
   }
}


int main()
{   struct hash_table* hashtable;
	hashtable=(struct hash_table*)malloc(sizeof(struct hash_table));
    char type;
	int size;
	scanf("%c",&type);
    hashtable->table_type=type;
	scanf("%d",&size);
    hashtable->size_table=size;
	hashtable->table=(int*)malloc(sizeof(int)*hashtable->size_table);
	for(int i=0;i<hashtable->size_table;i++)
		hashtable->table[i]=-99;
	if(hashtable->table_type=='a')
	{  
		scanf("%d %d",&hashtable->c1,&hashtable->c2);
	}
	char op;
    int num,res;
	scanf("%c",&op);
	while(op!='t')
	{ 	switch(op)
		{
		 case 'i': scanf(" %d",&num);
		 	       insert_table(hashtable,num);
		 	       break;
		 case 's': scanf(" %d",&num);
		           res=search_table(hashtable,num);
                   printf("%d\n",res);
		 	       break;
		 case 'p': print_table(hashtable);
		 	       break;
		 case 'd': scanf(" %d",&num);
                   res=search_table(hashtable,num);
                   if(res==1)
		           delete_table_ele(hashtable,num);
		 	       break;
		}
		scanf("%c",&op);
	}
		
	return 0;
}
