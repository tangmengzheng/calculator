#include<stdio.h>
#include<ctype.h>
#include"trance.h"
#include"tools.h"
extern char buffer[MAX];
void cal();
char getop(char s[]);
int main(){
    int i;
    trance();
    for(i=0;buffer[i]!='\0';i++)
	putchar(buffer[i]);
    putchar('\n');
    cal();
return 0;
}
void cal(){
    char type;
    int number;
    char s[8];
    while((type=getop(s))!=EOF){
	switch(type){
	    case '0':
		ipush(matoi(s));
		break;
	    case '+':
		ipush(ipop()+ipop());
		break;
	    case '-':
		number=ipop();
		ipush(ipop()-number);
		break;
	    case '*':
		ipush(ipop()*ipop());
		break;
	    case '/':
		number=ipop();
		if(number==0)
		{
		    printf("erro ,div 0 \n");
		    break;
		}
		ipush(ipop()/number);
		break;
	    case ' ':
		break;
	    default:
		printf("Err !\n");
	}
    }
    printf("%d",ipop());
    putchar('\n');
}

char getop(char s[]){//获取字符类型
    char ch;
    int i=0;
    ch=getch();
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	return ch;
    else if(isdigit(ch)){
	while(isdigit(ch)){
	    s[i++]=ch;
	    ch=getch();
	}
	if(ch!=' ')
	    ungetch(ch);
	s[i]='\0';
	
    return '0';
    }
    else if(ch=='\0')
	return EOF;
    else 
	return ch;
}
