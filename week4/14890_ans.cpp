#include <bits/stdc++.h>
using namespace std;
int n,l;
int a[101][101];
int ta[101][101];

int solve(int arr[101][101]){
    int numOfPaths = 0;
    for (int i=0; i<n; i++){
        int cnt = 1;
        int j;
        for (j=0; j<n-1; j++){
            if (arr[i][j] == arr[i][j+1]){
                cnt++;
            } else if (arr[i][j] + 1 == arr[i][j+1] && cnt >= l){
                cnt = 1;
            } else if (arr[i][j] - 1 == arr[i][j+1] && cnt >= 0){
                cnt = -l+1;
            } else {
                break;
            }
        }

        if (j == n-1 && cnt >= 0) numOfPaths++; 
    }
    return numOfPaths;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
            ta[j][i] = a[i][j];
        }
    }

    int ret = solve(a) + solve(ta);
    cout << ret << "\n";

    return 0;
}