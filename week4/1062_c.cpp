#include <bits/stdc++.h>
using namespace std;
int n,k;
string words[51];
vector<char>leftOvers;
set<char>uniqueLeftOver;
vector<set<char>>uniqueWords;
int ret = 0;

/**
 * Too slow. Works but it's too slow
*/

int countWords(set<char>v){
    int cnt = 0;
    for (set<char>uniqueWord : uniqueWords){
        set<char>temp = v;
        v.insert(uniqueWord.begin(), uniqueWord.end());
        
        if (v == temp) cnt++;

        v = temp;
    }

    return cnt;
}

void combi(int start, set<char>s){
    if (s.size() == k){
        ret = max(ret, countWords(s));
        return;
    }

    for (int i=start+1; i<leftOvers.size(); i++){
        s.insert(leftOvers[i]);
        combi(i, s);
        s.erase(leftOvers[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> words[i];
        set<char>temp;
        for (char c : words[i]){
            temp.insert(c);

            if (c != 'a' && c != 'c' && c != 'i' && c != 'n' && c != 't'){
                uniqueLeftOver.insert(c);
            }
        }

        uniqueWords.push_back(temp);
    }

    if (k < 5){
        cout << 0;
        return 0;
    }

    for (auto i : uniqueLeftOver){
        leftOvers.push_back(i);
    }

    int maxLength = uniqueLeftOver.size() + 5;
    if (k > maxLength){
        k = maxLength;
    }

    set<char>temp;
    temp.insert('a');
    temp.insert('c');
    temp.insert('i');
    temp.insert('n');
    temp.insert('t');
    
    combi(-1, temp);
    cout << ret << "\n";

    return 0;
}