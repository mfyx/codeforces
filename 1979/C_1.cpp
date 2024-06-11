#include <iostream> 
using namespace std;
const int maxn = 55;
int a[maxn];
int b[maxn];
int x[maxn];

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n; cin>>n;
        cin>>a[0];
        b[0] = a[0];
        for(int i = 1; i < n; i++) {
            cin>>a[i];
            b[i] = lcm(a[i], b[i-1]);
        }

        //cout<<a[n-1]<<endl;
        int num = b[n-1];
        //cout<<"num: "<<num<<endl;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            x[i] = num/a[i];
            sum += x[i];
        }

        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(x[i]*a[i] <= sum) {
                flag = false;
                break;
            }
        }

        if(flag) {
            for(int i = 0; i < n; i++)
                cout<<x[i]<<' ';
            cout<<endl;
        } else
            cout<<-1<<endl;
    }

    return 0;
}

