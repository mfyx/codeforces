#include <iostream>
#include <vector>
#include <algorithm>
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

void factorize(int n, vector<int>& f) {
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            f.push_back(i);
            if(i != n/i)
                f.push_back(n/i);
        }
    }
}

vector<int> queries(const vector<vector<int>>& p, const vector<vector<int>>& s, const vector<opt>& opts);

void solve1() {
    factorize(a[1], fa1);
    factorize(b[1], fb1);
    vector<vector<int>> p(fa1.size(), vector<int>(fb1.size(), 1));
    vector<vector<int>> s(fa1.size(), vector<int>(fb1.size(), 0));

    for(int i = 2; i <= n; i++) {
        for(int x = 0; x < fa1.size(); x++) {
            for(int y = 0; y < fb1.size(); y++) {
                if(a[i]%fa1[x] == 0 && b[i]%fb1[y] == 0) {
                    p[x][y]++;
                } else if(b[i]%fa1[x] == 0 && a[i]%fb1[y] == 0) {
                    p[x][y]++;
                    s[x][y] += c[i];
                }
            }
        }
    }

    vector<opt> opts;
    for(int x = 0; x < fa1.size(); x++) {
        for(int y = 0; y < fb1.size(); y++) {
            if(p[x][y] == n) {
                opts.push_back(opt(s[x][y], fa1[x]+fb1[y]));
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

    ret1 = queries(p, s, opts);
}

void solve2() {
    swap(a[1], b[1]);
    fa1.clear();
    fb1.clear();

    factorize(a[1], fa1);
    factorize(b[1], fb1);
    vector<vector<int>> p(fa1.size(), vector<int>(fb1.size(), 1));
    vector<vector<int>> s(fa1.size(), vector<int>(fb1.size(), c[1]));

    for(int i = 2; i <= n; i++) {
        for(int x = 0; x < fa1.size(); x++) {
            for(int y = 0; y < fb1.size(); y++) {
                if(a[i]%fa1[x] == 0 && b[i]%fb1[y] == 0) {
                    p[x][y]++;
                } else if(b[i]%fa1[x] == 0 && a[i]%fb1[y] == 0) {
                    p[x][y]++;
                    s[x][y] += c[i];
                }
            }
        }
    }

    vector<opt> opts;
    for(int x = 0; x < fa1.size(); x++) {
        for(int y = 0; y < fb1.size(); y++) {
            if(p[x][y] == n) {
                opts.push_back(opt(s[x][y], fa1[x]+fb1[y]));
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

    ret2 = queries(p, s, opts);
}

signed main() {
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    for(int i = 1; i <= n; i++)
        cin>>c[i];
    for(int i = 1; i <= q; i++)
        cin>>d[i];

    solve1();
    solve2();

    for(int i = 0; i < q; i++) 
        cout<<max(ret1[i], ret2[i])<<' ';
    cout<<endl;
    
    return 0;
}

vector<int> queries(const vector<vector<int>>& p, const vector<vector<int>>& s, const vector<opt>& opts) {
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
