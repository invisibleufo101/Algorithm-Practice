#include <bits/stdc++.h>
using namespace std;
int n,x;
int arr[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int>v (n, -1);
    stack<int>stck;

    for (int i=n-1; i>=0; i--){

        while(stck.size() && stck.top() <= arr[i]){
            stck.pop();
        }

        if (!stck.size()) v[i] = -1;
        else v[i] = stck.top();

        stck.push(arr[i]);
    }
    
    for (int i : v) cout << i << " ";
    cout << "\n";

    return 0;
}

/**
 * TCs
*/

// 7
// 4 2 2 1 2 3 4
// Ans: -1 3 3 2 3 -1

// 3
// 1 1 2
// Ans: 2 2 -1

// 5
// 1 8 5 7 9
// Ans: 8 9 7 9 -1 