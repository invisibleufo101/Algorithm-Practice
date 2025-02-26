#include <bits/stdc++.h>
using namespace std;
/**
 * This code is MUCH slower than 2529_b.cpp
 * I think the permutation function is PRETTY darn slow considering that
 * the time complexity if O(n^2)
*/
int k;
vector<char>nums = {'0','1','2','3','4','5','6','7','8','9'};
char ops[10];
string mx = "0";
string mn = "9999999999";

bool check(vector<char>v){
    for (int i=0; i<k; i++){
        char op = ops[i];

        if (op == '<'){
            if (v[i] > v[i+1]) return false;
        } else if (op == '>'){
            if (v[i] < v[i+1]) return false;
        }
    }
    return true;
}

void mx_cmp(string a, string b){
    if (a.length() > b.length()){
        mx = a;
    } else if (b.length() > a.length()){
        mx = b;
    } else {
        for (int i=0; i<a.length(); i++){
            if (a[i] > b[i]){
                mx = a;
                return;
            } else if (b[i] > a[i]){
                mx = b;
                return;
            }
        }
    }
}

void mn_cmp(string a, string b){
    if (a.length() > b.length()){
        mn = b;
    } else if (b.length() > a.length()){
        mn = a;
    } else {
        for (int i=0; i<a.length(); i++){
            if (a[i] > b[i]){
                mn = b;
                return;
            } else if (b[i] > a[i]){
                mn = a;
                return;
            }
        }
    }
}

void solve(vector<char>v){
    if (check(v)){
        string tmp = "";
        for (char c : v) tmp += c;

        mx_cmp(mx, tmp);
        mn_cmp(mn, tmp);
    }
}

void perm(int r, int depth){
    if (r == depth){
        vector<char>v;
        for (int i=0; i<r; i++) v.push_back(nums[i]);

        solve(v);
        return;
    }

    for (int i=depth; i<10; i++){
        swap(nums[i], nums[depth]);
        perm(r, depth + 1);
        swap(nums[i], nums[depth]);
    }

    return;
}


int main(){
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> ops[i];
    }

    perm(k+1, 0);
    
    cout << mx << "\n" << mn << "\n";

    return 0;
}