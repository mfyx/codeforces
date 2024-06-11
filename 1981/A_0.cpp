#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int maxn = 1e3+5;
bool p[maxn];
vector<int> prime;

void sieve() {
    for(int i = 2; i < maxn; i++)
        p[i] = true;
    for(int i = 2; i < maxn; i++) {
        if(p[i] == true) {
            prime.push_back(i);
        }
        for(int val : prime) {
            if(i*val < maxn)
                p[i*val] = false;
        }
    }
}

void solve() {

}

signed main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    sieve();

    while(tt--) {
        //solve();

        for(int val : prime) {
            cout<<val<<' ';
        }
        cout<<endl;
    }

    return 0;
}

