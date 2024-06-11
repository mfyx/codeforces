#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }

        if(n<=2) {
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
            if(a[i-1]<a[i] && a[i]<a[i+1])
                num = a[i];
            if(a[i-1]>a[i] && a[i]>a[i+1])
                num = a[i];

            if(a[i]<a[i-1] && a[i-1]<a[i+1])
                num = a[i-1];
            if(a[i]>a[i-1] && a[i-1]>a[i+1])
                num = a[i-1];

            if(a[i-1]<a[i+1] && a[i+1]<a[i])
                num = a[i+1];
            if(a[i-1]>a[i+1] && a[i+1]>a[i])
                num = a[i+1];

            if(a[i-1] == a[i])
                num = a[i];
            if(a[i] == a[i+1])
                num = a[i];
            if(a[i-1] == a[i+1])
                num = a[i-1];

            maxnum = max(maxnum, num);
        }

        cout<<maxnum<<endl;
    }

    return 0;
}


