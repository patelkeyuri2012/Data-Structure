#include<stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
	if(x=='\n')
	{
		return;
	}
	else
	{
		stack[++top] = x;	
	}
    
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}


int pre(char op)
{
	if(op == '*' || op == '/')
	{
		return (2);
	}
	if(op == '+' || op == '-')
	{
		return (1);
	}	  	
	if(op == '(' || op == ')')
	{
		return (0);
	}	 
}

int main(){
	char ch, sop;
	
	printf("Enter expression to convert Infix to Postfix that end with $ : ");
	
	do
	{	
		scanf("%c",&ch);
				
		if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
		{
			printf("%c",ch);
		}
		else
		{
			if (top == -1)
			{
				push(ch);
			}
			else if(ch == '(')
			{
				push(ch);
			}
			else if(ch == ')')
			{
				printf("%c",pop());
			
				while (stack[top] != '(')
				{
					sop = pop();
					printf("%c",sop);
				}
				pop();	
			}
			else
			{
				while (pre (stack[top]) >= pre(ch))
				{
					sop = pop();
					printf("%c",sop);
				}
				push(ch);
			}
		}
		if (ch == '\n')
		{
			
			while (top != -1)
			{
				sop = pop();
				printf("%c",sop);
				
			}
		}
	}
	while(ch != '\n');
}

