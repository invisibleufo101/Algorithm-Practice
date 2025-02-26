#include <bits/stdc++.h>
using namespace std;
int n, temp, cnt;
vector<int>v;
vector<int>tmp = {24, 35, 38, 40, 49, 59, 60, 67, 83, 98};



// Check if a number is prime or not
bool check_prime(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i=3; i*i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

void search(int idx, int sum){
    if (idx == n){
        if (check_prime(sum)){
            cnt++;
        }
        return;
    }

    search(idx + 1, sum + v[idx]);
    search(idx + 1, sum);

    return;
}

int go(int idx, int sum){
    if (idx == n){
        return check_prime(sum);
    }

    return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    cnt = 0;
    search(0,0);
    cout << "Search Function: ";
    cout << cnt << "\n";

    cout << "Go Function: ";
    cout << go(0,0) << "\n";

    return 0;
}
