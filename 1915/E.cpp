#include <iostream>
#include <map>
using namespace std;
const int inf = 2e5+5;

map<int, bool> e;

int main()
{
  int T; cin>>T;
  while(T--) {
    e.clear();
    int n; cin>>n;
    int sum[inf] = {0};
    bool yes = false;
    bool ji = true; //奇数取反
    cin>>sum[0];

    for(int i = 1; i < n; ++i) {
      cin>>sum[i];
      if(ji) sum[i] = -sum[i];
      sum[i] += sum[i-1];
      if(e[sum[i]]) {
        //cout<<"YES"<<endl;
        yes = true;
      }
      if(sum[i] == 0) {
        yes = true;
      }
      e[sum[i]] = true;
      ji = !ji;
    }
    if(yes) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
