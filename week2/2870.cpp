#include <bits/stdc++.h>
using namespace std;
int n;
string str;
vector<string>ret;

vector<string> split(string str){
    regex re("[a-z]+");
    sregex_token_iterator it(str.begin(), str.end(), re, -1), end;
    return vector<string>(it, end);
}

string ltrim(string str){
    int pos = str.find_first_not_of('0');
    return str.substr(pos);
}

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str;

        vector<string>v = split(str);

        for (string i : v){
            if (i == "") continue;
            if (atoi(i.c_str()) == 0) ret.push_back("0");
            else ret.push_back(ltrim(i));
        }
    }

    sort(ret.begin(), ret.end(), cmp);

    for (auto i : ret){
        cout << i << "\n";
    }

    return 0;
}