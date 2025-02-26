#include <bits/stdc++.h>
using namespace std;
int k;
char ops[10];
char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
int visited[11];
vector<string>v;

bool check(char a, char op, char b){
    int ia = a - '0';
    int ib = b - '0';

    if (op == '<'){
        if (ia > ib) return false;
    } else if (op == '>'){
        if (ia < ib) return false;
    }

    return true;
}

void makePerm(int idx, string num){
    if (num.length() == k+1){
        v.push_back(num);
        return;
    }

    for (int i=0; i<10; i++){
        if (visited[i]) continue;
        if (i == 0 || check(num[idx - 1], ops[idx - 1], char(i + '0'))){
            visited[i] = 1;

            num += to_string(i);
            makePerm(idx+1, num);

            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k;
    for (int i=0; i<k; k++){
        cin >> ops[i];
    }

    makePerm(0, "");
    
    reverse(v.begin(), v.end());
    cout << v[v.size() - 1] << "\n" << v[0] << "\n";

    return 0;
}