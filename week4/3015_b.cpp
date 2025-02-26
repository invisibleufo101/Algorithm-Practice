#include <bits/stdc++.h>
using namespace std;
long long n,curHeight;
struct A{
    long long height, cnt;
};
stack<A>stck;
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> curHeight;

        int cnt = 1;
        while (stck.size() && stck.top().height <= curHeight){
            ret += stck.top().cnt;

            if (stck.top().height == curHeight){
                cnt += stck.top().cnt;
            } else {
                cnt = 1;
            }
        }

        // Any elements that are higher than the current one 
        if (stck.size()) ret++;

        stck.push({curHeight, cnt});
    }

    cout << ret << "\n";

    return 0;
}
