#include<stdio.h>
#include<string.h>
#include<ctype.h>

int keyword(char *buffer)
{
	char *key[4]={"int","void","printf","main"};
	for (int i=0;i<4;i++)
	{
		if(strcmp(buffer,key[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	FILE *fp;
	int i;
	char buffer[100],ch;
	fp=fopen("test1.c","r");
	if(fp==NULL)
	{
		printf("Error while opening file\n");
		return 1;
	}
	while((ch=fgetc(fp))!=EOF)
	{
		i=0;
		if(ch==' ' || ch=='\t' || ch=='\n')
		{
			continue;
		}
		else if (isalpha(ch) || ch=='_')
		{
			buffer[i++]=ch;
			ch=fgetc(fp);
			while(isalnum(ch) || ch=='_')
			{
				buffer[i++]=ch;
				ch=fgetc(fp);
			}
			buffer[i]='\0';
			if(keyword(buffer)==1)
			{
				printf("Keyword : %s\n",buffer);
			}
			else
			{
				printf("Identifier : %s\n",buffer);
			}
			ungetc(ch,fp);
		}
		else if(isdigit(ch))
		{
			buffer[i++]=ch;
			ch=fgetc(fp);
			while(isdigit(ch))
			{
				buffer[i++]=ch;
				ch=fgetc(fp);
			}
			buffer[i]='\0';
			if(isalpha(ch))
			{
				printf("Invalid Token\n");
				while(isalnum(ch))
				{
					ch=fgetc(fp);
				}
			}
			else
			{
				printf("Digit : %s\n",buffer);
				ungetc(ch,fp);
			}
		}
		else if(ch == '(' || ch == ')' || ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ||ch == '{' ||ch == '}' ||ch == ';' ||ch == '>' || ch == '<' || ch == '=' )
		{
			printf("Symbols/operator : %c\n",ch);
		}
		else if(ch=='"')
		{
			printf("String Literal : ");
			while((ch=fgetc(fp))!='"' && ch!=EOF)
			{
				printf("%c",ch);
			}
		}
	}
	fclose(fp);
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
