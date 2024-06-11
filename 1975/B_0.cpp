#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3e5+5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
            if(a[i] == 1)
                flag = true;
        }
        if(flag) {
            cout<<"YES"<<endl;
            continue;
        }

        sort(a, a+n);

        int i = 1;
        while(a[i]%a[0]==0 && i<n) {
            i++;
        }
        if(i == n) {
            cout<<"YES"<<endl;
            continue;
        }

        int j = i+1;
        while((a[j]%a[0]==0 || a[j]%a[i]==0) && j<n) {
            j++;
        }

        if(j == n) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}

