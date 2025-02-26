#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int arr[51][51];
int visited[51][51];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>>countries;
int total_pop;

/**
 * This question is an advanced CONNECTED COMPONENTS problem
 * Main keypoint for this question:
 * - Determine how the DFS algorithm can access neighboring nodes (L <= population diff <= R)
 * - Iterate through the whole graph (if (visited[[i][j] == 0]))
 * - After the population changes, determine whether there is still a population change
 *      - IF there's no population changes, then break off the true loop
*/

void print(int a[51][51]){
    cout << "----------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;

        int diff = abs(arr[ny][nx] - arr[y][x]);

        if (diff >= l && diff <= r){
            total_pop += arr[ny][nx];
            countries.push_back({ny, nx});
            solve(ny, nx);
        }
    }
    return;
}

int go(){
    int day = 0;
    while (true){

        bool break_flag = 1;
        memset(visited, 0, sizeof(visited));
    
        // Iterating through the countries
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (visited[i][j] == 0){
                    total_pop = 0;
                    solve(i,j);

                    if (countries.size()){

                        break_flag = 0;

                        // Add the original starting country
                        total_pop += arr[i][j];
                        countries.push_back({i,j});

                        int cntry_cnt = countries.size();
                        int chnge_pop = total_pop/cntry_cnt;

                        for (auto country : countries){
                            arr[country.first][country.second] = chnge_pop;
                        }

                        countries.clear();
                    }
                }
            }
        }

        if (break_flag) return day;

        day++;   
    }
}

int main(){
    cin >> n >> l >> r;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    cout << go() << "\n";
    
    return 0;
}