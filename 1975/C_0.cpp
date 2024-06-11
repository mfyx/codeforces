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
        int num = 0;
        int lastnum = 0;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
            lastnum = num;
            num = max(num, a[i]);
        }

        if(a[n-1] == num) {
            cout<<lastnum<<endl;
        } else {
            cout<<num<<endl;
        }
    }

    return 0;
}


