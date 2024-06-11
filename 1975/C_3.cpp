#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;
    int test = 0;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }

        if(++test == 39) {
            cout<<"test "<<test<<": ";
            for(int i = 0; i < n; i++) 
                cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }
        
        if(n==2) {
            //cout<<a[0]<<endl;
            if(a[0]<a[1])
                cout<<a[0]<<endl;
            else
                cout<<a[1]<<endl;
            continue;
        }

        int maxnum = -1;
        for(int i = 1; i < n-1; i++) {
            int num = -1;

            priority_queue<int> pq;
            pq.push(a[i-1]);
            pq.push(a[i]);
            pq.push(a[i+1]);

            pq.pop();
            num = pq.top();
            
            maxnum = max(maxnum, num);
        }

        cout<<maxnum<<endl;
    }

    return 0;
}



