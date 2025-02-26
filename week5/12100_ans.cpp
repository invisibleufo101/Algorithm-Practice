#include <bits/stdc++.h>
using namespace std;
int n;
int mx;

struct Board {
    int arr[24][24];

    void _rotate(){
        int temp[24][24];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                temp[i][j] = arr[n - j -1][i];
            }
        }

        memcpy(arr, temp, sizeof(arr));
        return;
    }

    void moveBlocks(){
        int temp[24][24];
        for (int i=0; i<n; i++){
            int cols = -1; 
            bool isFirstElement = 0;
            for (int j=0; j<n; j++){
                if (arr[i][j] == 0) continue;
                if (isFirstElement && arr[i][j] == temp[i][cols]){
                    temp[i][cols] *= 2;
                    isFirstElement = 0;
                } else {
                    temp[i][++cols] = arr[i][j];
                    isFirstElement = 1;
                }
            }

            // Fill the rest of the row with zeroes after all elements have been
            // moved to certain direction
            for (cols++; cols < n; cols++) temp[i][cols] = 0;
        }

        memcpy(arr, temp, sizeof(arr));

        return;
    }

    void getMax(){
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mx = max(mx, arr[i][j]);
            }
        }
    }

    void printBoard(){
        cout << "----------------\n";
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "----------------\n";
    }

};

void solve(Board c, int cnt){
    if (cnt == 5){
        c.getMax();
        return;
    }

    for (int i=0; i<4; i++){
        Board d = c;  
        d.moveBlocks();
        solve(d, cnt+1);
        c._rotate();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    Board c;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> c.arr[i][j];
        }
    }

    solve(c, 0);
    cout << mx << "\n";

    return 0;
}