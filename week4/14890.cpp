#include <bits/stdc++.h>
using namespace std;
int n,l;
int a[101][101];
int ta[101][101];
int isRamped[101][101];

void print1(int temp[101][101]){
    cout << "----------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
}

void print2(int temp[101][101]){
    cout << "----------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << temp[j][i] << " ";
        }
        cout << "\n";
    }
}

void reset(int row){
    for (int i=0; i<n; i++){
        isRamped[row][i] = 0;
    }
}

int layDownRamps(int arr[101][101]){
    int cnt = 0;
    memset(isRamped, 0, sizeof(isRamped));

    for (int i=0; i<n; i++){

        int sameHeightCnt = 1;
        bool isFullClear = 1;
        bool resetFlag = 0;

        for (int j=0; j<n-1; j++){
    
            int heightDiff = abs(arr[i][j] - arr[i][j+1]);

            if (heightDiff > 1) {

                resetFlag = 1;
                isFullClear = 0;
                break;
            }

            if (heightDiff == 0){
                sameHeightCnt++;
                continue;
            }

            if (heightDiff == 1){

                if (arr[i][j] < arr[i][j+1]){

                    if (sameHeightCnt >= l && j-l+1 >= 0){

                        bool breakFlag = 0;

                        for (int k=j-l+1; k <= j; k++){

                            if (isRamped[i][k]){
                                breakFlag = 1;
                                break;
                            }

                            isRamped[i][k] = 1;
                        }

                        if (breakFlag){

                            isFullClear = 0;
                            resetFlag = 1;
                            break;
                        }
                    } else {
                    
                        resetFlag = 1;
                        isFullClear = 0;
                        break;
                    }

                } else if (arr[i][j] > arr[i][j+1]){

                    if (j+l <= n-1){

                        bool breakFlag = 0;

                        for (int k=j+1; k<=j+l; k++){
                            if (arr[i][k] != arr[i][j+1]){
                                breakFlag = 1;
                                break;   
                            }

                            isRamped[i][k] = 1;
                        }

                        if (breakFlag){
                         
                            resetFlag = 1;
                            isFullClear = 0;
                            break;
                        }

                    } else {
                    
                        isFullClear = 0;
                        resetFlag = 1;
                        break;
                    }
                    
                }
            }
        }

        if (resetFlag) {
            reset(i);
        }
        if (isFullClear) cnt++;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];

            ta[j][i] = a[i][j];
        }
    }

    int row = layDownRamps(a);
    // print1(isRamped);
    // cout << row << "\n";

    int col = layDownRamps(ta);
    // print2(isRamped);
    // cout << col << "\n";

    cout << row + col << "\n";

    return 0;
}