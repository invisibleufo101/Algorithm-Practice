#include <bits/stdc++.h>
using namespace std;
int t,ret=-1;
vector<int>dices;
vector<vector<int>>board = {
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0},
    {0,2,4,6,8,10,13,16,19,25,30,35,40,0},
    {0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40,0},
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40,0}
};
int points[4];
int horsePos[4];
vector<vector<int>>visited = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

struct horse{
    int num, points, pos, pathNum, isEnd;
};
vector<horse>horses = {{1,0,0,0,0}, {2,0,0,0,0}, {3,0,0,0,0}, {4,0,0,0,0}};
map<int,vector<pair<int,int>>>intersect;

void setup(){
    intersect[25] = {{1,9}, {2,13}, {3,19}};
    intersect[30] = {{1,10}, {2,14}, {3,20}};
    intersect[35] = {{1,11}, {2,15}, {3,21}};
    intersect[40] = {{0,20}, {1,12}, {2,16}, {3,22}};
}

void solve(int cnt){
    if (cnt == 10){
        int sum = 0;
        for (auto piece : horses) sum += piece.points;
        ret = max(ret, sum);
        return;
    }

    for (int i=0; i<4; i++){
        if (horses[i].isEnd) continue;

        horse curHorse = horses[i];

        int curHorseNum = curHorse.num;

        int curPos = curHorse.pos;
        int nextPos = curHorse.pos;

        int curPoint = curHorse.points;

        int curPathNum = curHorse.pathNum;
        int nextPathNum = curPathNum;

        int steps = dices[cnt];

        if (curPathNum == 0){
            if (nextPos == 5){
                nextPathNum = 1;
            } else if (nextPos == 10){
                nextPathNum = 2;
            } else if (nextPos == 15){
                nextPathNum = 3;
            }
        }

        nextPos += steps;

        // If there is another horse at the destination 
        // and that destination is not the end point
        if (nextPathNum == 0){
            nextPos = min(nextPos, 21);
            if (visited[0][nextPos] && nextPos != 21) continue;
            if (board[0][nextPos] == 40){
                bool flag = 0;
                for (auto pr : intersect[40]){
                    if (pr.first == nextPathNum) continue;
                    if (visited[pr.first][pr.second]){
                        flag = 1;
                        break;
                    }
                }

                if (flag) continue;
            }
            if (nextPos == 21) horses[i].isEnd = 1;

        } else if (nextPathNum == 1){
            nextPos = min(nextPos, 13);
            if (visited[1][nextPos] && nextPos != 13) continue;
            if (board[nextPathNum][nextPos] == 25 ||
                board[nextPathNum][nextPos] == 30 ||
                board[nextPathNum][nextPos] == 35 ||
                board[nextPathNum][nextPos] == 40
            ){
                bool flag = 0;
                for (auto pr : intersect[board[nextPathNum][nextPos]]){
                    if (pr.first == nextPathNum) continue;
                    if (visited[pr.first][pr.second]){
                        flag = 1;
                        break;
                    }
                }

                if (flag) continue;
            }
            if (nextPos == 13) horses[i].isEnd = 1;

        } else if (nextPathNum == 2){
            nextPos = min(nextPos, 17);
            if (visited[2][nextPos] && nextPos != 17) continue;
            if (board[nextPathNum][nextPos] == 25 ||
                board[nextPathNum][nextPos] == 30 ||
                board[nextPathNum][nextPos] == 35 ||
                board[nextPathNum][nextPos] == 40
            ){
                bool flag = 0;
                for (auto pr : intersect[board[nextPathNum][nextPos]]){
                    if (pr.first == nextPathNum) continue;
                    if (visited[pr.first][pr.second]){
                        flag = 1;
                        break;
                    }
                }

                if (flag) continue;
            }
            if (nextPos == 17) horses[i].isEnd = 1;

        } else if (nextPathNum == 3){
            nextPos = min(nextPos, 23);
            if (visited[3][nextPos] && nextPos != 23) continue;
            if (board[nextPathNum][nextPos] == 25 ||
                board[nextPathNum][nextPos] == 30 ||
                board[nextPathNum][nextPos] == 35 ||
                board[nextPathNum][nextPos] == 40
            ){
                bool flag = 0;

                for (auto pr : intersect[board[nextPathNum][nextPos]]){
                    if (pr.first == nextPathNum) continue;
                    if (visited[pr.first][pr.second]){
                        flag = 1;
                        break;
                    }
                }

                if (flag) continue;
            }
            if (nextPos == 23) horses[i].isEnd = 1;

        }

        horses[i].points += board[nextPathNum][nextPos];
        horses[i].pos = nextPos;
        horses[i].pathNum = nextPathNum;

        visited[curPathNum][curPos] = 0;
        visited[nextPathNum][nextPos] = curHorseNum;

        solve(cnt+1);

        horses[i].points = curPoint;
    
        horses[i].pos = curPos;

        horses[i].pathNum = curPathNum;
        horses[i].isEnd = 0;

        visited[curPathNum][curPos] = curHorseNum;
        visited[nextPathNum][nextPos] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<10; i++){
        cin >> t;
        dices.push_back(t);
    }

    setup();
    solve(0);
    cout << ret << "\n";

    return 0;
}

// Debug
// this_thread::sleep_for(chrono::milliseconds(300));
// cout << "Horse Info:\n";
// cout << "COUNT: " << cnt << "\n";
// cout << "------------------------------\n";
// cout << "Horse # " << curHorseNum << "\n";
// cout << "Dice: " << dices[cnt] << "\n";
// cout << "Points: " << horses[i].points << "\n";
// cout << "Pos: " << horses[i].pos << "\n";
// cout << "Path Num: " << horses[i].pathNum << "\n";
// cout << "isEnd: " << horses[i].isEnd << "\n";
// cout << "------------------------------\n";

// for (int i=0; i<visited.size(); i++){
//     for (int j=1; j<visited[i].size(); j++){
//         cout << visited[i][j] << " ";
//     }
//     cout << "\n";
// }
// cout << "\n";