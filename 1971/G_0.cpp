#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 505;
int m[3][maxn];
int a[3][maxn];

int main() {
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < n; j++) 
                cin>>m[i][j];
        }

        bool flag = false;
        for(int n = 0; n < 16; n++) {
            int k[4];
            int num = n;
            int ki = 0;
            while(num) {
                if(num&1) k[ki++] = 1;
                else k[ki++] = -1;
                num = num>>1;
            }

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int id = abs(m[i][j]);
                    //a[i][j] = 
                }
            }
        }


        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
