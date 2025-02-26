#include <bits/stdc++.h>
using namespace std;
int n,m,h;
int a,b; 
int arr[12][272];
int ret = 4;

bool check(){
    for (int i=1; i<=n; i++){
        int here = i;
        for (int j=1; j<=h; j++){
            if (arr[j][here] == 1){
                here++;
            } else if (arr[j][here-1] == 1){
                here--;
            }
        }
        if (here != i) return false;
    }
    return true;
}

void dfs(int here, int cnt){
    if (cnt > 3 || cnt >= ret){
        return;
    } else if (check()){
        ret = min(ret, cnt);
        return;
    }


    for (int i=here; i<=h; i++){
        for (int j=1; j<=n-1; j++){
            if (arr[i][j] == 1 || arr[i][j+1] == 1 || arr[i][j-1] == 1) continue;
            arr[i][j] = 1;

            dfs(i, cnt+1);

            arr[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }

    dfs(1, 0);
    if (ret > 3) cout << -1 << "\n";
    else cout << ret << "\n";

    return 0;
}