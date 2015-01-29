#include<stdio.h>
#include<ctype.h>
#include"tools.h"
#include"cal.h"
static int sp=0;//数据栈栈顶指针
static int bf=0;//缓冲区指针
static int pt=0;//指令队尾
static int gt=0;//指令队首
static int stack[MAX]; //数据栈
static char buffer[MAX];//缓冲区
static func function[MAX];// 指令
func I;
/*测试时用
void main(){
    char ch;
    while((ch=getch())!=EOF)
	putchar(ch);
}
*/

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
int isEmpty(){
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
void put(char ch,int a){
    func fc;
    fc.f=ch;
    fc.a=a;
    if(pt>MAX)
	printf("the function array is full\n");
    
    else{ 
	function[pt++]=fc;
    }
}
char get(){
    if(gt>=pt){
	return EOF;
    }
    else{
	 I=function[gt++];
	 return I.f;
    }
}


void blsp(){//遍历
  int i;
  for(i=0;i<sp;i++)
      printf("%d  ",stack[i]);
  putchar('\n');
}
void blfc(){
    int i;
    printf("**********************************\n");
    for(i=0;i<pt;i++)
	printf("%c %10d \n",function[i].f,function[i].a);
    printf("**********************************\n");
}
