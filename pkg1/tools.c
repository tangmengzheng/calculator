#include<stdio.h>
#include<ctype.h>
#include"tools.h"
static int sp=0;//堆栈栈定指针
static int bf=0;//输出缓冲区队首
static int pt=0;//输出缓冲区队尾
static int stack[MAX];//运行时操作符栈
char buffer[MAX];//输出队列
//buffer 为一个类似队列的数据结构,具体包括put、get和unget操作

void iinit(){
    sp=0;
}

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
    char ch;
    if(bf<=0){
	ch=getchar();
    }
    else{
	ch=buffer[--bf];
    }
    return ch;
}
void ungetch(char ch){
    if(bf>MAX){
	printf("cant ungeth,the buffer is full\n");
    }
    else{
	buffer[bf++]=ch;
    }
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
