#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//#define int long long
const int inf = 150005;

vector< vector<int> > factors(inf);

void init_factors() {
    for (int i = 1; i < inf; ++i) {
        for (int j = i; j < inf; j += i) {
            factors[j].push_back(i);
        }
    }
}

int main() {
    init_factors();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), sum(n);

        cin >> a[0];
        sum[0] = a[0];
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        
        bool all_same = true;
        for(int i = 1; i < n; ++i) {
          if(a[i]!=a[0]) {
            all_same = false;
            break;
          }
        }
        if(all_same) {
          cout<<0<<endl;
          continue;
        }
        
        int ans = 0;
        for (int k : factors[n]) {
            if (k > n) {
                break;
            }
            int maxn = -1, minn = n * 1e9;
            for (int j = 0; j < n; j += k) {
                int cur_sum = sum[j + k - 1] - (j == 0 ? 0 : sum[j - 1]);
                maxn = max(maxn, cur_sum);
                minn = min(minn, cur_sum);
            }
            ans = max(ans, maxn - minn);
        }
        cout << ans << endl;
    }

    return 0;
}

