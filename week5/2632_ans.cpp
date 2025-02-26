#include <bits/stdc++.h>
using namespace std;
int target,m,n,a,b;
int pizzaA[1001], pizzaB[1001], psumA[2002], psumB[2002];
map<int,int>aCnt, bCnt;

void solve(int n, int psum[], map<int,int>& mp){
    for (int interval=1; interval<=n; interval++){
        for (int start=interval; start<=n+interval-1; start++){
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if (interval == n) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> target >> m >> n;

    // Getting input & making prefix sum array
    for (int i=1; i<=m; i++){
        cin >> pizzaA[i];
        psumA[i] = psumA[i-1] + pizzaA[i];
    }

    // To convert a circular structure into a linear one, 
    // we can simply add the same values at the end.
    // [1,2,3,4] => [1,2,3,4,1,2,3,4]
    // -> This way, no matter what the interval is 
    // we can have the total possible number of outcomes
    for (int i=m+1; i<=2*m; i++){
        psumA[i] = psumA[i-1] + pizzaA[i - m];
    }

    // Same as pizza A
    for (int i=1; i<=n; i++){
        cin >> pizzaB[i];
        psumB[i] = psumB[i-1] + pizzaB[i];
    }

    for (int i=n+1; i<=2*n; i++){
        psumB[i] = psumB[i-1] + pizzaB[i - n];
    }

    solve(m, psumA, aCnt);
    solve(n, psumB, bCnt);

    // Case for each pizza having the required amount of slices
    int ret = (aCnt[target] + bCnt[target]);
    // Each map stores the number of times 
    // when every possible combination has amounted to a specific sum
    
    // By iterating through both maps and multiplying both occurences,
    // we get the total number of outcomes where slices from both pizza A and B 
    // match the target
    for (int i=1; i<target; i++){
        ret += (aCnt[i] * bCnt[target - i]);
    }

    cout << ret << "\n";
    
    return 0;
}