#include <iostream>
using namespace std;
const int inf = 10;

int main()
{
  int T; cin>>T;
  while(T--) {
    int n, k;
    cin>>n>>k;

    int a[inf], num = 1;
    for(int i = 0; i < n; ++i) {
      cin>>a[i];
      num *= a[i];
    }
    if(2023%num == 0) {
      cout<<"YES"<<endl;
      int t = 2023/num;
      cout<<t<<" ";
      for(int i = 1; i < k; ++i) {
        cout<<1<<" ";
      }
      cout<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
