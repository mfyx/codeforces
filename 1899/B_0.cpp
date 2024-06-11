#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 150005;
//const int inf = 1505;
bool is_prime[inf] = {false};
vector< vector<int> > factors(inf);
int primes[inf] = {0};
int idx = 0;

void sieve_prime() {
  for(int i = 2; i < inf; ++i) {
    factors[i].push_back(1);
  }
  for(int i = 2; i < inf; ++i) {
    is_prime[i] = true;
  }
  for(int i = 2; i < inf; ++i) {
    if(is_prime[i]) {
      //primes[idx++] = i;
      //for(int j = 0; (j < idx) && (i * primes[j] < inf); ++j) {
      for(int j = i + i; j < inf; j += i) {
        //is_prime[i * primes[j]] = false;
        //factors[i * primes[j]].push_back(i);
        factors[j].push_back(i);
      }
    }
  }
  for(int i = 2; i < inf; ++i) {
    factors[i].push_back(i);
  }
}

void print() {
  for(int i = 0; i < inf; ++i) {
    cout<<i<<": ";
    for(int j = 0; j < factors[i].size(); ++j) {
      cout<<factors[i][j]<<' ';
    }
    cout<<endl;
  }
}

int main()
{
  sieve_prime();

  int T; cin>>T;
  while(T--) {
    int n; cin>>n;
    int *a = new int[n];
    int *sum = new int[n];
    for(int i = 0; i < n; ++i) {
      sum[i] = 0;
      cin>>a[i];
      sum[i] += a[i];
      if(i >= 1) sum[i] += sum[i-1];
    }
    int ans = 0;
    for(int i = 0; i < factors[n].size(); ++i) {
      int fac = factors[n][i];
      int maxn = sum[fac], minn = sum[fac];
      for(int j = fac + fac; j <= n; j += fac) {
        int num = sum[j] - sum[j - fac];
        maxn = max(maxn, num);
        minn = min(minn, num);
      }
      ans = max(ans, maxn - minn);
    }
    cout<<ans<<endl;
  }

  return 0;
}
