#include <iostream>
#include <queue>
using namespace std;
const int maxn = 4e5+5;
int p[maxn], q[maxn];
int a[maxn];
int id[maxn];
int q2[maxn];
//int odd[maxn], even[maxn];

int main() {
    ios::sync_with_stdio(false);
    int T; cin>>T;

    while(T--) {
        priority_queue<int> odd, even;
        priority_queue<int> odd2, even2;    //优先队列应该定义为局部变量
                                            //防止之前的数据影响输出
        int n; cin>>n;
        //int i1 = -1, i2 = -1;
        for(int i = 0; i < n; i++) {
            cin>>p[i];
            id[p[i]] = i;
            if(i%2 == 0) {    //此时是奇数
                odd.push(p[i]);
                odd2.push(p[i]);
                //odd[++i1] = p[i];
            } else {
                even.push(p[i]);
                even2.push(p[i]);
                //even[++i2] = p[i];
            }
        }

        int num = n/2 + 1;
        while(!odd.empty()) {
            int idx = id[odd.top()];
            odd.pop();
            q[idx] = num++;
        }

        num = 1;
        while(!even.empty()) {
            int idx = id[even.top()];
            even.pop();
            q[idx] = num++;
        }

        for(int i = 0; i < n; i++)
            a[i] = p[i] + q[i];
        bool flag = true;
        for(int i = 1; i < n-1; i++) {
            if(a[i] == a[i+1]) {
                flag = false;       // 一旦出现相等就换一种方式求q
                break;
            }
        }

        if(flag) {
            cout<<endl;
            for(int i = 0; i < n; i++)
                cout<<q[i]<<" ";
            continue;
        }

        num = 1;
        while(!odd2.empty()) {
            int idx = id[odd2.top()];
            odd2.pop();
            q2[idx] = num++;
        }

        num = n/2+1;
        while(!even2.empty()) {
            int idx = id[even2.top()];
            even2.pop();
            q2[idx] = num++;
        }

        cout<<endl;
        for(int i = 0; i < n; i++) 
            cout<<q2[i]<<" ";
    }

    return 0;
}

