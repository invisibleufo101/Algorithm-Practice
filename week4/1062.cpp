#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
vector<int>leftOverLetters;
int baseLetters = 0;
int bitWords[51];
int ret = 0;
set<int>st;

// For debugging
// To see what kind of combination of letters each case is producing
void convert(string bin){
    reverse(bin.begin(), bin.end());

    for (int i=0; i<bin.length(); i++){
        if (bin[i] == '1'){
            cout << char(i + 'a') << " ";
        }
    }
    cout << "\n";
}

// Checks how many words can be made with this specific combination of letters
int check(int val){
    int cnt = 0;
    for (int i=0; i<n; i++){
        int bitWord = bitWords[i];

        if ((bitWord & val) == bitWord) cnt++;
    }
    return cnt;
}

// We only care about making combination of : 
// baseLetters (a,c,i,nt) + @ (whatever leftOverLetters has)

void combi(int start, int val, int cnt){
    // Set size referring to the total number of possible letter combinations
    if (cnt == st.size()){
        ret = max(ret, check(val));
        return;
    }

    for (int i=start+1; i<leftOverLetters.size(); i++){
        cnt++;
        val |= leftOverLetters[i]; // Add leftovers

        combi(i, val, cnt);

        cnt--;
        val &= ~(leftOverLetters[i]); // Remove leftovers
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> s;

        for (char c : s){

            bitWords[i] |= (1 << int(c - 'a'));

            if (c == 'a' || c == 'c' || c == 'i' || c == 'n' || c == 't'){
                baseLetters |= (1 << int(c - 'a'));
            } else {
                st.insert(1 << int(c - 'a'));
            }  
        }
    }

    if (k < 5){
        cout << 0 << "\n";
        return 0;
    }

    // If the number of letters to teach exceeds 
    // the maximum number of unique leftover letters
    int maxLength = st.size() + 5;
    if (k > maxLength){
        k = maxLength;
    }

    for (int i : st){
        leftOverLetters.push_back(i);
    }

    combi(-1, baseLetters, 0);

    cout << ret << "\n";

    return 0;
}