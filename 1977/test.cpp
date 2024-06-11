#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 辅助函数：计算两个数的最大公约数（GCD）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 辅助函数：计算两个数的最小公倍数（LCM）
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// 主函数：计算优先队列中所有数的最小公倍数（LCM）
int findPriorityQueueLCM(std::priority_queue<int> pq) {
    if (pq.empty()) {
        return 0; // 如果优先队列为空，返回0
    }
    
    int result = pq.top();
    pq.pop();

    while (!pq.empty()) {
        result = lcm(result, pq.top());
        pq.pop();
    }

    return result;
}

int main() {
    // 创建一个优先队列，并按从大到小的顺序存储数字
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(10);
    pq.push(20);
    
    // 计算并输出优先队列中所有数的最小公倍数
    std::cout << "LCM of all numbers in the priority queue: " << findPriorityQueueLCM(pq) << std::endl;
    
    return 0;
}
