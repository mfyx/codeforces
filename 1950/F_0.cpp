#include <iostream>
using namespace std;


void solve() {
    int a, b, c;
    cin>>a>>b>>c;

    if(2*a+b+1 != a+b+c) {
        cout<<"-1"<<endl;
        return;
    }

    int n = 2*a+1*b+0*c;
    int i = 2;
    int h = 0;
    while(n > 0) {
        n-=i;
        //a-=i/2;
        i*=2;

        h++;
    }

    cout<<h<<endl;
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
