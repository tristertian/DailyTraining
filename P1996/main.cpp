//循环队列写法

#include<iostream>
#include <queue>
int main(){
    int n, m;
    std::queue<int>q;

    std::cin >> n >> m;
    for (int i=1; i<=n; i++) {
        q.push(i);
    }
    for (int i=0; i<n; i++) {
        for (int i=1; i<m; i++) {
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front() << ' ';
        q.pop();
    }
}