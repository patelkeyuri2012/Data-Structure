#include<stdio.h>
#include<string.h>

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

int main() 
{
    char ch[100], sop;
    char prefix[100];

    printf("Enter expression to convert Infix to Prefix that ends with $ : ");
    scanf("%s", &ch);

    strrev(ch);

    int prefixIdx = 0; 

    for (int i = 0; i < strlen(ch); i++) 
	{
        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= '0' && ch[i] <= '9')) 
		{
            prefix[prefixIdx++] = ch[i];
        } 
		else if (ch[i] == ')') 
		{
            push(ch[i]);
        } 
		else if (ch[i] == '(') 
		{
            while (top != -1 && stack[top] != ')') 
			{
                sop = pop();
                prefix[prefixIdx++] = sop;
            }
            if (top != -1 && stack[top] == ')') 
			{
                pop();
            }
        } 
		else 
		{
            while (top != -1 && pre(stack[top]) >= pre(ch[i])) 
			{
                sop = pop();
                prefix[prefixIdx++] = sop;
            }
            push(ch[i]);
        }
    }

    while (top != -1) 
	{
        sop = pop();
        prefix[prefixIdx++] = sop;
    }
    
    strrev(prefix);
    printf("Prefix expression : %s", prefix);
	return 0;
}


