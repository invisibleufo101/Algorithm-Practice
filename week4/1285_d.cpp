#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char arr[21][21];
int visited[21][21];
int ret = 450;

void printCoins(){
    cout << "------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------------------\n";
}

void flipByCol(int col){
    for (int i=0; i<n; i++){
        if (arr[i][col] == 'H'){
            arr[i][col] = 'T';
        } else if (arr[i][col] == 'T'){
            arr[i][col] = 'H';
        }
    }
}

void flipByRow(int row){
    for (int j=0; j<n; j++){
        if (arr[row][j] == 'H'){
            arr[row][j] = 'T';
        } else if (arr[row][j] == 'T'){
            arr[row][j] = 'H';
        }
    }
}

int countTails(){
    int totalT = 0;
    for (int j=0; j<n; j++){
        int cntH = 0;
        int cntT = 0;
        for (int i=0; i<n; i++){
            if (arr[i][j] == 'H'){
                cntH++;
            } else {
                cntT++;
            }
        }

        if (cntT > cntH){
            totalT += cntH;
        } else {
            totalT += cntT;
        }
    }

    return totalT;
}

void solve(int idx){
    if (idx == n){
        ret = min(ret, countTails());
        return;
    }

    solve(idx+1);

    flipByRow(idx);
    solve(idx+1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // When we are flipping coins, 
    // the number of tails MUST be greater or equal to 2
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr[i][j] = s[j];
        }
    }

    solve(0);
    cout << ret << "\n";

    return 0;
}