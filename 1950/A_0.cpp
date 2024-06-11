#include <iostream>
using namespace std;

void solve() {
    int a, b, c;
    cin>>a>>b>>c;
    if(a<b && b<c) cout<<"STAIR"<<endl;
    else if(b>a && b>c) cout<<"PEAK"<<endl;
    else cout<<"NONE"<<endl;
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
