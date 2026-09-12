// 双向链表（doublely linked list）

#include<iostream>

struct node{
    int key, pre, nxt;
    node(int key=0, int pre=0, int nxt=0): key(key), pre(pre), nxt(nxt){

    }
};

node s[100000];
// 有N个同学进行排序，有M个同学会被去除；tot为已经使用的节点编号数
int n, m, tot = 0;
// 用index数组记录每一个节点的编号，index[0]表示0号同学（不存在）
int index[100000] = {0};

// 何意味：把数据y插入数据x后面
void insertBack(int x, int y){
    index[y] = ++tot;
    s[index[y]] = node(y, index[x], s[index[x]].nxt);
    s[index[x]].nxt = index[y];
    s[s[index[x]].nxt].pre = index[y];
}
// 何意味：把数据y插入数据x后面
void insertFront(int x, int y){
    index[y] = ++tot;
    s[index[y]] = node(y, s[index[x]].pre, index[x]);
    s[s[index[x]].pre].nxt = index[y];
    s[index[x]].pre = index[y];
}
void del(int x){
    if (index[x] != 0) {
        s[s[index[x]].pre].nxt = s[index[x]].nxt;
        s[s[index[x]].nxt].pre = s[index[x]].pre;
        index[x] = 0;
    }
}

int main(){
    std::cin >> n;
    s[0] = node();          // s[0]恒为最左边的节点
    insertBack(0, 1);
    int k, p;
    for (int i=2; i<=n; i++) {
        std::cin >> k >> p;
        (p == 1) ? insertBack(k, i) : insertFront(k, i);
    }

    std::cin >> m;
    int x;
    for (int i=0; i<m; i++) {
        std::cin >> x;
        del(x);
    }

    int now = s[0].nxt;
    for (int i=0; i<tot; i++) {
        std::cout << s[now].key << ' ';
        now = s[now].nxt;
    }
}