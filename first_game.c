#include<stdio.h>
void display(char a[])
{
printf("  |  |  \n");
printf("%c |%c |%c \n",a[1],a[2],a[3]);
printf("--------\n");
printf("  |  |  \n");
printf("%c |%c |%c \n",a[4],a[5],a[6]);
printf("--------\n");
printf("  |  |  \n");
printf("%c |%c |%c \n",a[7],a[8],a[9]);

}
int isempty(int n,char a[],char c)
{
    if(a[n]==' ')
    {
    
 return 1;        
    }
    else
    return 0;
}
int checktodraw(int a[])
{
    int i,c=0;
    for(i=1;i<10;i++)
    {
        if(a[i]==' ')
        c++;
    }
    if(c>0)
    return 0;
    else
    return 1;
}
int checktowin(char a[],char ch)
{
    if((a[1]==ch&&a[2]==ch&&a[3]==ch)||(a[4]==ch&&a[5]==ch&&a[6]==ch)||(a[7]==ch&&a[8]==ch&&a[9]==ch)||
	(a[1]==ch&&a[4]==ch&&a[7]==ch)||(a[2]==ch&&a[5]==ch&&a[8]==ch)||(a[9]==ch&&a[6]==ch&&a[3]==ch)||
	(a[1]==ch&&a[5]==ch&&a[9]==ch)||(a[7]==ch&&a[5]==ch&&a[3]==ch))
    return 1;
    else
    return 0;
}

int main() {
  
   //printf("Sum of x+y = %i", z);
   char a[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
   char ch,p1,p2,c;
   int n,t=0,w=0,p=1,turn=1,r=1,checksp,checkwin,checkdraw,resul=0;
   display(a);
    while(r==1)
    {
     char a[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  while(t==0)
   {
   printf("enter your choice:X or O:\n");
   scanf(" %c",&ch);
   if(ch=='X'||ch=='O'||ch=='x'||ch=='o')
   {
     t=1;
    if(ch=='X'||ch=='x')
    {
       p1='X';
       p2='O';
    }
    else
    {
        p1='O';
        p2='X';
        
    }
   }
   }
    printf("player-1 latter is %c\nplayer-2 latter is %c\n",p1,p2);
        while(w==0)
        {
          if(turn==1)
          {
              printf("player-1:enter a position to place to be insert:\n");
              scanf("%d",&n);
              checksp=isempty(n,a,p1);
              if(checksp==1)
              {
              a[n]=p1;
              turn=2;
              display(a);
              }
              else
              {
                  display(a);
                  printf("position is already filled\n");
              turn=1;
              }
              checkwin=checktowin(a,p1);
              if(checkwin==1)
              {
                  display(a);
                  printf("player-1 is win the game!!\n");
                  w=1;
              }
              else
              turn=2;
              checkdraw=checktodraw(a);
              if(checkdraw==1)
              {
                  turn=turn;
              }
              else
              {
                  printf("game is draw!!\n");
                  w=1;
              }
              
            }
            else
            {
              printf("player-2:enter a position to place to be insert:\n");
              scanf("%d",&n);
              checksp=isempty(n,a,p2);
              if(checksp==1)
              {
              a[n]=p2;
              turn=1;
              display(a);
              }
              else
              {
                  display(a);
                printf("position is already filled\n");  
              turn=2;
              }
              checkwin=checktowin(a,p2);
              if(checkwin==1)
              {
                  display(a);
                  printf("player-2 is win the game!!\n");
                  w=1;
              }
              else
              turn=1;  
               checkdraw=checktodraw(a);
              if(checkdraw==1)
              {
                  turn=turn;
              }
              else
              {
                  printf("game is draw!!\n");
                  w=1;
              }  
            }
            
        }
        while(resul==0)
        {
        printf("do u want to  play again:y or n:\n");
        scanf(" %c",&c);
        if(c=='y'||c=='n')
          resul=1;
        }
        resul--;
        if(c=='y')
        {
         r=1;
         w=0;
         t=0;
        }
        else
        {
         r=0;
         printf("you are exit from the game.");
        }
    }
    
}
