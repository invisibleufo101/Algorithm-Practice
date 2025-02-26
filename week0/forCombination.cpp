#include <bits/stdc++.h>
using namespace std;

int n = 5;

void combination(){

    // Each for loop represents the number of selection
    for (int i=0; i<n; i++){
        // cout << "i :" << i << "\n";
        // cout << "------------\n";
        for (int j=i+1; j<n; j++){
            // cout << "j :" << j << "\n";
            for (int k=j+1; k<n; k++){
                // cout << "k :" << k << "\n";
                cout << i << j << k << "\n";
            }
        }
    }
}

int main(){
    combination();
    return 0;
}