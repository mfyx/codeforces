#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin>>t;

    while(t--) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        if(a>c && b<d) {
            cout<<"NO"<<endl;
            continue;
        } else if(a<c && d<b) {
            cout<<"NO"<<endl;
            continue;
        } else if(b < c) {
            cout<<"NO"<<endl;
            continue;
        } else if(d < a) {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }

    return 0;
}

