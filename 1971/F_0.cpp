#include <iostream>
#include <cmath>
using namespace std;
#define int double
//const unsigned maxn = 1e5 + 5;
const unsigned maxn = 1e5 + 5;
int d[maxn][maxn];


signed main() {
    for(unsigned  i = 0; i < maxn; i++) {
        for(unsigned j = 0; j < maxn; j++) {
            d[i][j] = sqrt(i*i + j*j);
        }
    }

    for(unsigned  i = 0; i < maxn; i++) {
        for(unsigned j = 0; j < maxn; j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
