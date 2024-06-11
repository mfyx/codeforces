#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

const int MAX_D = 1000; // 根据题解，我们需要根据实际数据选择合适的值
vector<vector<int>> P(MAX_D, vector<int>(MAX_D, 0));
vector<vector<int>> S(MAX_D, vector<int>(MAX_D, 0));

void precompute(const vector<int>& a, const vector<int>& b, const vector<int>& c, const vector<int>& a1_factors, const vector<int>& b1_factors) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int x : a1_factors) {
            for (int y : b1_factors) {
                if (a[i] % x == 0 && b[i] % y == 0) {
                    P[x][y]++;
                } else if (a[i] % y == 0 && b[i] % x == 0) {
                    P[y][x]++;
                    S[y][x] += c[i];
                }
            }
        }
    }
}

void handle_queries(const vector<long long>& d, const vector<vector<int>>& P, const vector<vector<int>>& S, const vector<int>& a1_factors, const vector<int>& b1_factors) {
    for (long long coins : d) {
        long long max_gcd_sum = 0;
        for (int x : a1_factors) {
            for (int y : b1_factors) {
                if (P[x][y] == a1_factors.size()) {
                    if (S[x][y] <= coins) {
                        max_gcd_sum = max(max_gcd_sum, (long long)x + y);
                    }
                }
            }
        }
        cout << max_gcd_sum << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<long long> d(q);
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
    }

    vector<int> a1_factors = factorize(a[0]);
    vector<int> b1_factors = factorize(b[0]);

    precompute(a, b, c, a1_factors, b1_factors);

    handle_queries(d, P, S, a1_factors, b1_factors);

    return 0;
}

