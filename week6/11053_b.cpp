#include <bits/stdc++.h>
using namespace std;
int n,t,lis[1004],len;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        auto lowPos = lower_bound(lis, lis+len, t);
        if (*lowPos == 0) len++;
        *lowPos = t;
    }

    cout << len << "\n";
    
    return 0;
}