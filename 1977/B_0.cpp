#include <iostream>
#include <string>
using namespace std;
string s;
int num;

void solve(int n) {
    if(n == 0) {
        //cout<<"0 ";
        s += "0 ";
        num++;
        return;
    }
    if(n == 1) {
        //cout<<"1 ";
        s += "1 ";
        num++;
        return;
    }

    if(n%2 == 0) {
        //cout<<"0 ";
        s += "0 ";
        num++;
        solve(n/2);
    } else {
        if((n+1)%4 == 0) {
            //cout<<"-1 ";
            s += "-1 ";
            num++;
            solve((n+1)/2);
        } else {
            //cout<<"1 ";
            s += "1 ";
            num++;
            solve((n-1)/2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        s = "";
        num = 0;
        solve(n);
        
        cout<<num<<endl<<s<<endl;
    }

    return 0;
}

