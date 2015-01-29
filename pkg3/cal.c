#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"tools.h"
#include"cal.h"
extern func I;//此处不方便返回引用一外部变量
int main(){
    getSym();
    expression();
    blfc();
    interpret();
    return 0;
}

void expression(){ //表达式处理
    char csym;
    term();
    while(sym=='+'||sym== '-'){
	csym=sym;
	getSym();
	term();
	put(csym,0);//入指令栈
    }
}
void term(){//项处理
    char csym;
    factor();
    while(sym=='*'||sym=='/'){
	csym=sym;
	getSym();
	factor();
	put(csym,0); //指令栈
    }
}
void factor(){ //因子处理
    if(sym=='('){
	getSym();
	expression();
	if(sym!=')'){
	    printf("expression err \n");
	    exit(0);
	}

    }
    else if(sym==0){
	put('l',number);
	/* 此处小心，为何不能直接ipush操作呢？？？   问题关键 */
    }

    getSym();
}
void getSym(){//此法分析程序
    char ch=getch(); 
    if(isdigit(ch)){//数字串
	number=0;
	while(isdigit(ch)){
	    number=10*number+(ch-'0');
	    ch=getch();
	}
	ungetch(ch);
	sym=0;
    }
    else{
	sym=ch;
    }
}
void interpret(){//解释执行程序
    char ch;
    int n;
    while((ch=get())!=EOF){
	switch(ch){
	    case '+':
		ipush(ipop()+ipop());
		break;
	    case '-':
		n=ipop();
		ipush(ipop()-n);
		break;
	    case '*':
		ipush(ipop()*ipop());
		break;
	    case '/':
		n=ipop();
		if(n==0){
		    printf("div 0 err \n");
		    exit(0);
		}
		ipush(ipop()/n);
		break;
	    case 'l':
		ipush(I.a);
		break;
	    default:
		printf("Err \n");
		exit(0);
		break;
	}
    }
    printf("%d\n",ipop());
    if(!isEmpty()){
	printf("Big err \n");
	exit(0);
    }
}

