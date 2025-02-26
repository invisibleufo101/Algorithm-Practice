#include<bits/stdc++.h>
using namespace std;
int n;
string pattern, f_name;
string p_before, p_after;

bool starts_with(string s, string ptrn){
    if (s.substr(0, ptrn.size()) == ptrn){
        return true;
    }
    return false;
}

bool ends_with(string s, string ptrn){
    if (s.substr(s.size() - ptrn.size()) == ptrn){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> pattern;

    int pos = pattern.find('*');
    p_before = pattern.substr(0, pos);
    p_after = pattern.substr(pos+1);

    for (int i=0; i<n; i++){
        cin >> f_name;

        if (p_before.size() + p_after.size() > f_name.size()){
            cout << "NE\n";
            continue;

        } else {
            if (starts_with(f_name, p_before) && ends_with(f_name, p_after)) cout << "DA\n";
            else cout << "NE\n";
        }
    }

    return 0;
}