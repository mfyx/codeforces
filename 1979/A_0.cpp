#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 5e4+5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        priority_queue<int, vector<int>, greater<int>> pq;
        cin>>a[0];
        for(int i = 1; i < n; i++) {
            cin>>a[i];
            pq.push(max(a[i], a[i-1]));
        }

        cout<<pq.top()-1<<endl;
        /*while(!pq.empty()) {
            cout<<pq.top()<<endl;
            pq.pop();
        }*/
    }

    return 0;
}

