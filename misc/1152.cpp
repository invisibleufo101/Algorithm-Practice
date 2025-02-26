#include <bits/stdc++.h>
using namespace std;
string s;

vector<string>split(string& str, string delimiter){
    vector<string>ret;
    auto start = 0;
    auto end = str.find(delimiter);
    while (end != string::npos){
        ret.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    if (str.substr(start) != "\0") ret.push_back(str.substr(start));
    return ret;
}

int main(){
    getline(cin, s); string d = " ";

    vector<string>v = split(s, d);

    cout << v.size() << "\n";
    
    return 0;
}