/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<time.h>
#define m 10

int a,b,u,v,ne=1,min,mincost=0,i,j;
int cost[m][m],parent[m]={0},n;


void prims(int n,int cost[10][10])
{
    int i,j,u,v,min,mincost=0,visited[10];
    int ne=1;
    for(i=1;i<=n;i++)
    visited[i]=0;
    visited[1]=1;
    while(ne<n)
    {
    for(i=1,min=999;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]<min)
            if(visited[i]==1)
            {
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    mincost=min+mincost;
    printf("\nedge %d (%d-%d) cost:%d",ne++,u,v,min);
    visited[v]=1;
    cost[u][v]=cost[v][u]=999;
    }
    printf("\nminimum cost:%d",mincost);
}


int find(int i) 
{ 
    while(parent[i]) 
    i=parent[i];  
    return i; 
} 


int uni(int i,int j) 
{ 
    if(i!=j) 
   { 
      parent[j]=i;  
      return 1; 
   }
}


void kruskals(int n,int cost[m][m])
{
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                 if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=a=i;
                v=b=j;
            }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("%d edge (%d-%d)=%d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    
printf("Minimum cost = %d\n",mincost); 
}


int main()
{
    int choice;
    printf("enter choice to choose an algorithm  to find minimum cost spanning tree:");
    printf("\nenter\n1.Prims algorithm\n2.Kruskal algorithm");
    printf("\nenter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
          printf("enter no of nodes:");
          scanf("%d",&n);
          printf("enter the adjacency matrix:\n");
          for(int i=1;i<=n;i++)
          {
            for(j=1;j<=n;j++)
            {
              scanf("%d",&cost[i][j]);
              if(cost[i][j]==0)
            {
                cost[i][j]=999;
            
            }
        }
    }
          clock_t start=clock();
          prims(n,cost);
          clock_t end=clock(); 
          printf("\nStart time is %lf\n",(double)start);  
          printf("\nEnd time is %lf\n",(double)end);  
          printf("\nTotal time is %lf\n",(double)(end-start));
          break;
        }
        case 2:
        {
            printf("enter no of nodes:");
            scanf("%d",&n);
            printf("enter the adjacency matrix:\n");
           for(int i=1;i<=n;i++)
           {
             for(j=1;j<=n;j++)
             {
               scanf("%d",&cost[i][j]);
               if(cost[i][j]==0)
               {
                  cost[i][j]=999;
            
               }
                 
            }
    }
          clock_t start=clock();
          kruskals(n,cost);
          clock_t end=clock(); 
          printf("\nStart time is %lf\n",(double)start);  
          printf("\nEnd time is %lf\n",(double)end);  
          printf("\nTotal time is %lf\n",(double)(end-start));
          break;
        }
        default:
        printf("enter correct choice!!");
    }
return 0; 
} 