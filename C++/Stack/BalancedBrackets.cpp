/* Question link (HackerRank): https://www.hackerrank.com/challenges/balanced-brackets/problem */
/* Without using STL stack */
char arr[1000];
int top = -1;
void push(char c) {
   arr[++top] = c;  
}
char pop() {
    return arr[top--];
}
char get_front() {
    return arr[top];
}
// Complete the isBalanced function below.
string isBalanced(string s) {
    top = -1;   // since this func is called for multiple testcases and there is only one global stack
    for(auto i: s) {
        if(i == '(' || i == '{' || i == '[') {
            push(i);
        }
        else {
            if(top == -1)   return "NO";
            switch(i) {
                case ')':
                    if(get_front() == '(')  pop();
                    else    return "NO";
                    break;
                case '}':
                    if(get_front() == '{')  pop();
                    else    return "NO";
                    break;
                case ']':
                    if(get_front() == '[')  pop();
                    else    return "NO";
                    break;
            }
        }
    }
    if(top != -1)   return "NO";    // stack should be empty after expression is over, else surplus opening brackets
    return "YES";
}