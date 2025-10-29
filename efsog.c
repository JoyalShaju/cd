#include<stdio.h>
#include<string.h>
#define MAX 20

int e[MAX][MAX],vis[MAX],states;

void dfs(int state)
{
	vis[state]=1;
	for (int i =0;i<states;i++)
	{
		if(e[state][i] && !vis[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int i,j,n,from,to;
	printf("Enter the number of states : ");
	scanf("%d",&states);
	memset(e,0,sizeof(e));
	printf("Enter the number of epsilon transition : ");
	scanf("%d",&n);
	printf("Enter the transition\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&from,&to);
		e[from][to]=1;
	}
	for (i=0;i<states;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i);
		printf("\nE-Closure (%d) : ",i);
		for(j=0;j<states;j++)
		{
			if(vis[j])
			{
				printf("%d",j);
			}
		}
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
