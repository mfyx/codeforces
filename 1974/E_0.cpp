#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, x;
        cin >> m >> x;
        vector<int> c(m), h(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i] >> h[i];
        }

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= m; ++i) {
            dp[i] = dp[i - 1]; // 不买当前月的幸福
            for (int j = 0; j < i; ++j) {
                if ((i - j) * x >= c[i - 1]) {
                    dp[i] = max(dp[i], dp[j] + h[i - 1]);
                }
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
