#include <iostream>
using namespace std;

void solve() {
    char s[10];
    cin.getline(s, 10);

    int h = (s[0]-'0')*10 + (s[1]-'0');
    int m = (s[3]-'0')*10 + (s[4]-'0');

    bool PM = false;
    if(h > 12) {
        h -= 12;
        PM = true;
    } else if(h == 12) {
        PM = true;
    } else if(h == 0) {
        h += 12;
        PM = false;
    }
    
    if(h < 10) {
        cout<<'0';
    }
    cout<<h<<':'<<s[3]<<s[4]<<' ';
    if(PM) cout<<"PM"<<endl;
    else cout<<"AM"<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    int T; cin>>T;
    char s[10];
    cin.getline(s, 10);
    while(T--) {
        solve();
    }

    return 0;
}
