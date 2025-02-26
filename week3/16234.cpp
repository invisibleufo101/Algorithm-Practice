#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int sum;
int arr[51][51];
int visited[51][51];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>>v;
map<pair<int,int>,vector<pair<int,int>>>mp;

void print(int a[51][51]){
    cout << "-------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void go(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (abs( arr[ny][nx] - arr[y][x]) < l || abs( arr[ny][nx] - arr[y][x]) > r) continue;
    
        // Get the sum of population & number of countries
        sum += arr[ny][nx];
        // Get the coordinates of the countries
        v.push_back({ny, nx});

        go(ny, nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> l >> r;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }   
    }

    int day_cnt = 0;

    while (true){

        bool isChange = 0;
        memset(visited, 0, sizeof(visited));

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (visited[i][j] == 0){
                    v.clear();

                    // Initialize getting population & country coordinates
                    v.push_back({i,j});
                    sum = arr[i][j];

                    go(i,j);

                    // IF the starting country's position is deadlocked
                    if (v.size() == 1) continue;

                    // Change the population
                    int pop = sum / v.size();
                    for (auto i : v){
                        arr[i.first][i.second] = pop;
                        isChange = 1;
                    }
                }
            }
        }

        print(arr);

        if (!isChange) break;
        day_cnt++;
    }
    cout << "-------------\n";
    
    cout << day_cnt << "\n";

    return 0;
}