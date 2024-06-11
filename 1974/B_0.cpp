#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        string s;
        cin>>s;

        int cnt[256] = {0};

        string r = "";
        for(int i = 0; i < n; i++) {
            cnt[s[i]]++;
            //if(cnt[s[i]] == 1) {
            //    r += s[i];
                //r.append(s[i]);
            //}
        }

        for(int i = 0; i < 256; i++) {
            if(cnt[i])
                r += i;
        }

        //cout<<r<<endl;
        map<char, char> cmap;
        int m = r.size();
        for(int i = 0; i < m; i++) {
            cmap[r[i]] = r[m-i-1];
        }

        string ret;
        for(int i = 0; i < n; i++) {
            ret += cmap[s[i]];
        }

        cout<<ret<<endl;

    }

    return 0;
}


