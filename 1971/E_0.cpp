#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 1e5+5;
int a[maxn], b[maxn];
int qu[maxn];
//int last[1000000005];

signed main() {
    std::ios_base::sync_with_stdio(false);
    int t; cin>>t;
    
    while(t--) {
        int n, k, q;
        cin>>n>>k>>q;
        a[0] = 0;
        b[0] = 0;
        for(int i = 1; i <= k; i++)
            cin>>a[i];
        for(int i = 1; i <= k; i++)
            cin>>b[i];

        for(int i = 0; i < q; i++)
            cin>>qu[i];

        for(int i = 0; i < q; i++) {
            int j = 0;
            while(a[j] < qu[i])
                j++;
            j--;
            
            //int ans = (double)(qu[i]-b[j]) / ( (a[j+1]-a[j]) / (b[j+1]-b[j]) );
            int ans = (double)(qu[i]-a[j]) / ( (double)(a[j+1]-a[j]) / (b[j+1]-b[j]) );
            ans += b[j];
            if(ans < 0) ans = 0;
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}

