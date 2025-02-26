#include <bits/stdc++.h>
using namespace std;
int n;
int arr[51];

int main(){
    cin >> n;
    int mx = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    if (n == 1){
        cout << arr[0] * arr[0] << "\n";
        return 0;
    }

    int i = mx+1;
    while (true){
        bool flag = 1;
        for (int x=0; x<n; x++){
            if (i % arr[x] != 0){
                flag = 1;
                break;
            } else {
                flag = 0;
            }
        }

        if (flag == 0){
            cout << i << "\n";
            break;
        }

        i++;
    }

    return 0;
}