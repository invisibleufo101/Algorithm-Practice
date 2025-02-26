#include <bits/stdc++.h>
using namespace std;
int t,n,arr[1004];

int main(){
    cin >> t;
    for (int j=0; j<t; j++){

        cin >> n;
        cout << "Denominations: ";
        for (int i=0; i<n; i++){
            cin >> arr[i];
            cout << arr[i] << " ";
        }
        cout << "\n";

        bool isValid = 1;
        for (int i=0; i<n-1; i++){
            if (arr[i]*2 > arr[i+1]){
                isValid = 0;
                break;
            }
        }

        if (isValid) cout << "Good coin denominations!\n";
        else cout << "Bad coin denominations!\n";

        if (j != t-1) cout << "\n";

        memset(arr, 0, sizeof(arr));
    }

    return 0;
}