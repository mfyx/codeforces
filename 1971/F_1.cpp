#include <iostream>
#include<fstream>
#include <cmath>
using namespace std;
#define int long long
const int maxn = 1e5+5;
//const int maxn = 2e3+5;
int cnt[2*maxn] = {0};

signed main() {
    ios::sync_with_stdio(false);
    ofstream out_file("output.txt");
    out_file.is_open();
    cout.rdbuf(out_file.rdbuf());

    int **d;
    d = new int*[maxn];
    for(int i = 0; i < maxn; i++) {
        d[i] = new int[maxn];
    }

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++)
            d[i][j] = sqrt(i*i + j*j);
    }

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            if(i==0 || j==0)
                cnt[d[i][j]]+=2;
            else
                cnt[d[i][j]]+=4;
        }
    }

    for(int i = 0; i < 2*maxn; i++) {
        if(cnt[i] != 0) {
            cout<<"ans["<<i<<"] = "<<cnt[i]<<endl;

            //cout<<i<<": "<<cnt[i]<<endl;
        }
    }

    out_file.close();
    //cout.rdbuf(cout.rdbuf());
    //cout<<"程序运行结束!"<<endl;
    

    /*for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }*/

    return 0;
}

