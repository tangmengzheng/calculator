#include<stdio.h>
#include<stdlib.h>
#include"seqStack.h"

void init(SeqStack *S){
	S->top=0;
}
int notEmpty(SeqStack S){
	if(S.top<=0)
		return 0;
	return 1;
}
int push(SeqStack *S,DataType x){
	if(S->top>=MAXSIZE){
		printf("The Stack is full \n");
		return -1;
	}
	else{
		S->stack[S->top]=x;
		S->top++;
		return x;
	}
    
}
int pop(SeqStack *S,DataType *x){
	if(S->top<=0){
		printf("The stack is empty\n");
		return -1;
	}
	else{
	    *x=S->stack[--S->top];
		
	    return *x;
	}
}
int getTop(SeqStack S,DataType *x){
	if(S.top<=0){
		printf("the Stack if empty \n");
		return -1;
	}
	else{
		*x=S.stack[S.top-1];
	return *x;
	}
}

