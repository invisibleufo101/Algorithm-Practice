#include <bits/stdc++.h>
using namespace std;
int n;
int arr[11][11];
int visited[11][11];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int min_cost = 3000; //  200 * 5 * 3 = 3000

void print(int a[11][11]){
    cout << "----------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

// Checking if seed is plantable
bool check(int y, int x){
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
        if (visited[ny][nx]) return false;
    }
    return true;
}

// Adding the cost of the 5 plantable spots
int addCost(int y, int x){
    int cost = arr[y][x];
    visited[y][x] = 1;

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        cost += arr[ny][nx];
        visited[ny][nx] = 1;
    }
    return cost;
}

void rollBack(int y, int x){
    visited[y][x] = 0;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 0;
    }
    return;
}

void dfs(int cnt, int cost){

    // std::this_thread::sleep_for(chrono::milliseconds(1000));

    if (cnt == 3){
        min_cost = min(min_cost, cost);
        return;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (check(i,j)){
                dfs(cnt+1, cost+addCost(i,j));
                print(visited);
                rollBack(i,j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0);
    cout << min_cost << "\n";

    return 0;
}