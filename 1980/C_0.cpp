#include <iostream>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];

int gcd(int a, int b) {
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int n; cin>>n;
    bool flag = false;

    for(int i = 0; i < n; i++)
        cin>>a[i];

    int gcdn = 1;
    for(int i = 1; i < n; i++) {
        int t = gcd(a[i-1], a[i]);
        if(gcdn <= t) {
            gcdn = t;
        } else {
            if(flag == false)
                flag = true;
            else {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        solve();
    }

    return 0;
}

