#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  if(a < b) swap(a, b);
  while(b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main()
{
  int T; cin>>T;
  while(T--) {
    int a, b;
    cin>>a>>b;
    //cout<<gcd(a, b)<<endl;

    if(a < b) swap(a, b);
    if(a % b == 0) {
      if(b == 1) cout<<a*a<<endl;
      else {
        cout<<a*a/b<<endl;
      }
    } else {
      cout<<a * b / gcd(a, b)<<endl;
    }
  }
  return 0;
}
