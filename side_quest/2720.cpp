#include <bits/stdc++.h>
using namespace std;
int t,c;
int arr[51];

int main(){
    cin >> t;
    while (t--){
        cin >> c;

        memset(arr, 0, sizeof(arr));

        while (c > 0){
            if (c >= 25){
                c -= 25;
                arr[25]++;
            } else if (c >= 10){
                c -= 10;
                arr[10]++;
            } else if (c >= 5){
                c -= 5;
                arr[5]++;
            } else if (c >= 1){
                c--;
                arr[1]++;
            }
        }

        cout << arr[25] << " " << arr[10] << " " << arr[5] << " " << arr[1] << "\n";
    }

    return 0;
}