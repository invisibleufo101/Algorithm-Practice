#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int arr[5][5];
int visited[5][5];
int ret = 0;

int countUp(int a[5][5]){

    int totalSum = 0;

    // Case for counting horizontal numbers
    for (int i=0; i<n; i++){
        int rowNum = 0;
        for (int j=0; j<m; j++){
            if (visited[i][j]){
                // Shifts the number up by 10 everytime
                // ex) [7,4,9,1] 
                // cur = 0;
                // cur = 0*10 + 7 = 7;
                // cur = 7 * 10 + 4 = 74;
                // cur = 74 * 10 + 9 = 749;
                // cur = 749 * 10 + 1 = 7491;
                rowNum = rowNum * 10 + arr[i][j]; 
            } else {
                totalSum += rowNum;
                rowNum = 0;
            }
        }
        totalSum += rowNum;
    }

    // Case for counting vertical numbers
    for (int j=0; j<m; j++){
        int colNum = 0;    
        for (int i=0; i<n; i++){
            if (visited[i][j] == 0){
                colNum = colNum * 10 + arr[i][j];
            } else {
                totalSum += colNum;
                colNum = 0;
            }
        }
        totalSum += colNum;
    }

    return totalSum;
}

void solve(int y, int x){
    if (y == n){
        ret = max(ret, countUp(visited));
        return;
    }

    // End of column in the current row
    if (x == m){
        solve(y+1, 0);
        return;
    }

    visited[y][x] = 1;

    solve(y, x+1);

    visited[y][x] = 0;

    solve(y, x+1);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    solve(0,0);
    cout << ret << "\n";

    return 0;
}