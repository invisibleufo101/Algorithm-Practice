#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
int mx = 0;
pair<int,int>pr;

int main(){

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> arr[i][j];

            if (arr[i][j] >= mx){
                mx = arr[i][j];
                pr = {i,j};
            }
        }
    }

    cout << mx << "\n";
    cout << pr.first+1 << " " << pr.second+1 << "\n";

    return 0;
}