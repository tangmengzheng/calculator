#include<stdio.h>
#include<ctype.h>
#include"tools.h"
#include"seqStack.h"
int Evaluate();		//执行函数
char getop(char s[]);	//读取  词法分析
char precede(char ch1,char ch2);//字符优先级比较
int op(int x,char ch,int y);//计算函数
SeqStack S; //指令栈
int main(){
    int n;
    iinit();
    init(&S);
    push(&S,'=');
    n=Evaluate();
    printf("%d\n",n);
    return 0;
}
int Evaluate(){
    int x,y;
    char c,string[8];
    char ch=getop(string);
    while(ch!='='||getTop(S)!='='){	
	if(ch==0){
	    ipush(matoi(string));
	    ch=getop(string);
	   }
	else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='='){
	    switch(precede(getTop(S),ch)){
		case '<':
		    push(&S,ch);
		    ch=getop(string);
		    break;
		case '=':
		    pop(&S,&c);
		    ch=getop(string);
		    break;
		case '>':
		    pop(&S,&c);
		    y=ipop();
		    x=ipop();
		    ipush(op(x,c,y));
		    break;	
	    }
	}
    }
    return ipop();
}

char getop(char s[]){//获取字符类型
    char ch;
    int i=0;
    ch=getch();
    if(isdigit(ch)){
	while(isdigit(ch)){
	    s[i++]=ch;
	    ch=getch();
	}
	if(ch!=' ')
	    ungetch(ch);
	s[i]='\0';
	
    return 0;
    }
    else {
	return ch;
    }
}
int op(int x,char ch,int y){
    switch(ch){
	case '+':
	    return x+y;
	case '-':   //注意先后次序
	    return x-y;
	case '*':
	    return x*y;
	case '/':   //注意先后次序
	    if(y==0){
		printf("div 0 err\n");
		exit(0);
	    }
	    return x/y;
    }
}
char precede(char ch1,char ch2){
    switch(ch1){
	case '+':
	case '-':
	    switch(ch2){
		case '+':
		case '-':
		    return '>';	
		case '*':
		case '/':
		    return '<';

		case '(':
		    return '<';
		case ')':
		    return '>';
		case '#':
		    return '>';
	    }
	case '*':
	case '/':
	    switch(ch2){
		case '+':
		case '-':
		case '*':
		case '/':
		    return '>';
		case '(':
		    return '<';
		case ')':
		    return '>';
		case '=':
		    return '>';
	    }

	case '(':
	    if(ch2==')')
		return '=';
	    else if(ch2=='#'){
		printf("kuohao err\n");
		exit(0);
	    }
	    else 
		return '<';
	case ')':
	    if(ch2=='('){
		printf(" ( or ) err \n");
		exit(0);
	    }
	    else 
		return '>';
	case '=':
	    if(ch2==')'){
		printf("kuohao pipei err \n");
		exit(0);
	    }
	    else 
		return '<';

	default:
	    printf("err \n");
	    exit(0);

	}
}



