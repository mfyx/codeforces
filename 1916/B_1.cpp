#include <iostream>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    ll r;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

void solve() {
	ll a, b; cin >> a >> b;
    ll x = gcd(a, b);
    if (x == a||x==b) {
        ll ans = max(a, b) * max(a / x, b / x);
        cout << ans << '\n';
    }
    else {
        ll ans = a / x * b;
        cout << ans << '\n';
    }
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
