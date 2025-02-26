#include <bits/stdc++.h>
using namespace std;
int n,l,r,cnt=0;
int arr[104][104];

int main(){
    cin >> n;

    for (int k=0; k<n; k++){
        cin >> l >> r;

        for (int i=r; i<r+10; i++){
            for (int j=l; j<l+10; j++){
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            if (arr[i][j]){
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}