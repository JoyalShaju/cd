#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char data[20][20],str[20],operation[20];
	int i=0;
	printf("Enter the arguements : \n");
	do
	{
		scanf("%s",data[i]);
	}while(strcmp(data[i++],"exit")!=0);
	
	i=0;
	do
	{
		strcpy(str,data[i]);
		switch(str[3])
		{
			case '+' : strcpy(operation,"ADD");
			break;
			case '-' : strcpy(operation,"SUB");
			break;
			case '*' : strcpy(operation,"MUL");
			break;
			case '/' : strcpy(operation,"DIV");
			break;
		}
		printf("\n MOV %c R%d",str[2],i);
		printf("\n %s  %c R%d",operation,str[4],i);
		printf("\n MOV R%d %c",i,str[0]);
	}while(strcmp(data[++i],"exit")!=0);
}
