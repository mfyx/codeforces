#include <iostream>
using namespace std;

int main()
{
  int T; cin>>T;
  while(T--) {
    int n; cin>>n;
    if(n % 3 == 0) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
  }
  return 0;
}
