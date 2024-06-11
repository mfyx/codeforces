#include <iostream>
#include <queue>
using namespace std;
const int maxn = 55;
int a[maxn];
deque<int> q[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];

        int cnt = 0;
        for(int i = 0; i < n-1; ) {
            while(a[i] < a[i+1]) {
                q[cnt].push_back(a[i++]);
            }
            q[cnt].push_back(a[i++]);
            cnt++;
            //i++;
        }

        int t = 0;
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j < q[i].size(); j++)
                cout<<q[i][j]<<' ';
            cout<<endl;
        }

        if(cnt <= 1) {
            cout<<"YES"<<endl;
        } else if(cnt == 2) {
            if(q[0].front() >= q[1].back())
                cout<<"YES"<<endl;
        }
        

    }

    return 0;
}

