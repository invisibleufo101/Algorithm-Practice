#include<bits/stdc++.h>
using namespace std;
int n;
string pattern;
string f_name;
string p1, p2;
vector<string>v;

int main(){
    cin >> n;
    cin >> pattern;

    int x = pattern.find('*');
    p1 = pattern.substr(0, x);
    p2 = pattern.substr(x+1, pattern.length());

    regex re(p1 + "(.*)" + p2);

    for (int i=0; i<n; i++){
        cin >> f_name;

        if (regex_match(f_name, re)){
            v.push_back("DA");
        } else {
            v.push_back("NE");
        }
    }

    for (auto i : v){
        cout << i << "\n";
    }

    return 0;
}