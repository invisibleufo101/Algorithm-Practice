#include <bits/stdc++.h>
using namespace std;
int n,m,t,x,d,k;
int arr[54][54], visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool isNotDupe = 1;

void _rotate(int y, int dir,int k){
    vector<int>v;
    // Get the values of the targeted circle
    for (int i=0; i<m; i++) v.push_back(arr[y][i]);
    // Rotate values
    // 1-> clockwise
    // 0-> counter-clockwise
    if (dir == 1) rotate(v.begin(), v.begin()+k, v.end());
    else if (dir == 0) rotate(v.begin(), v.begin()+ m - k, v.end());

    // Put the rotated values back into the original
    for (int i=0; i<m; i++){
        arr[y][i] = v[i];
    }
}

void dfs(int y, int x){
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;

        if (ny < 0 || ny >= n) continue;
        if (visited[ny][nx]) continue;
        if (arr[y][x] == arr[ny][nx]){
            visited[y][x] = visited[ny][nx] = 1;
            isNotDupe = 0; // Flag to indicate whether duplicate is there or not
            dfs(ny,nx);
        }
    }
}

bool findAdj(){
    isNotDupe = 1; // Duplicate flag
    memset(visited, 0, sizeof(visited));

    // Iterate through the circles
    // and use DFS to mark the duplicate spots
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (visited[i][j]) continue;
            if (arr[i][j]){
                dfs(i,j);
            }
        }
    }

    // Since the visited array shows where the duplicates are,
    // erase the duplicates.
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (visited[i][j]) arr[i][j] = 0;
        }
    }

    return isNotDupe;
}

void setAverage(){
    int sum = 0;
    int cnt = 0;

    // Iterate through circles and get average value
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j]){
                sum += arr[i][j];
                cnt++;
            }
        }
    }

    // Change val of circle
    double avg = (double) sum / (double) cnt;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j]){
                if ((double) arr[i][j] > avg) arr[i][j]--;
                else if ((double)arr[i][j] < avg) arr[i][j]++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> x >> d >> k;
        // Iterate through all circles that are multiples of X
        for (int j=x-1; j<n; j+=x){
            _rotate(j,d,k);
        }
        if (findAdj()) setAverage();
    }

    return 0;
}