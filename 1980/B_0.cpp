#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];

bool compare(int x, int y) {
    return x > y;
}

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n, f, k;
        cin>>n>>f>>k;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        int fav = a[f];
        sort(a+1, a+n+1, compare);

        if(a[k] < fav)
            cout<<"YES"<<endl;
        else if(a[k] == fav) {
            if(k==n)
                cout<<"YES"<<endl;
            else if(k<n && a[k+1]!=fav)
                cout<<"YES"<<endl;
            else if(k<n && a[k+1]==fav)
                cout<<"MAYBE"<<endl;
        } else if(a[k] > fav)
            cout<<"NO"<<endl;

        //for(int i = 1; i <= n; i++)
        //    cout<<a[i]<<' ';
        //cout<<endl;
    }

    return 0;
}

