#include<stdio.h>
#include<ctype.h>
#include"seqStack.h"
#include"tools.h"
#include"trance.h"
void trance(){
    SeqStack S1,S2;
    init(&S1);
    char ch,rch;
    char op[128];
    op['+']=op['-']=1;
    op['*']=op['/']=2;
    op['(']=3;
    op[')']=0;
    op['#']=-1;

    push(&S1,'#');
    while((ch=getchar())!='='){
	if(isdigit(ch))
	    put(ch);
	else if (isop(ch)){
	    put(' ');
	    if(op[ch]>op[getTop(S1,&rch)])
		push(&S1,ch);
	    else {
		   while(op[ch]<=op[getTop(S1,&rch)]&&rch!='(')
			put(pop(&S1,&rch));
		    if(rch=='('&&ch==')')
			pop(&S1,&rch);
		    else
			push(&S1,ch);
		 }
	    }
     }
     while(notEmpty(S1))
	 if(pop(&S1,&rch)!='#')
	    put(rch);
    put('\0');
}
int isop(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
	return 1;
    return 0;
}
