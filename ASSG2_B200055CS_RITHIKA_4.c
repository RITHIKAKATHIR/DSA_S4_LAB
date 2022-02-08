#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct data{
    char name[200];
    char roll[100];
};
struct hash_info{
    int i1;
    int i2;
    int i3;
    int index;
};
int hash_sub_func(int i){
   int k;
   k=(i%26)%10;
    return k;
}
struct hash_info* hash_function(char* word){
    struct hash_info* h;
    h=(struct hash_info*)malloc(sizeof(struct hash_info));
    char digit1[100];
    char digit2[100];
    char digit3[100];
    int j1=0; 
    int j2=0;
    int j3=0;
    for(int j11=0;j11<3;j11++){
        if(j11<=strlen(word)) digit1[j1++]=word[j11];
    }
    digit1[j1]='\0';
    for(int j22=0;j22<5/*,j22<=strlen(word)*/;j22=j22+2){
        if(j22<=strlen(word))  digit2[j2++]=word[j22];
    }
    digit2[j2]='\0';

    for(int j33=0;j33<9/*,j33<=strlen(word)*/;j33=j33+4){
        if(j33<=strlen(word))  digit3[j3++]=word[j33];
    }
    digit3[j3]='\0';
   // printf("%s %s %s",digit1,digit2,digit3);
    int dig1=0;
    int dig2=0;
    int dig3=0;
    for(int i=0;i<j1;i++){
        dig1=dig1+digit1[i];
    }
    for(int i1=0;i1<j2;i1++){
        dig2=dig2+digit2[i1];
    }
    for(int i2=0;i2<j3;i2++){
        dig3=dig3+digit3[i2];
    }
   // printf("%d %d %d\n",dig1,dig2,dig3);


   
    h->i1=hash_sub_func(dig1);
    h->i2=hash_sub_func(dig2);
    h->i3=hash_sub_func(dig3);

   // printf("%d %d %d\n",h->i1,h->i2,h->i3);

    int index=(h->i1*100)+(h->i2*10)+(h->i3*1);
   // printf("%d\n",index);
    h->index=index;
    return h;
}
void insert_func(struct data* Hash_table,char* name){
  struct hash_info* hash_index;
  hash_index=hash_function(name);
 // printf("in func: %d",hash_index->index);
  char roll_num[200];
    int i=0;
    roll_num[i]=name[i];
    i++;
    roll_num[i]=hash_index->i1+'0';
    i++;
    roll_num[i]=hash_index->i2+'0';
    i++;
    roll_num[i]=hash_index->i3+'0';
    i++;
    roll_num[i]='\0';
   // printf(" rollnumin func: %s",roll_num);
    strcpy(Hash_table[hash_index->index].name,name);
    strcpy(Hash_table[hash_index->index].roll,roll_num);

}
void search_roll(struct data* Hash_table,char* roll){
   int index=0;
   int i=1;
   int j=2;
   for(int i=1;i<=3;i++){
       index=index+((roll[i]-'0')*pow(10,j));
         j--;
   }
   // printf("in search index is: %d",index);
   if(strcmp(Hash_table[index].roll,roll)==0){
       printf("%s\n",Hash_table[index].name);
   }
   else{
       printf("NOT FOUND\n");
   }
}
void delete(struct data* Hash_table,char* roll){
   int index=0;
   int i=1;
   int j=2;
   for(int i=1;i<=3;i++){
       index=index+((roll[i]-'0')*pow(10,j));
         j--;
   }
   //printf("in delete: %d",index);
    if(strcmp(Hash_table[index].roll,roll)==0){
         strcpy(Hash_table[index].name,"null");
         strcpy(Hash_table[index].roll,"null");
    }
   
}

int main(){
    char* name;
    name=(char*)malloc(sizeof(char)*1000);
    struct data* Hash_table;
    Hash_table=(struct data*)malloc(sizeof(struct data)*1000);
    for(int i=0;i<1000;i++){
        strcpy(Hash_table[i].name,"null");
        strcpy(Hash_table[i].roll,"null");
    }
    char ch;
    int hash_index;
     while (1)
	{
		scanf("%c",&ch);

		switch (ch)
		{
			case 'i':	scanf(" %s",name);
                        insert_func(Hash_table,name);
                        break;
			case 's':   scanf(" %s",name);
                        search_roll(Hash_table,name);
                        break;
            case 'd':   scanf(" %s",name);
                        delete(Hash_table,name);
                        break;
            case 't':	return 1;

		}
	}





   return 0; 
}