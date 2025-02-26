#include <bits/stdc++.h>
using namespace std;
int n, arr[21][21];
int mx = -1;

void print(int a[21][21]){
    cout << "-----------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void check(int a[21][21]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            mx = max(mx, a[i][j]);
        }
    }
}

void moveUp(int a[21][21]){
    stack<pair<int,bool>>stck;
    for (int j=0; j<n; j++){
        for (int i=0; i<n; i++){
            if (a[i][j]){
                if (stck.size() && a[i][j] == stck.top().first && stck.top().second == 0){
                    stck.pop();
                    stck.push({a[i][j] * 2, 1});
                } else {
                    stck.push({a[i][j], 0});
                }
            }
            a[i][j] = 0;
        }

        int iter = stck.size() - 1;
        while(stck.size()){
            a[iter][j] = stck.top().first;
            stck.pop();
            iter--;
        }
    }
}

void moveDown(int a[21][21]){
    stack<pair<int,bool>>stck;
    for (int j=n-1; j>=0; j--){
        for (int i=n-1; i>=0; i--){
            if (a[i][j]){
                if (stck.size() && a[i][j] == stck.top().first && stck.top().second == 0){
                    stck.pop();
                    stck.push({a[i][j] * 2, 1});
                } else {
                    stck.push({a[i][j], 0});
                }
            }
            a[i][j] = 0;
        }
        
        int iter = n - stck.size();
        while(stck.size()){
            a[iter][j] = stck.top().first;
            stck.pop();
            iter++;
        }
    }
}

void moveLeft(int a[21][21]){
    stack<pair<int,bool>>stck;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j]){
                if (stck.size() && a[i][j] == stck.top().first && stck.top().second == 0){
                    stck.pop();
                    stck.push({a[i][j] * 2, 1});
                } else {
                    stck.push({a[i][j], 0});
                }
            }
            a[i][j] = 0;
        }

        int iter = stck.size() - 1;
        while(stck.size()){
            a[i][iter] = stck.top().first;
            stck.pop();
            iter--;
        }
    }
}

void moveRight(int a[21][21]){
    stack<pair<int,bool>>stck;
    for (int i = n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if (a[i][j]){
                if (stck.size() && a[i][j] == stck.top().first && stck.top().second == 0){
                    stck.pop();
                    stck.push({a[i][j] * 2, 1});
                } else {
                    stck.push({a[i][j], 0});
                }
            }
            a[i][j] = 0;
        }

        int iter = n - stck.size();
        while(stck.size()){
            a[i][iter] = stck.top().first;
            stck.pop();
            iter++;
        }
    }
}


void execute(int a[21][21], vector<int>d){
    
    for (int i : d){
        switch (i){
            case 0:
                moveUp(a);
                break;
            case 1:
                moveDown(a);
                break;
            case 2:
                moveLeft(a);
                break;
            case 3:
                moveRight(a);
                break;
        }
    }

    check(a);
}

void solve(vector<int>dirs){
    if (dirs.size() == 5){
        int tmp[21][21];
        memcpy(tmp, arr, sizeof(arr));
        execute(tmp, dirs);

        return;
    }

    for (int i=0; i<4; i++){
        dirs.push_back(i);
        solve(dirs);
        dirs.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int>t;
    solve(t);

    cout << mx << "\n";

    return 0;
}

// 4
// 2 0 2 8
// 0 0 2 2
// 0 0 0 0
// 0 0 0 0
// Ans: 16

// 4
// 2 4 16 8
// 8 4 0 0
// 16 8 2 0
// 2 8 2 0
// Ans: 32