#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::vector<int>stu;

    std::cin >> n >> m;
    int num = 0;
    for(int i=0; i<n; i++){
        std::cin >> num;
        stu.push_back(num);
    }
    for (int i=0; i<m; i++) {
        std::cin >> num;
        std::cout << stu[num-1] << std::endl;
    }
    return 0;
}