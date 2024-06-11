#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin>>t;

    while(t--) {
        string s;
        cin>>s;
        int n = s.length();

        if(n == 1) {
            cout<<"NO"<<endl;
            continue;
        }

        int i;
        char a = s[0];
        bool flag = false;
        for(i = 1; i < n; i++) {
            if(s[i] != a) {
                flag = true;
                break;
            }
        }

        if(flag) {
            cout<<"YES"<<endl;
            swap(s[0], s[i]);
            cout<<s<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

