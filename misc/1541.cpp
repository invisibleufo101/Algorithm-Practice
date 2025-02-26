#include <bits/stdc++.h>
using namespace std;
string s;

vector<int>split(string str, string delimiter){
    vector<int>ret;
    auto start = 0;
    auto end = str.find(delimiter);
    while(end != string::npos){

        if (str.substr(start, end - start).find('+') != string::npos){
            string tmp = "";
            int buffer = 0;
            for (char c : str.substr(start, end - start)){
                if (c == '+'){
                    buffer += stoi(tmp);
                    tmp = "";
                } else {
                    tmp += c;
                }
            }
            buffer += stoi(tmp);
            ret.push_back(buffer);
        } else {
            ret.push_back(stoi(str.substr(start, end - start)));
        }

        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }

    if (str.substr(start, end - start).find('+') != string::npos){
        string tmp = "";
        int buffer = 0;
        for (char c : str.substr(start, end - start)){
            if (c == '+'){
                buffer += stoi(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        buffer += stoi(tmp);
        ret.push_back(buffer);
    } else {
        ret.push_back(stoi(str.substr(start, end - start)));
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    vector<int>v = split(s, "-");

    int ret = v[0];
    for (int i=1; i<v.size(); i++) ret -= v[i];
    cout << ret << "\n";
    
    return 0;
}