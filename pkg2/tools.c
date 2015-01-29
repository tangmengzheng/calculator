#include<stdio.h>
#include<ctype.h>
#include"tools.h"
static int sp=0;
static int bf=0;
static int pt=0;
static int stack[MAX];
char buffer[MAX];

int ipop(){
    if(sp==0){
	printf("the istack is null\n");
	return ;
    }
    return stack[--sp];
   } 
void ipush(int x){
    if(sp>MAX){
	printf("the istack is full \n");
	return ;
    }
    stack [sp++]=x;
}
int ifEmpty(){
    if(sp<=0)
	return 1;
    return 0;
}
char getch(){
    if(bf>=MAX)
	printf("getch err \n");
    else 
	return buffer[bf++];
}
void ungetch(char ch){
    if(bf<=0){
	printf("the buffer is full\n");
	return ;
    }
    buffer[--bf]=ch;
}
void put(char ch){
    if(pt>=MAX)
	printf("the buffer is full\n");
    else 
	buffer[pt++]=ch;
}

int matoi(char s[]){//字符转换为整数
    int i=0,n=0;
    while(s[i]!='\0'){
	n=10*n+s[i]-'0';
	i++;
    }
    return n;
}
