#include<bits/stdc++.h>
using namespace std;
int n;
string f_name;
string ptrn, start_ptrn, end_ptrn;
vector<string>v;

/** 
 * RUN TIME ERROR...
*/

bool starts_with(string str, string ptrn){
    string start_str = str.substr(0, ptrn.length());
    
    if (start_str == ptrn){
        return true;
    }
    return false;
}

bool ends_with(string str, string ptrn){
    string end_str = str.substr(str.length() - ptrn.length(), str.length());

    if (end_str == ptrn){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> ptrn;

    int x = ptrn.find('*');
    start_ptrn = ptrn.substr(0, x);
    end_ptrn = ptrn.substr(x+1, ptrn.length());

    for (int i=0; i<n; i++){
        cin >> f_name;
        if (starts_with(f_name, start_ptrn) && ends_with(f_name, end_ptrn)){
            v.push_back("DA");
        } else {
            v.push_back("NE");
        }
    }

    for (auto i: v) cout << i << "\n";

    return 0;
}