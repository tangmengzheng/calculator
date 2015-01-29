#ifndef SEQ_STACK_H
#define SEQ_STACK_H
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char DataType;
typedef struct{
	DataType stack[MAXSIZE];
	int top;
}SeqStack;

void init(SeqStack *S);
int notEmpty(SeqStack S);
int push(SeqStack *S,DataType x);
int pop(SeqStack* S,DataType *x);
int getTop(SeqStack S,DataType *x);
#endif
