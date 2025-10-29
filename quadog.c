#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char exp[20],op[20],arg1[20],arg2[20];
	char operators[]="/*+-";
	int i,j,count=0;
	printf("Enter the expression : ");
	scanf("%s",exp);
	for(j=0;j<4;j++)
	{
		for(i=0;exp[i];i++)
		{
			if(exp[i]==operators[j])
			{
				op[count]=exp[i];
				arg1[count]=exp[i-1];
				arg2[count]=exp[i+1];
				exp[i-1]=count+'0';
				strcpy(&exp[i],&exp[i+2]);
				count++;
				i=-1;
			}
		}
	}
	printf("\n--- Three Address Code ---\n");
	for(i=0;i<count;i++)
	{
		printf("t%d =",i+1);
		isdigit(arg1[i]) ? printf("t%d",arg1[i] - '0' + 1) : printf("%c",arg1[i]);
		printf("%c",op[i]);
		isdigit(arg2[i])? printf("t%d\n",arg2[i] - '0' +1) : printf("%c\n",arg2[i]);
	}
	printf("\n--- Quadruple ---\nOp\tArg1\tArg2\tResult\n");
	for(i=0;i<count;i++)
	{
		printf("%c\t",op[i]);
		isdigit(arg1[i]) ? printf("t%d\t",arg1[i]-'0'+1) : printf("%c\t",arg1[i]);
		isdigit(arg2[i]) ? printf("t%d\t",arg2[i]-'0'+1) : printf("%c\t",arg2[i]);
		printf("t%d\n",i+1);
	}
	printf("\n--- Triple ---\nPos\tOp\tArg1\tArg2\n");
	for(i=0;i<count;i++)
	{
		printf("(%d)\t%c\t",i,op[i]);
		isdigit(arg1[i]) ? printf("(%c)\t",arg1[i]) : printf("%c\t",arg1[i]);
		isdigit(arg2[i]) ? printf("(%c)\n",arg2[i]) : printf("%c\n",arg2[i]);
	}
}
	
	
	
	
	
	
	
	
	
	
