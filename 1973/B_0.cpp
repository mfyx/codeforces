#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e5 + 5;
int a[inf];

int main() {
    ios::sync_with_stdio(false);
    int T; cin>>T;

    while(T--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++) 
            cin>>a[i];

        bool b[inf][25] = {0} ;

        for(int i = 0; i < n; i++) {
            int bits = 0;
            while(a[i] != 0) {
                b[i+1][bits++] = a[i]&1;
                a[i] = a[i]>>1;
            }
        }
        for(int i = 0; i <= 21; i++) {
            b[0][i] = 1;
            b[n+1][i] = 1;
        }

        int ret = 1;
        int maxdis;
        for(int i = 21; i >= 0; i--) {
            int cnt1 = 0;
            int pre1=-1;
            maxdis = -1;
            for(int j = 0; j <= n+1; j++) {
                if(b[j][i]) {
                    cnt1++;
                    if(pre1 == -1) {
                        pre1 = j;
                    } else {
                        maxdis = max(maxdis, j-pre1);
                        pre1 = j;
                    }
                }
            }

            if(cnt1 == 2)
                continue;
            /*if(cnt1 == 3) {
                pre1 = max(pre1+1, n-pre1);
                ret = max(ret, pre1);
                //cout<<"i: "<<i<<"  pre1: "<<pre1<<endl;
                continue;
            }*/
                
            ret = max(ret, maxdis);

            //cout<<"i: "<<i<<"\t\t"<<"maxdis: "<<maxdis<<endl;
        }
        cout<<ret<<endl;

        /*for(int i = 0; i < n; i++) {
            for(int j = 4; j >= 0; j--)
                cout<<b[i][j]<<' ';
            cout<<endl;
        }*/
    }

    return 0;
}

