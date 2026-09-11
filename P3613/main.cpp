#include <iostream>
#include <vector>
int main(){
    int n, q;
    int op, op_i, op_j, op_k;
    std::cin >> n >> q;
    std::vector<int>cab[n+1];

    for (int i=0; i<q; i++) {
        std::cin >> op >> op_i >> op_j;
        if (op == 1) {
            std::cin >> op_k;
            if (cab[op_i].size() < op_j) {
                cab[op_i].resize(op_j+1);
            }
            cab[op_i][op_j] = op_k;
        }
        if (op == 2) {
            std::cout << cab[op_i][op_j] << '\n';
        }
    }
    return 0;
}