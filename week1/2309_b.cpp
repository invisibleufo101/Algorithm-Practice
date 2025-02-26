#include <bits/stdc++.h>
using namespace std;

// 9c2 == 9c7

int a[9];
int sum;
pair<int, int> pr;
vector<int>v;
int x,y;

// 9c7 == 9c2
// Originally, we are supposed to use 9c7, but we can think the opposite and use 9c2
// Since we are trying to figure out which 7 gnomes have the height sum of 100,
// this is same as trying to see which 2 gnomes are equal to 100 
// when subtracted by the total height of ALL gnomes
// (Pick 7 out of 9 for 100) == TOTAL HEIGHT - (Pick 2 out of 9)
void solve(){
    for (int i=0; i<9; i++){
        for(int j=0; j<i; j++){
            if (sum - a[i] - a[j] == 100){
                //store the index of the 2 WRONG gnomes in pair
                pr = {i, j};
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // store the height of ALL gnomes in array 
    for(int i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }

    solve();

    // iterate through the array
    // ADD the gnomes that match the height sum of 100
    // CONTINUE if the index of the gnome matches the index of the WRONG gnomes that we stored in pair
    for (int i=0; i<9; i++){
        if (pr.first == i || pr.second == i){
            continue;
        }
        v.push_back(a[i]);
    }

    // Sort from least to greatest
    sort(v.begin(), v.end());

    for(int i : v) cout << i << "\n";
    
    return 0;
}   