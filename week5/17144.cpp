#include <bits/stdc++.h>
using namespace std;
int r,c,t, totalDust;
int arr[54][54];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>>circulator;
vector<pair<int,int>>upperCoord;
vector<pair<int,int>>lowerCoord;

void print(){
    cout << "--------------------------------\n";
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void spread(){
    int buffer[54][54];
    memset(buffer, 0, sizeof(buffer));

    queue<pair<int,int>>dustQ;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (arr[i][j] != -1 && arr[i][j] != 0){
                dustQ.push({i,j});
            }
        }
    }

    while(dustQ.size()){
        int y,x;
        tie(y,x) = dustQ.front();
        int spreadVal = arr[y][x]; 
        dustQ.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (arr[ny][nx] == -1) continue;
            if (ny < 0 || nx < 0 || ny >=r || nx >= c) continue;

            buffer[ny][nx] += (spreadVal / 5);
            arr[y][x] -= (spreadVal / 5);
        }
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            arr[i][j] += buffer[i][j];
        }
    }

    return;
}

// Get the coordinates of the area that will be circulated by the circulator
void setup(pair<int,int>upper, pair<int,int>lower){
    
    // Upper
    for (int j=upper.second+1; j<c; j++){
        upperCoord.push_back({upper.first, j});
    }

    for (int i=upper.first-1; i>=0; i--){
        upperCoord.push_back({i, c-1});
    }

    for (int j=c-2; j>=0; j--){
        upperCoord.push_back({0, j});
    }

    for (int i=1; i<upper.first; i++){
        upperCoord.push_back({i, 0});
    }

    // Lower
    for (int j=lower.second+1; j<c; j++){
        lowerCoord.push_back({lower.first, j});
    }

    for (int i=lower.first+1; i<r; i++){
        lowerCoord.push_back({i, c-1});
    }

    for (int j=c-2; j>=0; j--){
        lowerCoord.push_back({r-1, j});
    }

    for (int i=r-2; i>lower.first; i--){
        lowerCoord.push_back({i, 0});
    }

    return;
}

void circulate(){

    for (int i=upperCoord.size()-1; i>0; i--){
        arr[upperCoord[i].first][upperCoord[i].second] = arr[upperCoord[i-1].first][upperCoord[i-1].second];
    }

    arr[upperCoord[0].first][upperCoord[0].second] = 0;

    for (int i=lowerCoord.size()-1; i>0; i--){
        arr[lowerCoord[i].first][lowerCoord[i].second] = arr[lowerCoord[i-1].first][lowerCoord[i-1].second];    
    }

    arr[lowerCoord[0].first][lowerCoord[0].second] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> t;
    
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> arr[i][j];

            if (arr[i][j] == -1){
                circulator.push_back({i,j});
            }
        }
    }

    setup(circulator[0], circulator[1]);

    while(t--){
        // 1. Spread dust
        spread();

        // 2. Circulate air
        circulate();
    }

    int amount = 0;
    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (arr[i][j] != -1){
                amount += arr[i][j];
            }
        }
    }

    cout << amount << "\n";

    return 0;
}
