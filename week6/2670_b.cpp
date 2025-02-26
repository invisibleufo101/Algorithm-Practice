#include <bits/stdc++.h>
using namespace std;
int n;
double arr[10004], ret=-1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << setprecision(3) << fixed;

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    double cmp = arr[0];
    for (int i=1; i<n; i++){
        if (cmp * arr[i] >= arr[i]) cmp *= arr[i];
        else if (cmp * arr[i] < arr[i]) cmp = arr[i];

        ret = max(ret, cmp);
    }

    cout << ret << "\n";

    return 0;
}