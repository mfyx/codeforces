#include <iostream>
using namespace std;
const int inf = 1e5 + 5;

void solve() {
  int n; cin>>n;
  int a[inf] = {0}, ans[inf] = {0};
  for(int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  int ji = a[0]%2;
  int ou = 1-ji;
  int sum = a[0];
  cout<<a[0]<<" ";
  for(int i = 1; i < n; ++i) {
    sum += a[i];

    //if(int(a[i]/2)*2 == a[i]) ++ou;
    if(a[i]%2 == 0) ++ou;
    else ++ji;

    int t = ji % 3;
    if(t == 0 || t == 2) {
      cout<<sum-(ji/3)<<" ";
    } else {
      cout<<sum-(ji/3)-1<<" ";
    }
      //cout<<endl<<"t: "<<t<<endl;
  }
  cout<<endl;
}

int main() {
  int T; cin>>T;
  while(T--) {
    solve();
  }
  return 0;
}
