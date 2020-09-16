#include<stdio.h>
using namespace std;

class Int_stack
{ 
private:
	int arr[1000];
	int size, top;
public:
	Int_stack()
	{
		top = -1;
		size = 0;
	}

	void push(int elem)
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

	int pop()
	{
		if(size == 0)	return '\0';
		else
		{
			int temp = arr[top];
			top--;
			size--;
			return temp;
		}
	}


	int get_top()
	{
		if(size == 0)	return -1;
		else
			return arr[top];
	}
};


int main()
{
	Int_stack num;
	char temp;
	scanf("%c", &temp);
	while(temp != '\n')
	{
		if(temp != ' ')
		{
			if(temp <= '9' && temp >='0')
			{
				num.push(int(temp) - 48);
			}
			else 
			{
				switch(temp)
				{
					case '+':
						num.push(num.pop() + num.pop());
						break;
					case '*':
						num.push(num.pop() * num.pop());
						break;
					case '-':
					{
						int a = num.pop();
						int b = num.pop();
						num.push(b-a);
						break;
					}
					case '/':
					{
						int a = num.pop();
						int b = num.pop();
						num.push(b/a);
						break;
					}
					default:
						printf("Error\n");
				}
			}
		}
		scanf("%c", &temp);
	}
	printf("%d\n", num.pop());
	return 0;
}
