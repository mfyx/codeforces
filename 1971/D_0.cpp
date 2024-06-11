#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin>>t;

    while(t--) {
        string s;
        cin>>s;
        //int n = s.length();
        int n = s.size();

        int i = 0;
        int cnt0 = 0, cnt1 = 0;
        char state = s[0];

        while(i < n) {
            while(s[i] == state) i++;
            
            if(state == '0') cnt0++;
            else cnt1++;

            if(state == '0') state = '1';
            else state = '0';
        }

        if(cnt0 + cnt1 < 1) cout<<"ERROR"<<endl;
        else if(cnt0 + cnt1 == 1) cout<<"1"<<endl;
        else if(cnt0 + cnt1 == 2) {
            if(s[0] == '0') cout<<"1"<<endl;
            else cout<<"2"<<endl;
        } else {
            cout<<cnt0+cnt1-1<<endl;
        }

    }

    return 0;
}
