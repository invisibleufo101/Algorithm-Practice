#include <bits/stdc++.h>
using namespace std;
int t,ia,ib,ic;
int visited[3001][3001][3001];
int combos[3][3] = {
    {0,0,0},
    {-1,0,0},
    {-1,-1,0},
};

void solve(int a, int b, int c){
    visited[a][b][c] = 1;
    queue<tuple<int,int,int>>q;
    q.push({a,b,c});
    
    while(q.size()){
        int ta, tb, tc;
        tie(ta,tb,tc) = q.front();
        q.pop();

        if (ta < tb < tc){
            int sum = (a - ta) + (b - tb) + (c - tc);
            cout << sum << "\n";
            break;
        }

        for (int i=0; i<3; i++){
            int na = max(1, ta + combos[i][0]);
            int nb = max(2, tb + combos[i][1]);
            int nc = max(3, tc + combos[i][2]);

            if (visited[na][nb][nc]) continue;

            visited[na][nb][nc] = visited[ta][tb][tc] + 1;
            q.push({na, nb, nc});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> ia >> ib >> ic;

        memset(visited, 0, sizeof(visited));
        solve(ia,ib,ic);
    }

    return 0;
}