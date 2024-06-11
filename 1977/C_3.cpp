#include <iostream>
#include <queue>
#include <set>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int lcm2(priority_queue<int> pq) {
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
    ios::sync_with_stdio(false);
    int tt; cin>>tt;
    
    while(tt--) {
        int n; cin>>n;
        priority_queue<int> pq;
        set<int> s;
        int t;

        for(int i = 0; i < n; i++) {
            cin>>t;
            pq.push(t);
            s.insert(t);
        }

        int cnt = n;
        int maxnum = pq.top();
        int m = 0;
        //while(m=lcm2(pq) && maxnum == lcm2(pq) || pq.top()==lcm2(pq)) {
        //while(m=lcm2(pq) && (maxnum == m || pq.top()==m) ) {
        //while(maxnum == lcm2(pq) || pq.top() == lcm2(pq)) {
        while(s.count(lcm2(pq))) {
            cout<<"lcm: "<<lcm2(pq)<<endl;
            cout<<"top: "<<pq.top()<<endl;
            pq.pop();
            cnt--;
        }

        cout<<cnt<<endl;
    }

    return 0;
}
