#include <iostream>
using namespace std;
const int maxn = 2e5+5;
int cnt[256] = {0};
char N = 'N', S = 'S', W = 'W', E = 'E';

int main() {
    ios::sync_with_stdio(false);
    int tt; cin>>tt;

    while(tt--) {
        int n;
        string s;
        cin>>n>>s;

        for(int i = 0; i < n; i++)
            cnt[i]++;
        int num1, num2;
        num1 = cnt[N]>cnt[S] ? cnt[N]-cnt[S] : cnt[S]-cnt[N];
        num2 = cnt[W]>cnt[E] ? cnt[W]-cnt[E] : cnt[E]-cnt[W];

        if(num1%2==1 || num2%2==1) {
            cout<<"NO"<<endl;
            continue;
        }

        string ret;
        bool f1 = true, f2 = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N' || s[i] == 'S') {
                if(s[i] == 'N') {
                    if(cnt[i] && cnt['S']) {
                        if(f1) {
                            cnt[i]--;
                        } else {

                        }
                        f1 = !f1;
                    }
                } else {

                }
            } else {

            }
        }



    }

    return 0;
}

