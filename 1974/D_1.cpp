#include <iostream>
using namespace std;
const int maxn = 2e5+5;
//int cnt[256] = {0};
int N = 0, S = 0, W = 0, E = 0;

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n;
        string s;
        cin>>n>>s;
        N=0; S=0; W=0; E=0;

        for(int i = 0; i < n; i++) {
            switch(s[i]) {
                case 'N': N++; break;
                case 'S': S++; break;
                case 'W': W++; break;
                case 'E': E++; break;
                default:
                    cout<<"error!"<<endl;
                    break;
            }
        }

        if(n==2 && s[0]!=s[1]) {
            cout<<"NO"<<endl;
            continue;
        }

        int num1, num2;
        num1 = N>S ? N-S : S-N;
        num2 = W>E ? W-E : E-W;
        //num1 = cnt[N]>cnt[S] ? cnt[N]-cnt[S] : cnt[S]-cnt[N];
        //num2 = cnt[W]>cnt[E] ? cnt[W]-cnt[E] : cnt[E]-cnt[W];

        if(num1%2==1 || num2%2==1) {
            cout<<"NO"<<endl;
            continue;
        }

        string ret;
        bool f1 = true, f2 = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N') {
                if(N>S) {    //平分
                    if(f1) ret+='R';
                    else ret+='H';
                    f1 = !f1;
                N--;
                } else {    //无脑给R
                    ret += 'R';
                }
            }
            
            if(s[i] == 'S') {
                if(S>N) {
                    if(f1) ret+='R';
                    else ret+='H';
                    f1 = !f1;
                S--;
                } else {
                    ret += 'R';
                }
            }

            if(s[i] == 'W') {
                if(W>E) {
                    if(f2) ret+='R';
                    else ret+='H';
                    f2 = !f2;
                W--;
                } else {
                    ret += 'R';
                }
            }

            if(s[i] == 'E') {
                if(E>W) {
                    if(f2) ret+='R';
                    else ret+='H';
                    f2 = !f2;
                E--;
                } else {
                    ret += 'R';
                }
            }
        }

        bool flag = true;
        for(int i = 0; i < ret.size(); i++) {
            if(ret[i] != 'R') {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(N == S  && N!=0) {
                int t1 = 0;
                while(s[t1] != 'N') t1++;
                int t2 = 0;
                while(s[t2] != 'S') t2++;

                ret[t1] = 'H';
                ret[t2] = 'H';
            } else {
                int t1 = 0;
                while(s[t1] != 'W') t1++;
                int t2 = 0;
                while(s[t2] != 'E') t2++;

                ret[t1] = 'H';
                ret[t2] = 'H';

            }
            
        }

        cout<<ret<<endl;
    }

    return 0;
}

