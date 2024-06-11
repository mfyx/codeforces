#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--) {
        int p1, p2, p3;
        cin>>p1>>p2>>p3;
        int sum = p1 + p2 + p3;
        
        if(sum % 2 == 1) {
            cout<<-1<<endl;
            continue;
        }

        int cnt = 0;
        priority_queue<int> p;
        //priority_queue<int, std::vector<int>, std::greater<int>> p;
        p.push(p1);
        p.push(p2);
        p.push(p3);

        while(p.top() != 0) {
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();

            if(a==0 || b==0)
                break;

            a--; b--;
            p.push(a);
            p.push(b);

            cnt++;
        }

        cout<<cnt<<endl;
    }

    return 0;
}

