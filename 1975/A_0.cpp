#include <iostream>
using namespace std;
const int maxn = 55;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];

        if(n <= 1) {
            cout<<"YES"<<endl;
            continue;
        }

        int now = 0;
        int pre = 1;

        int cnt = 0;
        while(pre<n) {
            while(a[now] <= a[pre] && pre < n) {
                now++;
                pre++;
            }
            if(pre == n)
                break;
            cnt++;
            now++;
            pre++;
        }

        if(cnt > 1) {
            cout<<"NO"<<endl;
        } else if(cnt == 1){
            if(a[0] >= a[n-1])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}

