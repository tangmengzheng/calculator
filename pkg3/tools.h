#ifndef TOOLS_H
#define TOOLS_H
#define MAX 100
int ipop();
void ipush(int x);
int ifEmpty();
char getch();
void ungetch(char ch);
void put(char ch,int a);
char get();
void blsp();
void blfc();

typedef struct{
    char f;
    int a;
}func;
#endif
