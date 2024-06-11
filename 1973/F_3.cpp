#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int n, q;
int a[maxn], b[maxn];
int c[maxn];
int d[maxn];
vector<int> fa1;
vector<int> fb1;
vector<int> ret1, ret2;

struct opt {
    int cost;
    int sum;
    opt(int c, int s) : cost(c), sum(s) {}

    bool operator<(const opt& oth) const {
        return cost < oth.cost;
    }
};

void factorize(int n, vector<int>& f, unordered_map<int, int>& cache) {
    if (cache.find(n) != cache.end()) {
        f.push_back(cache[n]);
        return;
    }
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            f.push_back(i);
            if(i != n / i)
                f.push_back(n / i);
        }
    }
    cache[n] = f.back();
}

vector<int> queries(const vector<opt>& opts);

void solve1(unordered_map<int, int>& factor_cache) {
    factorize(a[1], fa1, factor_cache);
    factorize(b[1], fb1, factor_cache);
    int fa1_size = fa1.size();
    int fb1_size = fb1.size();
    
    vector<vector<int>> p(fa1_size, vector<int>(fb1_size, 1));
    vector<vector<int>> s(fa1_size, vector<int>(fb1_size, 0));

    for(int i = 2; i <= n; i++) {
        for(int x = 0; x < fa1_size; x++) {
            for(int y = 0; y < fb1_size; y++) {
                if(a[i] % fa1[x] == 0 && b[i] % fb1[y] == 0) {
                    p[x][y]++;
                } else if(b[i] % fa1[x] == 0 && a[i] % fb1[y] == 0) {
                    p[x][y]++;
                    s[x][y] += c[i];
                }
            }
        }
    }

    vector<opt> opts;
    for(int x = 0; x < fa1_size; x++) {
        for(int y = 0; y < fb1_size; y++) {
            if(p[x][y] == n) {
                opts.push_back(opt(s[x][y], fa1[x] + fb1[y]));
            }
        }
    }

    sort(opts.begin(), opts.end());

    int max_sum = -1;
    for(auto it = opts.begin(); it != opts.end(); it++) {
        if(it->sum > max_sum)
            max_sum = it->sum;
        it->sum = max_sum;
    }

    ret1 = queries(opts);
}

void solve2(unordered_map<int, int>& factor_cache) {
    swap(a[1], b[1]);
    fa1.clear();
    fb1.clear();

    factorize(a[1], fa1, factor_cache);
    factorize(b[1], fb1, factor_cache);
    int fa1_size = fa1.size();
    int fb1_size = fb1.size();
    
    vector<vector<int>> p(fa1_size, vector<int>(fb1_size, 1));
    vector<vector<int>> s(fa1_size, vector<int>(fb1_size, c[1]));

    for(int i = 2; i <= n; i++) {
        for(int x = 0; x < fa1_size; x++) {
            for(int y = 0; y < fb1_size; y++) {
                if(a[i] % fa1[x] == 0 && b[i] % fb1[y] == 0) {
                    p[x][y]++;
                } else if(b[i] % fa1[x] == 0 && a[i] % fb1[y] == 0) {
                    p[x][y]++;
                    s[x][y] += c[i];
                }
            }
        }
    }

    vector<opt> opts;
    for(int x = 0; x < fa1_size; x++) {
        for(int y = 0; x < fb1_size; y++) {
            if(p[x][y] == n) {
                opts.push_back(opt(s[x][y], fa1[x] + fb1[y]));
            }
        }
    }

    sort(opts.begin(), opts.end());

    int max_sum = -1;
    for(auto it = opts.begin(); it != opts.end(); it++) {
        if(it->sum > max_sum)
            max_sum = it->sum;
        it->sum = max_sum;
    }

    ret2 = queries(opts);
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= q; i++)
        cin >> d[i];

    unordered_map<int, int> factor_cache;
    solve1(factor_cache);
    solve2(factor_cache);

    for(int i = 0; i < q; i++) 
        cout << max(ret1[i], ret2[i]) << ' ';
    cout << endl;
    
    return 0;
}

vector<int> queries(const vector<opt>& opts) {
    vector<int> ret;

    for(int i = 1; i <= q; i++) {
        auto it = upper_bound(opts.begin(), opts.end(), opt(d[i], 0));

        if(it == opts.begin())
            ret.push_back(0);
        else {
            it--;
            ret.push_back(it->sum);
        }
    }

    return ret;
}

