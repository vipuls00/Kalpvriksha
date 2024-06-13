#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stack[100];
int top=-1;
int operate(int a,int b,char opr)
{
switch(opr)
{
case '+': return a+b;
break;
case '-': return a-b;
break;
case '*': return a*b;
break;
case '/': return a/b;
}
    return 0;
}
 
int peak(){
    if(top>=0)
    return stack[top];
    else
    return -1;
}
void pop(){
    top--;
}
void push(int value){
    stack[++top]=value;
}
int main() {
     char str[100];
     int flag=0,i=0,j=0,n=0,ans=0,a,b;
     scanf("%[^\n]%*c", str);
    for(i=0;strlen(str)>i;i++){
    if(str[i]==' ') 
    {
        push(ans);
        //printf("%d\n",ans);
        ans=0;
    }
    else if(str[i]>=48 && str[i]<=57)
    {
        ans=ans*10+(str[i]-48);
    }
    else
    {
     b=peak();
     //printf("%d ",peak());
     pop();
     a=peak();
     //printf("%d ",peak());
     pop();
     if(top<-1)
    {
       flag=1;
       break;
    }
     else
    {// printf("%d%d%c",a,b,str[i]);
      ans=operate(a,b,str[i]);
     //printf("%d\n",ans);
    }
    }
    //printf("%d",peak());
    }
    //printf("%d",ans);
    if(flag==1 || top!=-1)
    printf("0");
    else
    printf("%d",ans);
    return 0;
}