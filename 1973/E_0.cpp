#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
const int maxn = 1e5+5;
int p[maxn];

signed main() {
    ios::sync_with_stdio(false);
    int T; cin>>T;

    while(T--) {
        int n; cin>>n;
        for(int i = 1; i <= n; i++) 
            cin>>p[i];

        //int cnt2 = 0;
        set<int> cnt2;
        for(int i = 1; i <= n; i++) {
            if(p[i] != i) {
                //cnt2++;
                cnt2.insert(i + p[i]);
            }
        }

        int cnt;
        if(cnt2.size() == 1)
            cnt = 1;
        else if(cnt2.size() == 0) {
            n*=2;
            cnt = n*(n+1)/2;
            cout<<cnt<<endl;
            continue;
        } else
            cnt = 0;
        //cout<<"cnt2: "<<cnt2<<endl;
        //cout<<"cnt: "<<cnt<<endl;

        int L = maxn, R = -1;
        for(int i = 1; i <= n; i++) {
            if(p[i] != i) {
                L = min(L, p[i]);
                R = max(R, p[i]);
            }
        }

        int l = L+n;
        int r = R+1;
        int maxr = 2*n;

        //int len = maxr-r+1;
        //cnt += (l*len - (l-r+1));
        for(int i = 1; i<=l; i++) {
            /*int j = max(r, i);
            int len = maxr - j + 1;
            cnt+=len;*/

            for(int j = r; j<=maxr; j++) {
                if(i < j)
                    cnt++;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}

/*
1~5 5~8
1   5 6 7 8
2
3
4

5   6 7 8

*/

