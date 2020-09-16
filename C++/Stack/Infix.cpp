#include<stdio.h>
using namespace std;

class Stack
{
private:
	char arr[1000];
	int size, top;
public:
	Stack()
	{
		top = -1;
		size = 0;
	}

	void push(char elem)
	{
		if(size == 1000)
		{
			printf("Stack FULL!\n");
		}
		else
		{
			top++;
			arr[top] = elem;
			size++;
		}
	}

	char pop()
	{
		if(size == 0)	return '\0';
		else
		{
			char temp = arr[top];
			top--;
			size--;
			return temp;
		}
	}


	char get_top()
	{
		if(size == 0)	return '\0';
		else
			return arr[top];
	}

	bool is_empty()
	{
		return (size == 0);
	}

	void print()
	{
		for(int i=0; i<size; i++)
		{
			printf("%d ",int(arr[i]));
        }
        printf("\n");
    }
};

int precedence_of(char op)
{
	if(op == '+' || op == '-')	return 1;
	else if(op == '*' || op == '/')	return 2;
	return 0;
}

int do_op(char op, int num1, int num2)
{
	// printf("OP: %c", op);
	switch(op)
    {
        case '+':
        	return (num1 + num2);
        case '-':
        	return ((num1) - (num2));
        case '*':
 	      	return ((num1) * (num2));
        case '/':
        	return ((num1) / (num2));
        default:
        	printf("Error occured in switch-case\n");
        	return 0;
    }
}

int main()
{
	Stack op, num;
	char temp;
	printf("Enter your expression: ");
    while(1)
    {
        scanf("%c", &temp);
        if(temp == '\n') 	break;
        else if(temp != ' ')
        {
        	if(temp<='9' && temp>='0')	num.push(int(temp) - 48);	// If a number
        	// If an operator or a parenthesis
        	else if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '(' || temp == ')')
        	{
        		if(temp == '(')	op.push(temp);
        		else if(temp == ')')
        		{
        			// printf("op.get_top() == %c\n", op.get_top());
        			while(op.get_top() != '(')
        			{
        				// if(op.get_top()!='\0')
        					num.push(do_op(op.pop(),num.pop(), num.pop()));
        				// else
        				// 	printf("ERROR\n");
        				// 	// op.print();
        				// 	break;
        			}
        			op.pop();

        		}
        		else
        		{
        			while(!op.is_empty() && precedence_of(op.get_top())>=precedence_of(temp))
        			{
        				num.push(do_op(op.pop(),num.pop(),num.pop()));
        			}
        			op.push(temp);
        		}
        	}

        	else	{printf("INVALID EXPRESSION!"); break;}
    	}
    	// printf("*******OP stack:");
    	// op.print();
    	// printf("******NUM stack:");
    	// num.print();
    }
    // printf("Num stack:");
    // num.print();
    // printf("Op stack:");
    // op.print();	
    while(!op.is_empty())
    {
    	num.push(do_op(op.pop(),num.pop(),num.pop()));
    }
    num.print(); 
    // op.print(); //To check if stack is empty at the end
	return 0;
}
