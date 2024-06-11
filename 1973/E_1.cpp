#include <iostream>
#include <set>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int p[maxn];

signed main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;

    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) 
            cin >> p[i];

        set<int> cnt2;
        int L = maxn, R = -1;
        for (int i = 1; i <= n; ++i) {
            if (p[i] != i) {
                cnt2.insert(i + p[i]);
                L = min(L, p[i]);
                R = max(R, p[i]);
            }
        }

        int cnt;
        if (cnt2.size() == 1) {
            cnt = 1;
        } else if (cnt2.size() == 0) {
            n *= 2;
            cnt = n * (n + 1) / 2;
            cout << cnt << '\n';
            continue;
        } else {
            cnt = 0;
        }

        int l = L + n;
        int r = R + 1;
        int maxr = 2 * n;

        // 利用数学公式优化内部循环

        for(int i = 1; i <= l; ++i) {
            if (i < r) {
                cnt += (maxr - r + 1);
            } else if (i < maxr) {
                cnt += (maxr - (i + 1) + 1);
            }
        }

        /*
        for(int i = 1; i <= l; ++i) {
            for(int j = r; j <= maxr; ++j) {
                if(i < j)
                    ++cnt;
            }
        }*/

        cout << cnt << '\n';
    }

    return 0;
}

