#include <bits/stdc++.h>
using namespace std;
int n;
int arr[101];
vector<int>v;
int cnt;

bool checkPrime(int n){
    if (n <= 1) return false; 
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;

    for (int i=3; i*i <= n; i++){
        if (n % i == 0) return false;
    }

    return true;
}

void combi(int depth, int r, vector<int>v){
    if (v.size() == r){

        int sum = accumulate(v.begin(), v.end(), 0);
        if (checkPrime(sum)){
            cnt++;
        }
        return;
    }

    for (int i=depth+1; i<n; i++){
        v.push_back(arr[i]);
        combi(i, r, v);
        v.pop_back();
    }

    return;
}

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cnt = 0;

    for (int i=1; i<=n; i++){
        vector<int>v;
        combi(-1, i, v);
    }

    cout << cnt << "\n";

    return 0;
}

// 10
// 24 35 38 40 49 59 60 67 83 98 

