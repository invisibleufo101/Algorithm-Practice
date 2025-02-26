#include <bits/stdc++.h>
using namespace std;
long long n, tempHeight, ret;
struct A {
    long long height, cnt;
};
stack<A>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tempHeight;

        int cnt = 1;

        while (stck.size() && stck.top().height <= tempHeight){

            ret += stck.top().cnt;
            
            if (stck.top().height == tempHeight){
                cnt = stck.top().cnt + 1;
            } else {
                cnt = 1;
            }

            stck.pop();
        }

        if (stck.size()) ret++;
        stck.push({tempHeight, cnt});
    }

    cout << ret << "\n";

    return 0;
}