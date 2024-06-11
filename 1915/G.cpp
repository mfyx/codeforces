#include <iostream>
using namespace std;
const int inf = 2e5+5;

int main()
{
  int T; cin>>T;
  while(T--) {
    bool yes = false;
    int n; cin>>n;
    int a[inf]={0} , b[inf]={0};
    int ji[inf], ou[inf];
    int id1=0,id2=0;
    bool flag = 0;
    for(int i = 0; i < n; ++i) {
      cin>>a[i];
      if(flag) ji[id1++] = a[i];
      else ou[id2++] = a[i];
      flag = !flag;
    }
    //int id = id1>id2 ? id1:id2;
    for(int i = 0; i < id2; ++i) {
      b[i] = ou[i]-ji[i];
    }
    int c[inf];
    c[0] = b[0];
    for(int i = 1; i < id2; ++i) {
      c[i] = b[i] + c[i-1];
      if(c[i] == 0 || c[i]) {
        yes = true;
      }
    }

    
  }
  return 0;
}
