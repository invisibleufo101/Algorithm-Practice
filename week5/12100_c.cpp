#include <bits/stdc++.h>
using namespace std;
int n, mx=-1;
struct Board{
    int arr[24][24];

    void _rotate90(){
        int buffer[24][24]; 
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                buffer[i][j] = arr[n -j-1][i];
            }
        }
        memcpy(arr, buffer, sizeof(arr));
        return;
    }

    void moveBlocks(){
        stack<pair<int,bool>>stck;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (arr[i][j] == 0) continue;
                if (stck.size() && arr[i][j] == stck.top().first && stck.top().second == 0){
                    stck.pop();
                    stck.push({arr[i][j]*2, 1});
                } else {
                    stck.push({arr[i][j], 0});
                }
                arr[i][j] = 0;
            }

            int iter = stck.size() - 1;
            while(stck.size()){
                arr[i][iter] = stck.top().first;
                stck.pop();
                iter--;
            }
        }
        return;
    }

    void getMaxBlock(){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mx = max(mx, arr[i][j]);
            }
        }
        return;
    }

};

void solve(Board tmp, int cnt){
    if (cnt == 5){
        tmp.getMaxBlock();
        return;
    }

    for (int i=0; i<4; i++){
        Board c = tmp;
        c.moveBlocks();
        solve(c, cnt+1);
        tmp._rotate90();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    Board initBoard;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> initBoard.arr[i][j];
        }
    }

    solve(initBoard, 0);
    cout << mx << "\n";

    return 0;
}