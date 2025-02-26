#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int n,k,row,col,x,l;
char c;
deque<pair<int,int>>dq;
map<int,char>dirs;

void print(int a[101][101]){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

string turn(char changeDir, string curDir){
    if (changeDir == 'L'){ // Left
        if (curDir == "Right"){
            return "Up";
        } else if (curDir == "Up"){
            return "Left";
        } else if (curDir == "Left"){
            return "Down";
        } else if (curDir == "Down"){
            return "Right";
        }
    } else if (changeDir == 'D'){ // Right
        if (curDir == "Right"){
            return "Down";
        } else if (curDir == "Up"){
            return "Right";
        } else if (curDir == "Left"){
            return "Up";
        } else if (curDir == "Down"){
            return "Left";
        }
    }
}

void moveHead(string dir){
    int y,x;
    if (dir == "Up"){
        y = dq.front().first - 1;
        x = dq.front().second;
        dq.push_front({y, x});
    } else if (dir == "Down"){
        y = dq.front().first+1;
        x = dq.front().second;
        dq.push_front({y, x});
    } else if (dir == "Left"){
        y = dq.front().first;
        x = dq.front().second - 1;
        dq.push_front({y, x});
    } else if (dir == "Right"){
        y = dq.front().first;
        x = dq.front().second+1;
        dq.push_front({y, x});
    }
}

bool isGameOver(){
    if (dq.front().first <= 0 || dq.front().second <= 0 || dq.front().first > n || dq.front().second > n) return 1;
    if (dq.back().first <= 0 || dq.back().second <= 0 || dq.back().first > n || dq.back().second > n) return 1;

    int dqSize = dq.size();
    pair<int,int> head;

    for (int i=0; i<dqSize; i++){
        if (i == 0){
            head = dq.front();
        } else {
            if (head == dq.front()) return 1;
        }

        dq.push_back(dq.front());
        dq.pop_front();
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<k; i++){
        cin >> row >> col;
        arr[row][col] = 1;
    }

    cin >> l;

    for (int i=0; i<l; i++){
        cin >> x >> c;
        dirs[x] = c;
    }

    int sec = 1;
    string curDir = "Right";
    dq.push_back({1,1});
    
    while(true){
        // Move Head
        moveHead(curDir);

        // If out of bounds or if the snake hits itself game over. 
        if (isGameOver()) break;
    
        // If there's an apple extend the head
        // else, move the tail
        if (arr[dq.front().first][dq.front().second] == 1){
            arr[dq.front().first][dq.front().second] = 0;
        } else if (arr[dq.front().first][dq.front().second] != 1){
            dq.pop_back();
        }

        if (dirs.find(sec) != dirs.end()){
            curDir = turn(dirs[sec], curDir);
        }

        sec++;
    }

    cout << sec << "\n";

    return 0;
}