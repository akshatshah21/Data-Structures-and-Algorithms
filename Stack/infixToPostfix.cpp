#include <iostream>
#include<cstdio>
#include <string>
using namespace std;

class Stack {
private:
	char arr[1000];
	int size, top;
public:
	Stack() {
		top = -1;
		size = 0;
	}

	void push(char elem) {
		if(size == 1000)
			cout<<"Stack FULL\n";
		else {
			top++;
			arr[top] = elem;
			size++;
		}
	}

	char pop() {
		if(size == 0)	return '\0';
		else {
			char temp = arr[top];
			top--;
			size--;
			return temp;
		}
	}

	char get_top() {
		if(size == 0)	return '\0';
		else	return arr[top];
	}

	bool is_empty() {
		return (size == 0);
	}
	
};

int precedence_of(char op) {
	if(op == '+' || op == '-')	return 1;
	if(op == '*' || op == '/')	return 2;
	if(op == '(')	return 3;
	return 0;
}


int main() {
	Stack op;
	string result = "";
	cout<<"Enter infix expression: ";
	char c = getchar();
	while(c != '\n') {
		if(c <= '9' && c >= '0')	{result += c; result += ' ';}
		else if(c == '(') 	op.push(c);
		else if(c == '+' || c == '-' || c == '*' || c == '/') {
			if(!op.is_empty()) 
				while(precedence_of(c) <= precedence_of(op.get_top()) && op.get_top()!= '(') 
					{
						
						result += op.pop(); result += ' ';
					}

			op.push(c);
		}
		else if(c == ')') {
			while(op.get_top() != '(')
				{result += op.pop(); result += ' ';}
			op.pop();
		}
		else if (c!= ' ')	cout<<"Invalid expression\n";
		c = getchar();
	}
	while(!op.is_empty()) {
		result += op.pop(); result += ' ';
	}
	cout<<"Postfix expression: "<<result<<endl;
	return 0;
}
