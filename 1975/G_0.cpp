#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(string& p, string& s) {
    int m, n;
    m=s.length();
    n=p.length();
    
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    
    dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        
        // 状态转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '-') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '-') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

    return dp[m][n];
}

int main() {
    string p, s;
    int n, m;

    cin>>n>>m;
    cin>>p>>s;

    bool flag = false;
    if(solve(p, s)) {
        cout<<"YES"<<endl;
        return 0;
    }

    if(solve(s, p)) {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
}

