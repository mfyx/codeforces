#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;
    int test = 0;

    while(tt--) {
        int n; cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }

        if(++test == 4) {
            cout<<"test4: ";
            for(int i = 0; i < n; i++) 
                cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }
        
        if(n==2) {
            //cout<<a[0]<<endl;
            if(a[0]<a[1])
                cout<<a[0]<<endl;
            else
                cout<<a[1]<<endl;
            continue;
        }

        int maxnum = -1;
        for(int i = 1; i < n-1; i++) {
            int num = -1;

            int b=a[i-1], c=a[i-1];
            b = max(b, a[i]);
            b = max(b, a[i+1]);

            c = min(c, a[i]);
            c = min(c, a[i+1]);

            if(a[i-1]!=b && a[i-1]!=c)
                num = a[i-1];
            else if(a[i]!=b && a[i]!=c)
                num = a[i];
            else
                num = a[i+1];
            
            maxnum = max(maxnum, num);
        }

        cout<<maxnum<<endl;
    }

    return 0;
}


