#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e9+5;
//const int maxn = 1e2+5;
vector<int> p;
//bool is_prime[maxn];
vector<bool> is_prime(maxn, true);

void sieve() {
    for(int i = 2; i < maxn; i++) {
        if(is_prime[i]) {
            p.push_back(i);
            for(int j = 2*i; j*j < maxn; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;
    sieve();

    for(int i = 0; i < p.size(); i++)
        cout<<p[i]<<' ';


    while(tt--) {

    }

    return 0;
}


