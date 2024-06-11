#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n;
        string s;
        cin>>n>>s;
        
        bool ok = true;
        int i = 0;
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
            i++;

        while(s[i]-'0'>=0 && s[i]-'0'<=9 && i<s.size()) {
            if(s[i] >= s[i-1]) {
                i++;
            } else {
                ok = false;
                break;
            }
        }

        if(!ok) {
            cout<<"NO"<<endl;
            continue;
        }

        //cout<<s[i]<<endl;
        if(s[i]-'a'>=0 && s[i]-'a'<=25)
            i++;

        while(s[i]-'a'>=0 && s[i]-'a'<=25 && i<s.size()) {
            if(s[i] >= s[i-1]) {
                i++;
            } else {
                ok = false;
                break;
            }
        }

        if(!ok) {
            cout<<"NO"<<endl;
        } else {
            if(i == s.size())
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}

