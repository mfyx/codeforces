#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n, m;
        cin>>n>>m;

        if(m == 0) {
            cout<<n<<endl;
            continue;
        }

        int num = 0;
        for(int i = n-m; i <= n+m; i++) {
            if(i >= 0)
                num = num|i;
        }
        cout<<num<<endl;

    }

    return 0;
}

