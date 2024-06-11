#include <iostream>
using namespace std;

void solve() {
    int n; cin>>n;
    char c;
    for(int i = 0; i < n; ++i) {


        for(int j = 0; j < 2*n; ++j) {
            if(i % 2 == 0) {
                if(j%4 == 0 || j%4 == 1) c = '#';
                else c = '.';
            } else {
                if(j%4 == 0 || j%4 == 1) c = '.';
                else c = '#';
            }
            cout<<c;
        }
        cout<<endl;
        for(int j = 0; j < 2*n; ++j) {
            if(i % 2 == 0) {
                if(j%4 == 0 || j%4 == 1) c = '#';
                else c = '.';
            } else {
                if(j%4 == 0 || j%4 == 1) c = '.';
                else c = '#';
            }
            cout<<c;
        }
        cout<<endl;

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    int T; cin>>T;
    while(T--) {
        solve();
    }

    return 0;
}
