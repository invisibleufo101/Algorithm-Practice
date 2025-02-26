#include <bits/stdc++.h>
using namespace std;
int n, arr[100004], psum[100006], ret=-10004;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    int refPoint = 0;
    int curMax;
    for (int i=1; i<=n; i++){
        int interval = psum[i] - psum[refPoint];
        int curVal = arr[i];

        if (curVal > interval){
            refPoint = i-1;
            curMax = curVal;
        } else if (interval >= curVal){
            curMax = interval;
        }

        ret = max(ret, curMax);
    }

    cout << ret << "\n";

    return 0;
}