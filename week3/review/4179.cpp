#include <bits/stdc++.h>
using namespace std;
int r,c;
char arr[1001][1001];
int f_visit[1001][1001];
int j_visit[1001][1001];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int fy, fx; // Fire's coordinates
int jy, jx; // JH's coordinates
const int INF = 987654321;

queue<pair<int,int>>fires;
pair<int,int>jh;

/**
 * Note:
 * - READ THE QUESTION PROPERLY!
 * 
 * - I think this is a good brain teaser for thinking about how the question should
 * be executed. Because you think JH and fire should be moving together simutaneously
 * but you can just make fire go first and see where JH can go to avoid the fire
 * 
 * if (JH's next step is LESS THAN fire's next step) 
 *      THEN he can cross
 * else
 *      he can't cross
 * 
 * Also, filling f_visit array with INF is a good idea as well because this above logic
 * doesn't work in case JH doesn't have ANY fire near him. 
 * 
 * If we were to think of the case where f_visit is filled with 0s for the areas that the 
 * fires haven't touched. then the above logic makes JH not be able to cross where there's no fire
 * because 0 is less than JH's steps. That's why the f_visit is filled with INF.
*/

void print(int a[1001][1001]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (a[i][j] == INF) cout << "INF ";
            else cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

// Simulate fire spreading
void spread(){
    while (fires.size()){
        tie(fy,fx) = fires.front();
        fires.pop();
        for (int i=0; i<4; i++){
            int nfy = fy + dy[i];
            int nfx = fx + dx[i];

            if (nfy < 0 || nfx < 0 || nfy >= r || nfx >= c) continue;
            if (f_visit[nfy][nfx] != INF) continue;
            if (arr[nfy][nfx] == '#') continue;

            f_visit[nfy][nfx] = f_visit[fy][fx] + 1;
            fires.push({nfy, nfx});
        }
    }
}

// Simulate JH escaping
int escape(int y, int x){
    j_visit[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({y,x});
    while (q.size()){
        tie(jy, jx) = q.front();
        q.pop();

        if (jy == 0 || jx == 0 || jy == r-1 || jx == c-1){
            return j_visit[jy][jx];
        }

        for (int i=0; i<4; i++){
            int njy = jy + dy[i];
            int njx = jx + dx[i];

            if (njy < 0 || njx < 0 || njy >= r || njx >= c) continue;
            if (j_visit[njy][njx]) continue;
            if (arr[njy][njx] == '#') continue;
            if (j_visit[jy][jx] + 1 >= f_visit[njy][njx]) continue;

            j_visit[njy][njx] = j_visit[jy][jx] + 1;
            q.push({njy, njx});
            
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    // Initialize Fire's visited array with INF 
    fill(&f_visit[0][0], &f_visit[0][0] + 1001 * 1001, INF);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'F'){
                fires.push({i,j});
                f_visit[i][j] = 1;
            }
            else if (arr[i][j] == 'J') {
                jh = {i,j};
            }
        }
    }

    spread();
    
    int ret = escape(jh.first, jh.second);

    if (ret == -1) cout << "IMPOSSIBLE" << "\n";
    else cout << ret << "\n";
    
    return 0;
}