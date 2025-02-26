#include <bits/stdc++.h>
using namespace std;
int t, ret = -1;
vector<int>dices;
int board[34], score[34], turn[34], visited[34], position[4];

void setup(){
    for (int i=0; i<21; i++) board[i] = i+1;
    board[21] = 21;
    for (int i=22; i<27; i++) board[i] = i+1;
    board[27] = 20;
    board[28] = 29; board[29] = 30; board[30] = 25;
    board[31] = 32; board[32] = 25;

    turn[5] = 22; turn[10] = 31; turn[15] = 28;

    for(int i=0; i<21; i++) score[i] = 2*i;
    score[22] = 13; score[23] = 16; score[24] = 19; score[25] = 25;
    score[26] = 30; score[27] = 35; score[28] = 28;
}

void solve(int cnt){
    if (cnt == 10){

        return;
    }

    for (int i=0; i<4; i++){
        
        solve(cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<10; i++){
        cin >> t;
        dices.push_back(t);
    }

    return 0;
}