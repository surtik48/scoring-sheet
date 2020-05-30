#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void btdetails(int);
void bowdetails(int);
void fulldetails(int,int);

int k=0;

struct batsmen
{   char namebat[10];
    int score,highest,innings;
    float average;
};
struct bowlers
{   char namebow[10];
    int wickets,matches;
    float economy;
};
struct team
{char name[20];
    struct batsmen b[10];
    struct bowlers bow[10];
}teams[2];
int teamscore(struct team ,int number);
int teamscore(struct team t,int number)
{
    int sum=0,m;
    for(m=0;m<number;m++)
    {
        sum+=t.b[m].score;

    }
    return sum;
}
int wicketslost(struct team h,int numbers)
{
    int wi=0,m;
    for(m=0;m<numbers;m++)
    {
        wi+=h.bow[m].wickets;

    }
    return wi;
}


/*---------------------------------------------------------*/
int toss,o;
int main()

{
  printf("\t\tDETAILS COUNTER\n");
  printf("Name of team 1:");
  gets(teams[0].name);
  printf("\nName of team 2:");
  gets(teams[1].name);
  printf("\ntoss won by team number:");
  scanf("%d",&toss);
  printf("\n");
  printf(" chose to 1.bat or 2.bowl:");
  scanf("%d",&o);
  printf("\n \t\tSTART ENTERING MATCH DETAILS FOR SCORE SHEET\n\n");
  if(((toss==1)&&(o==1))||((toss==2)&&(o==2)))
    {btdetails(0);
    k++;}
  else
    {btdetails(1);
    k++;}

}
/*---------------------------------------------------------------*/
int  num1,num2;
void btdetails(int tnum)
{int j;
  printf("\t\tenter the batsman details for team %s\n\n",teams[tnum].name);
  printf("enter the number of batsmen:");
  if(tnum==0)
 {
  scanf("%d",&num1);
   for(j=0;j<num1;j++)
   {
  printf("name:");
  scanf("%s",&teams[0].b[j].namebat);
  printf("\n");
  printf("score:");
  scanf("%d",&teams[0].b[j].score);
  printf("\n");
  printf("number of 4's:");
  scanf("%d",&teams[0].b[j].highest);
  printf("\n");
  printf("number of 6's:");
  scanf("%d",&teams[0].b[j].innings);
  printf("\n");
  printf("strike rate:");
  scanf("%f",&teams[0].b[j].average);
   }
   k++;
   bowdetails(1);
  }
  else
    {scanf("%d",&num2);
    for(j=0;j<num2;j++)
    {
  printf("name:");
  scanf("%s",&teams[1].b[j].namebat);
  printf("\n");
  printf("score:");
  scanf("%d",&teams[1].b[j].score);
  printf("\n");
  printf("number of 4's:");
  scanf("%d",&teams[1].b[j].highest);
  printf("\n");
  printf("number of 6's:");
  scanf("%d",&teams[1].b[j].innings);
  printf("\n");
  printf("strike rate:");
  scanf("%f",&teams[1].b[j].average);
    }
    k++;
    bowdetails(0);

}
}
/*---------------------------------------------------------*/
int n1,n2;
void bowdetails(int tnumb)
{int j;
  printf("\t\tenter the bowler details for team %s\n\n",teams[tnumb].name);
  printf("enter the number of bowlers:");
  if(tnumb==0)
 {
  scanf("%d",&n1);
   for(j=0;j<n1;j++)
   {


  printf("name:");
  scanf("%s",&teams[0].bow[j].namebow);
  printf("\n");
  printf("number of wickets:");
  scanf("%d",&teams[0].bow[j].wickets);
  printf("\n");
  printf("number of maidens:");
  scanf("%d",&teams[0].bow[j].matches);
  printf("\n");
  printf("economy:");
  scanf("%f",&teams[0].bow[j].economy);
   }
   k++;
   if(k==4)
    fulldetails(toss,o);
    else
   btdetails(0);
  }
  else
    {scanf("%d",&n2);
    for(j=0;j<n2;j++)
    {


  printf("name:");
  scanf("%s",&teams[1].bow[j].namebow);
  printf("\n");
  printf("number of wickets:");
  scanf("%d",&teams[1].bow[j].wickets);
  printf("\n");
  printf("number of maidens:");
  scanf("%d",&teams[1].bow[j].matches);
  printf("\n");
  printf("economy:");
  scanf("%f",&teams[1].bow[j].economy);
    }
    k++;
    if(k==4)
        fulldetails(toss,o);
    else
    btdetails(1);

}
}
/*-----------------------------------------------------------------*/
void fulldetails(int t,int op)
{int i=0;
system("COLOR B");
    printf("\t\t\tCRICKET SCORE SHEET\n\n");
    system("COLOR C");
    printf("FIRST INNINGS:\n");
    system("COLOR F");
    if(((t==1)&&(op==1))||((t==2)&&(op==2)))
    {
        printf("\t\tBATTING OF %s\n\n",teams[0].name);
        printf("\n");
        printf("NAME\tSCORE\t4's\t6's\tSTRIKE RATE\n\n");
        system("COLOR A");
        while(i<num1)
        {
            printf("%s\t",teams[0].b[i].namebat);
            printf("%d\t",teams[0].b[i].score);
            printf("%d\t",teams[0].b[i].highest);
            printf("%d\t",teams[0].b[i].innings);
            printf("%.2f",teams[0].b[i].average);
            printf("\n");
            i++;
        }

        i=0;
        system("COLOR F");
        printf("\t\tBOWLING OF %s\n\n",teams[1].name);
        printf("\n");
         printf("NAME\t   WICKETS\t MAIDENS\t ECONOMY\n\n");
         system("COLOR E");
         while(i<n2)
        {
            printf("%-10s",teams[1].bow[i].namebow);
            printf("  %d\t\t",teams[1].bow[i].wickets);
            printf("   %d\t\t",teams[1].bow[i].matches);
            printf("  %.2f\t",teams[1].bow[i].economy);
            printf("\n");
            i++;
        }
         printf("TEAM SCORE:%d  WICKETS:%d\n",teamscore(teams[0],num1),wicketslost(teams[1],n2));
        i=0;
        system("COLOR C");
        printf("\n\nSECOND INNINGS:\n");
        system("COLOR F");
         printf("\t\tBATTING OF %s\n\n",teams[1].name);
         printf("\n");
         printf("NAME\tSCORE\t4's\t6's\tSTRIKE RATE\n\n");
        system("COLOR E");
        while(i<num2)
        {
            printf("%s\t",teams[1].b[i].namebat);
            printf("%d\t",teams[1].b[i].score);
             printf("%d\t",teams[1].b[i].highest);
            printf("%d\t",teams[1].b[i].innings);
            printf("%.2f",teams[1].b[i].average);
            printf("\n");
            i++;
        }
        i=0;
        printf("TEAM SCORE:%d\n\n",teamscore(teams[1],num2));
        system("COLOR F");
        printf("\t\tBOWLING OF %s\n\n",teams[0].name);
        printf("\n");
        printf("NAME\t  WICKETS\t MAIDENS\t ECONOMY\n\n");
         system("COLOR A");
         while(i<n1)
        {
            printf("%-10s",teams[0].bow[i].namebow);
            printf(" %d\t\t",teams[0].bow[i].wickets);
            printf("    %d\t\t",teams[0].bow[i].matches);
            printf("  %.2f\t",teams[0].bow[i].economy);
            printf("\n");
            i++;
        }
         printf("TEAM SCORE:%d  WICKETS:%d\n",teamscore(teams[1],num2),wicketslost(teams[0],n1));
        i=0;
       /* --------------------------------------------*/


    }
    system("COLOR F");
    if(((t==1)&&(op==2))||((t==2)&&(op==1)))
    {printf("\nFIRST INNINGS:\n");
        printf("\t\tBATTING OF %s\n\n",teams[t].name);
        printf("\n");
        printf("NAME\tSCORE\t4's\t6's\tSTRIKE RATE\n\n");
        system("COLOR A");
        while(i<num2)
        {
            printf("%s\t",teams[1].b[i].namebat);
            printf("%d\t",teams[1].b[i].score);
             printf("%d\t",teams[1].b[i].highest);
            printf("%d\t",teams[1].b[i].innings);
            printf("%0.2f\t",teams[1].b[i].average);
            printf("\n");
            i++;
        }
        i=0;
        system("COLOR F");
         printf("\t\tBOWLING OF %s\n\n",teams[t-1].name);
         printf("\n");
         printf("NAME\tWICKETS\tMAIDENS\tECONOMY\n\n");
         system("COLOR E");
         while(i<n1)
        {
            printf("%s\t",teams[0].bow[i].namebow);
            printf("%d\t",teams[0].bow[i].wickets);
            printf("%d\t",teams[0].bow[i].matches);
            printf("%.2f\t",teams[0].bow[i].economy);
            printf("\n");
            i++;
        }
         printf("TEAM SCORE:%d  WICKETS:%d\n",teamscore(teams[1],num2),wicketslost(teams[0],n1));
        i=0;
        system("COLOR F");
         printf("\n\n\tSECOND INNINGS:\n");
          printf("\t\tBATTING OF %s\n\n",teams[t-1].name);
          printf("\n");
          printf("NAME\tSCORE\t4's\t6's\tSTRIKE RATE\n\n");
        system("COLOR E");
        while(i<num1)
        {
            printf("%s\t",teams[0].b[i].namebat);
            printf("%d\t",teams[0].b[i].score);
             printf("%d\t",teams[0].b[i].highest);
            printf("%d\t",teams[0].b[i].innings);
            printf("%.2f\t",teams[0].b[i].average);
            printf("\n");
            i++;
        }

        i=0;
        system("COLOR F");
        printf("\t\tBOWLING OF %s\n\n",teams[t].name);
        printf("\n");
        printf("NAME\tWICKETS\tMAIDENS\tECONOMY\n\n");
        system("COLOR A");
         while(i<n2)
        {
            printf("%s\t",teams[1].bow[i].namebow);
            printf("%d\t",teams[1].bow[i].wickets);
            printf("%d\t",teams[1].bow[i].matches);
            printf("%f\t",teams[1].bow[i].economy);
            printf("\n");
            i++;
        }
        printf("TEAM SCORE:%d  WICKETS:%d\n",teamscore(teams[0],num1),wicketslost(teams[1],n2));


    }
}

