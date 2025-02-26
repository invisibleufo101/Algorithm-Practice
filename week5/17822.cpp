#include <bits/stdc++.h>
using namespace std;
int n,m,t,num,x,d,k;
vector<vector<int>>circles;
struct instr{
    int targetNum, dir, rotateVal;
}; 
vector<instr>instructions;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[54][54];
set<pair<int,int>>coords;

void print(){
    cout << "-----------------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << circles[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkAdjDuplicates(){
    for (int y=0; y<n; y++){
        for (int x=0; x<m; x++){
            if (circles[y][x]){
                int val = circles[y][x];

                for (int i=0; i<4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                    if (circles[ny][nx] == val) return true;
                }
            }
        }
    }
    return false;
}

void dfs(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;

        if (visited[ny][nx]) continue;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (circles[ny][nx] == 0) continue;

        if (circles[ny][nx] == circles[y][x]){
            coords.insert({ny,nx});
            dfs(ny,nx);
        }
    }
}

void removeDupeVal(){
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (circles[i][j]){
                coords.insert({i,j});
                dfs(i,j);
                if (coords.size() > 1){
                    for (auto coord : coords) circles[coord.first][coord.second] = 0;
                }
                coords.clear();
            }
        }
    }
}

double getAverage(){
    double sum = 0;
    int cnt = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){    
            if (circles[i][j]){
                sum += circles[i][j];
                cnt++;
            }
        }
    }
    double avg = sum / cnt;
    return avg;
}

void changeVal(double avg){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (circles[i][j] != 0){
                if (circles[i][j] > avg) circles[i][j]--;
                else if (circles[i][j] < avg) circles[i][j]++;
            }
        }
    }
}

void solve(){
    for (instr instruction : instructions){
        int targetNum = instruction.targetNum;
        int dir = instruction.dir;
        int rotateVal = instruction.rotateVal;

        // Step 1
        for (int j=0; j<circles.size(); j++){
            if ((j+1) % targetNum == 0){
                if (dir == 0) rotate(circles[j].rbegin(), circles[j].rbegin()+rotateVal, circles[j].rend());
                else if (dir == 1) rotate(circles[j].begin(), circles[j].begin()+rotateVal, circles[j].end());
            }
        }

        // Step 2
        if (checkAdjDuplicates()){
            // 2-1) If there are adjacent duplicates,
            removeDupeVal();
        } else if (!checkAdjDuplicates()){
            // 2-2) If there are none
            double totalAvg = getAverage();
            changeVal(totalAvg);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> t;

    for (int i=0; i<n; i++){
        vector<int>tmp;
        for (int j=0; j<m; j++){
            cin >> num;
            tmp.push_back(num);
        }
        circles.push_back(tmp);
    }

    for (int i=0; i<t; i++){
        cin >> x >> d >> k;
        instructions.push_back({x,d,k});
    }

    solve();
    
    int ret = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ret += circles[i][j];
        }
    }

    cout << ret << "\n";

    return 0;
}