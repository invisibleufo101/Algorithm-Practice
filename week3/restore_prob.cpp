#include <bits/stdc++.h>
using namespace std;
vector<int>v [3]= {
    {10, 20, 21}, 
    {70, 90, 12},
    {80, 110, 120} 
};
vector<int>sum;
int visited[3][3];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void printSum(){
    for (int i : sum) cout << i << " ";
    cout << "\n";
}

void go(int y, int x){

    if (y == 2 && x == 2){
        printSum();
        return;
    }

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;
        if (visited[ny][nx]) continue;
        
        visited[ny][nx] = 1;
        sum.push_back(v[ny][nx]);

        go(ny, nx);

        visited[ny][nx] = 0;
        sum.pop_back();
    }
}

int main(){
    int strt = 0, ed = 0;
    visited[strt][ed] = 1;
    sum.push_back(v[0][0]);

    go(strt,ed);

    return 0;
}