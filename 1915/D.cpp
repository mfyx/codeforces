#include <iostream>
#include <string>
using namespace std;
const int inf = 200005;

bool is_v(char &s) {
  return s=='a' || s=='e';
}

int main()
{
  int T; cin>>T;
  while(T--) {
    bool dot[inf] = {false};
    int n; cin>>n;
    string s; cin>>s;
    for(int i = 0; i < s.size(); ++i) {
      cout<<s[i];
      if(is_v(s[i])) {
        if(i+2<s.size() && is_v(s[i+2])) {
          dot[i] = true;
        } else if(i+3<s.size() && is_v(s[i+3])) {
          dot[i+1] = true;
        } 
      }
      if(dot[i]) {
        cout<<".";
      }
    }
    cout<<endl;
  }
}
