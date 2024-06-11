#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n, m;
        cin>>n>>m;
        
        if(n < m) {
            cout<<"NO"<<endl;
            continue;
        }

        if(n == m) {
            cout<<"YES"<<endl;
            continue;
        }

        if((n-m)%2 == 0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

