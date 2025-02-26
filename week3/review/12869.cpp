#include <bits/stdc++.h>
using namespace std;
int n;
int damage [6][3] = {
    {-9, -3, -1},
    {-9, -1, -3},
    {-3, -9, -1},
    {-3, -1, -9},
    {-1, -9, -3},
    {-1, -3, -9},
};
int tmp[3];
int mn = 987654321;
int arr[61][61][61];
int visited[61][61][61];

void solve(int a, int b, int c){
    visited[a][b][c] = 1;
    queue<tuple<int,int,int>>q;
    q.push({a,b,c});
    while (q.size()){
        tie(a,b,c) = q.front();
        q.pop();

        if (visited[0][0][0]){
            cout << visited[0][0][0] - 1 << "\n";
            return;
        }

        for (int i=0; i<6; i++){
            // int na = max(0, a + damage[i][0]);
            // int nb = max(0, b + damage[i][1]);
            // int nc = max(0, c + damage[i][2]);

            int na = a + damage[i][0];
            int nb = b + damage[i][1];
            int nc = c + damage[i][2];

            if (na <= 0) na = 0;
            if (nb <= 0) nb = 0;
            if (nc <= 0) nc =0;

            if (visited[na][nb][nc]) continue;

            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp[i];
    }

    solve(tmp[0], tmp[1], tmp[2]);

    return 0;
}