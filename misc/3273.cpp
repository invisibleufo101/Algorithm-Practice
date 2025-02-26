#include <bits/stdc++.h>
using namespace std;
int n,x;
int arr[100001];
int cnt = 0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;

    
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i] + arr[j] == x) cnt++;
        }
    }

    cout << cnt << "\n";

    

    return 0;
}