#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;

        int c[7] = {0};
        for(int i = 0; i < n; i++) {
            c[s[i]-'A']++;
        }

        int cnt = 0;
        for(int i = 0; i < 7; i++) {
            if(c[i] < m)
                cnt += m-c[i];
        }
        
        cout<<cnt<<endl;
    }

    return 0;
}

