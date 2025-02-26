#include <bits/stdc++.h>
using namespace std;
int arr[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int sum = 0;
    for (int i=0; i<5; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+5);
    cout << sum / 5 << "\n" << arr[2] << "\n";
    
    return 0;
}