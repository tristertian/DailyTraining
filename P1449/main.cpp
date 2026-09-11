#include <cstdio>
#include <iostream>
#include <stack>
int main(){
    std::stack<int>s;
    char ch;
    int num = 0;
    do {
        ch = getchar();
        if (ch >= '0' && ch <= '9') {
            num = (num*10)+(ch-'0');
        }else if (ch == '.') {
            s.push(num);
            num = 0;
        }else if (ch != '@') {
            int L_operator, R_operator;
            R_operator = s.top();   s.pop();
            L_operator = s.top();   s.pop();
            if (ch == '+') {
                s.push(L_operator+R_operator);
            }else if (ch == '-') {
                s.push(L_operator-R_operator);
            }else if (ch == '*') {
                s.push(L_operator*R_operator);
            }else if (ch == '/') {
                s.push(L_operator/R_operator);
            }
        }
    } while(ch != '@');
    std::cout << s.top() << '\n';
    return 0;
}