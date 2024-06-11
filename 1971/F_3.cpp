#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5+5;

int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    
    while(t--) {
        int r; cin>>r;
        int cnt = 0;

        int x, y;
        y = r-1;
        for(x = 0; x <= r-1; x++) {
            int d = sqrt(x*x+y*y);
            if( d>=r && d<(r+1) ) {
                if(x == 0) cnt+=2;
                else cnt+=4;
            }
        }
        x = r-1;
        for(y = 0; y < r-1; y++) {
            int d = sqrt(x*x+y*y);
            if( d>=r && d<(r+1) ) {
                if(y == 0) cnt+=2;
                else cnt+=4;
            }
        }

        y = r;
        for(x = 0; x <= r; x++) {
            int d = sqrt(x*x+y*y);
            if( d>=r && d<(r+1) ) {
                if(x == 0) cnt+=2;
                else cnt+=4;
            }
        }
        x = r;
        for(y = 0; y < r; y++) {
            int d = sqrt(x*x+y*y);
            if( d>=r && d<(r+1) ) {
                if(y == 0) cnt+=2;
                else cnt+=4;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}
