#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int x, y;
        cin>>x>>y;

        int cnt = 0;
        
        if(x==0 && y==0) {
            cout<<0<<endl;
            continue;
        }

        int x2, y2;
        if(y%2 == 0) {
            y2 = y/2;
            if(x <= y2*7)
                cout<<y2<<endl;
            else {
                x -= y2*7;
                if(x%15 == 0)
                    x2 = x/15;
                else
                    x2 = (x/15)+1;
                cout<<x2+y2<<endl;
            }
        } else {
            y2 = y/2;
            if(x <= y2*7+11)
                cout<<y2+1<<endl;
            else {
                x -= (y2*7+11);
                if(x%15 == 0)
                    x2 = x/15;
                else
                    x2 = (x/15)+1;
                cout<<x2+y2+1<<endl;
            }
        }

    }

    return 0;
}

