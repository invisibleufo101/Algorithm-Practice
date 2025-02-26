#include <bits/stdc++.h>
using namespace std;

int n = 5;
int visited[5];

void print(int a[5]){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void solve(int idx){
    if (idx == n){
        print(visited);
        return;
    }

    visited[idx] = 1;
    solve(idx + 1);

    visited[idx] = 0;
    solve(idx + 1);    

}

void bitMaskCombo(int idx){
    for (int i=0; i<(1 << idx); i++){
        for (int j=0; j<idx; j++){
            if (i & (1 << j)){
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    // solve(0);
    bitMaskCombo(5);
    
    return 0;
}