#include <iostream>
using namespace std;

void solve() {
    int n; cin>>n;
    
    //for(int i = 2; i <= 32; i++) {
    for(int i = 32; i >= 2; i--) {      //32到2
        int j = i;
        int num = 0;
        int d = 1;
        while(j){
            num+=(j&1)*d;
            j = j>>1;
            d*=10;
        }
        while(n % num == 0) {
            n/=num;
        }
        if(n == 1) break;
    }

    if(n == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
