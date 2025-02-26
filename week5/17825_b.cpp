#include <bits/stdc++.h>
using namespace std;
int t,ret=-1;
vector<int>dices;
int board[40];
int turn[40];
int visited[40];
struct horse{
    int num, pos, points;
    bool isInner, isEnd;
};
vector<horse>horses = {{1,0,0,0,0}, {2,0,0,0,0}, {3,0,0,0,0}, {4,0,0,0,0}};

void setup(){
    for (int i=1; i<21; i++) board[i] = 2*i;
    board[21] = -1;
    // Path 1
    board[22] = 13; board[23] = 16; board[24] = 19; 

    // Path 2
    board[25] = 22; board[26] = 24;

    // Path 3
    board[27] = 28; board[28] = 27; board[29] = 26;

    // Inner intersection (including center circle, 25)
    board[30] = 25; board[31] = 30; board[32] = 35; 

    // Blue circles
    turn[5] = 22; turn[10] = 25; turn[15] = 27;

    // Turnover for inner-intersection
    turn[24] = 30; turn[26] = 30; turn[29] = 30;
    turn[32] = 20;
}

void solve(int cnt){
    if (cnt == 10){
        int sum = 0;
        for (horse piece : horses) sum += piece.points;
        ret = max(ret, sum);
        return;
    }

    for (int i=0; i<4; i++){
        if (horses[i].isEnd) continue;

        int curPos = horses[i].pos;
        int nextPos = horses[i].pos;
        int curPoints = horses[i].points;
        int steps = dices[cnt];
        bool curIsInner = horses[i].isInner;
        bool nextIsInner = curIsInner;

        if (!nextIsInner){
            if (turn[nextPos]){
                nextPos = turn[nextPos];
                steps--;
                nextIsInner = 1;
            }
        }

        while(steps--){
            if (board[nextPos] == -1){
                break;
            }
            if (turn[nextPos] && nextIsInner){
                nextPos = turn[nextPos];
            } else {
                nextPos++;
            }
        }

        if (visited[nextPos] && board[nextPos] != -1) continue;

        if (nextPos == 21){
            horses[i].isEnd = 1;
        } else if (nextPos != 21){
            horses[i].points += board[nextPos];
        }

        horses[i].pos = nextPos;
        horses[i].isInner = nextIsInner;
        
        visited[curPos] = 0;
        visited[nextPos] = horses[i].num;

        solve(cnt+1);

        horses[i].pos = curPos;
        horses[i].points = curPoints;
        horses[i].isInner = curIsInner;
        horses[i].isEnd = 0;

        visited[curPos] = horses[i].num;
        visited[nextPos] = 0;
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