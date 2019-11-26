#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAXOP 100
#define NUMBER '0'
int sp=0;
int main()
{
void clear(void);
int getop(char []);
void push(double);
double pop(void);
double stof(char s[]);
int type;
double op2,op1;
char s[MAXOP];
while((type=getop(s))!=EOF)
{
switch (type){
  case NUMBER:
           push(stof(s));
           break;
  case '+':
     push(pop()+pop());break;
  case '-':
     op2=pop();
     push(pop()-op2);break;
  case '*':
    push(pop()*pop());break;
  case '/':
    op2=pop();
    if(op2!=0.0) push(pop()/op2);
    else printf("error");
    break;
  case '%':
    op2=pop();
    if(op2!=0.0) push(fmod(pop(),op2));
    else printf("error");
    break;
  case '?':
     op2=pop();
     printf("\t%.8g\n",op2);
     push(op2);break;
  case 'c':
     clear();break;
  case 'd':
     op2=pop();
     push(op2);push(op2);break;
  case 's':
     op1=pop();
     op2=pop();
     push(op1);
     push(op2);break;
  case '\n':
    printf("\t%.8g\n",pop());break;
  default:
    printf("error:");
    break;
}

}
return 0;
}
int getop(char s[])
{
int getch();
void ungetch(int);

int c,i;
while((s[0]=c=getch())==' '||c=='\t') ;
s[1]='\0';
i=0;
if(!isdigit(c)&&c!='.' &&c!='-')
{
  return c;
}
if(c=='-')
   {
     if(isdigit(c=getch())||c=='.') s[++i]=c;
     else {
             if(c!=EOF) ungetch(c);
             return '-';
           }

   }
if(isdigit(c))
  {while ( isdigit( s[++i]=c=getch() ) ) 
   ;}
if(c=='.')
   {while ( isdigit(s[++i]=c=getch()) ) 
     ;}
s[i]='\0';
if(c!=EOF)
   ungetch(c);
return NUMBER;
}
void push(double s)
{}
double pop(void)
{}
double stof(char s[])
{

}
int getch(){}
void ungetch(int a){}
void clear(void)
{
  sp=0;
}
