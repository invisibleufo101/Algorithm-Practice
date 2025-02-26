#include <bits/stdc++.h>
using namespace std;
int dices[10];
int horses[4];
vector<int> adj[54];
int score[104];

void printBoard(){
    for (int i=0; i<32; i++){
        cout << i << " : ";
        for (int j=0; j<adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int move(int here, int cnt){
    if (here == 100) return 100;
    // If the horse starts at the cross-road point(5, 10, 15),
    // Direct it to the inner alternate path 
    if (adj[here].size() >= 2){
        here = adj[here][1]; 
        cnt--; // Deduct move cnt
    }
    // If the horse still needs to move,
    if (cnt){
        queue<int>q;
        q.push(here);
        int there;
        while(q.size()){
            int x = q.front(); 
            q.pop();
            there = adj[x][0];
            q.push(there);

            if(there == 100) break;
            cnt--;
            if (cnt == 0) break;
        }
        return there;
    } else {
        return here;
    }
}

bool hasAnotherHorse(int horseIdx, int idx){
    // 100 represents the end point
    if (horseIdx == 100) return 0;
    // Iterate through all horses
    for (int i=0; i<4; i++){
        if (i == idx) continue;
        if(horses[i] == horseIdx) return 1;
    }
    return 0;
}

void add(int start, int end){
    adj[start].push_back(end);
}

void setup(){
    // The points that have cross roads have two children nodes (5, 10, 15)
    for (int i=0; i<20; i++) add(i, i+1);
    add(5, 21); add(21, 22); add(22, 23); add(23, 24); 
    add(15, 29); add(29, 30); add(30, 31); add(31, 24);

    add(10, 27); add(27, 28); add(28, 24); add(24, 25);
    add(25, 26); add(26, 20);

    add(20, 100); // <- 100 means END

    for (int i=1; i<21; i++) score[i] = i*2;
    score[21] = 13; score[22] = 16; score[23] = 19;
    score[24] = 25; score[25] = 30; score[26] = 35;
    score[27] = 22; score[28] = 24; score[29] = 28;
    score[30] = 27; score[31] = 26;
}

int solve(int here){
    if (here == 10) return 0;
    int ret = 0;
    for (int i=0; i<4; i++){
        int tempIdx = horses[i];
        // Move horse by dice val
        int horseIdx = move(tempIdx, dices[here]);
        // If there's already another horse, skip this dice val
        if(hasAnotherHorse(horseIdx, i)) continue;
        // Move horse according to the current dice val
        horses[i] = horseIdx;
        
        ret = max(ret, solve(here+1) + score[horseIdx]);

        // Backtrack - Reset horse position to its original spot
        horses[i] = tempIdx;
    }

    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<10; i++) cin >> dices[i];
    setup();
    // printBoard();

    cout << solve(0) << "\n";

    return 0;
}