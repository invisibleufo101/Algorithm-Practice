#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[21];
int originalState[21];
int tails;
int ret = 450; // Max # of tails = 400

void printArr(){
    // Remember to change the bitset size!
    cout << "---------------\n";
    for (int i=0; i<n; i++){
        string binary = bitset<3>(arr[i]).to_string();
        for (int i=0; i<binary.length(); i++){
            cout << binary[i] << " ";
        }
        cout << "\n";
    }
}

void flipByCol(int col){
    for (int i=0; i<n; i++){
        arr[i] ^= (1 << (n-1-col));
    }
}

void flipByRow(int row){
    for (int i=0; i<n; i++){
        arr[row] ^= (1 << i);
    }
}

int countTails(){
    // This time instead of actually flipping,
    // IF number of tails is greater than tails, 
    // then we are just gonna count the number of tails as number of heads 
    // - just pretending to have actually flipped

    int totalH = 0;
    int totalT = 0;

    for (int j=0; j<n; j++){
        int cntH = 0;
        int cntT = 0;

        for (int i=0; i<n; i++){
            
            if (arr[i] & (1 << (n-1-j))){
                cntH++;
            } else {
                cntT++;
            }
        }

        if (cntT > cntH){
            totalT += cntH;
        } else {
            totalT += cntT;
        }
    }

    return totalT;
}

void solve(int idx){
    if (idx == n){
        ret = min(ret, countTails());
        return;
    }

    solve(idx+1);

    arr[idx] = ~arr[idx];
    solve(idx+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        // Turn all the bits on 
        int c = (1 << n) - 1;
        for (int j=0; j<n; j++){
            // Turn off bits that are tails
            if (s[j] == 'T'){
                c &= ~(1 << (n-1-j));
            }
        }

        arr[i] = c;
    }

    solve(0);
    cout << ret << "\n";

    return 0;
}