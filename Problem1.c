#include<stdio.h>
#include<conio.h>
#include<process.h>       //for exit()
#include<stdlib.h>         //for system(“cls”)
#define MAX 5               //Maximum number of elements that can be stored
int top=-1,stack[MAX];
void push();
void pop();
void display();
void main()
{
    int ch;
    while(1)                //infinite loop, will end when choice will be 4
    {
        //system(“cls”);      //work in windows, for other OS change it to system(“clear”)
        printf(“*** Stack Menu ***”);

printf(“nn1.Pushn2.Popn3.Displayn4.Exit”);
        printf(“nnEnter your choice(1-4):”);
        scanf(“%d”,&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf(“nWrong Choice!!Press any key….”);
                     getch();
        }
    }
}
void push()
{
    int val;
    if(top==MAX-1)
    {
        printf(“nStack is full!!Press any key….”);
        getch();
    }
    else
    {
        printf(“nEnter element to push:”);
        scanf(“%d”,&val);
        top=top+1;
        stack[top]=val;
        printf(“nPress any key….”);
        getch();
    }
}
void pop()
{
    if(top==-1)
    {
        printf(“nStack is empty!!Press any key….”);
        getch();
    }
    else
    {
        printf(“nDeleted element is %dnPress any key….”,stack[top]);
        top=top-1;
        getch();
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf(“nStack is empty!!Press any key….”);
        getch();
    }
    else
    {
        printf(“nStack is…n”);
        for(i=top;i>=0;–i)
            printf(“%dn”,stack[i]);
    printf(“nPress any key….”);
    getch();
    }
}
