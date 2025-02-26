#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000001];
stack<int>stck;

int main(){
    cin >> n;
    vector<int>v(n,-1);

    for (int i=0; i<n; i++){
        cin >> arr[i];
        while (stck.size() && arr[i] > arr[stck.top()]){
            v[stck.top()] = arr[i];
            stck.pop();
        }
        stck.push(i);
    }

    for (int i : v) cout << i << " ";
    cout << "\n";

    return 0;
}