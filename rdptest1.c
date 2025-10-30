#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void S();
void L();
void Lprime();

char input[20];
int i=0,error=0;

void main()
{
	printf("Enter the expression : ");
	gets(input);
	S();
	if(strlen(input)==i && error==0)
	{
		printf("Accepted..\n");
	}
	else
	{
		printf("Rejected..\n");
	}
}

void S()
{
	if(input[i]=='(')
	{
		i++;
		L();
		if(input[i]==')')
		{
			i++;
		}
		else error=1;
	}
	else if(input[i]=='a')
	{
		i++;
	}
	else error=1;
}
void L()
{
	S();
	Lprime();
}

void Lprime()
{
	if(input[i]==',')
	{	
		i++;
		S();
		Lprime();
	}
}
		
		
		
		
		
		
