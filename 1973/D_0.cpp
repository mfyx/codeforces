#include <iostream>
#include <cstdio>
using namespace std;
int n, k;

bool check(int m) {
    int r = 0;

    //int t = n/k;
    int cnt = 0;

    do {
        printf("? %d %d\n", r+1, m);
        fflush(stdout);
        scanf("%d", &r);
        cnt++;

        if(r == n+1) 
            return false;
        if(cnt<k && r==n)
            return false;
        if(cnt>=k && r<n)
            return false;

    } while(r<n);
    
    return true;
}

void solve() {
    //cin>>n>>k;
    scanf("%d %d", &n, &k);

    int mx; //找到隐藏数组的最大值mx
    int r;
    int i = 1;
    do {
        printf("? 1 %d\n", n*i);
        fflush(stdout);
        i++;
        scanf("%d", &r);
    } while(r != n);
    
    mx = i-1;   //m的值为 1*mx 2*mx ... (n/k)*mx
    
    for(int i = 1; i <= n/k; i++) {
        int m = i * mx;
        if(check(m)) {
            printf("! %d\n", m);
            fflush(stdout);
            
            int rsp;
            scanf("%d", &rsp);
            if(rsp == -1)
                printf("回答错误!");

            return;
        }
    }

    printf("! -1\n");
    fflush(stdout);
    
    int rsp;
    scanf("%d", &rsp);
    if(rsp == -1)
        printf("回答错误!");
}

signed main() {
    int T;
    //cin>>T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}

