#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 2e5+5;
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < n+1; i++)
            cin>>b[i];

        int cnt = 0;
        //int minnum = maxn;
        //int maxnum = -1;
        int dis = maxn;
        int num = b[n];
        bool flag = false;
        for(int i = 0; i < n; i++) {
            cnt += abs(a[i]-b[i]);
            //minnum = min(minnum, b[i]);
            //maxnum = max(maxnum, b[i]);
            //minnum = min(minnum, a[i]);
            //maxnum = max(maxnum, a[i]);

            dis = min(dis, abs(a[i]-num));
            dis = min(dis, abs(b[i]-num));

            if(a[i]<=num && num<=b[i])
                flag = true;
            if(a[i]>=num && num>=b[i])
                flag = true;
        }

        if(flag) {
            cout<<cnt+1<<endl;
            continue;
        }

        //int dis = min(abs(num-minnum), abs(num-maxnum));
        cout<<cnt+dis+1<<endl;

    }

    return 0;
}

