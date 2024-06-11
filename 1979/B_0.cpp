#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int x, y;
        cin>>x>>y;

        int cnt = 0;
        while(x%2 == y%2) {
            cnt++;
            x /= 2;
            y /= 2;
        }

        cout<<int(double(pow(2,cnt)))<<endl;
        //int ret = x^y;
        //cout<<ret<<endl;
    }

    return 0;
}

