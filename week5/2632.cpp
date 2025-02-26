#include <bits/stdc++.h>
using namespace std;
int target,n,m,a,b,cnt;
vector<int>pizzaA,pizzaB;
map<int,int>mpA,mpB;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> target >> m >> n;
    for (int i=0; i<m; i++){
        cin >> a;
        pizzaA.push_back(a);
    }

    for (int i=0; i<n; i++){
        cin >> b;
        pizzaB.push_back(b);
    }

    for (int i=0; i<m; i++){
        int sum = 0;
        for (int j=0; j<m; j++){
            sum += (pizzaA[(i+j)%m]);
            if (j < m-1) mpA[sum]++;
        }
    }

    int sumA = accumulate(pizzaA.begin(), pizzaA.end(), 0);
    mpA[sumA]++;

    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=0; j<n; j++){
            sum += (pizzaB[(i+j)%n]);
            if (j < n-1) mpB[sum]++;
        }
    }

    int sumB = accumulate(pizzaB.begin(), pizzaB.end(), 0);
    mpB[sumB]++;

    if (mpA.count(target)) cnt += mpA[target];
    if (mpB.count(target)) cnt += mpB[target];

    for (auto it : mpA){
        int comp = target - it.first;
        if (mpB.find(comp) != mpB.end()){
            cnt += (it.second * mpB[comp]);
        }
    }

    cout << cnt << "\n";

    return 0;
}

// 7
// 5 3
// 2
// 2
// 1
// 7
// 2
// 6
// 8
// 3

// 6 
// 3 3 
// 1 1 1
// 1 1 1 