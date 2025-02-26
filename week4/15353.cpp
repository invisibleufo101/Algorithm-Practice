#include <bits/stdc++.h>
using namespace std;
string a,b;

string solve(string a, string b){
    string ret = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int carryOver = 0;
    if (a.size() > b.size()){

        int diff = a.size() - b.size();

        for (int i=0; i<b.size(); i++){
            int ia = a[i] - '0';
            int ib = b[i] - '0';

            int sum = ia + ib + carryOver;

            if (sum >= 10){
                carryOver = 1;
                sum %= 10;
            } else {
                carryOver = 0;
            }

            ret += (sum + '0');
        }

        // Dealig with carryovers 
        if (carryOver == 1){
            for (int i=a.size() - diff; i<a.size(); i++){
                int ia = a[i] - '0';
                int sum = carryOver + ia;

                if (sum >= 10){
                    carryOver = 1;
                    sum %= 10;
                } else {
                    carryOver = 0;
                }

                ret += (sum + '0');
            }

            if (carryOver == 1){
                ret += '1';
            }
        } else if (carryOver == 0) {
            for (int i=a.size() - diff; i<a.size(); i++){
                ret += a[i];
            }
        }

        reverse(ret.begin(), ret.end());

    } else if (a.size() < b.size()){
        int diff = b.size() - a.size();

        for (int i=0; i<a.size(); i++){
            int ia = a[i] - '0';
            int ib = b[i] - '0';
            int sum = ia + ib + carryOver;
            
            if (sum >= 10){
                carryOver = 1;
                sum %= 10;
            } else {
                carryOver = 0;
            }

            ret += (sum + '0');
        }

        if (carryOver == 1){
            for (int i=b.size() - diff; i<b.size(); i++){
                int ib = b[i] - '0';
                int sum = carryOver + ib;

                if (sum >= 10){
                    carryOver = 1;
                    sum %= 10;
                } else {
                    carryOver = 0;
                }

                ret += (sum + '0');
            }

            if (carryOver == 1){
                ret += '1';
            }
        } else if (carryOver == 0){
            for (int i=b.size() - diff; i<b.size(); i++){
                ret += b[i];
            }
        }
        reverse(ret.begin(), ret.end());

    } else if (a.size() == b.size()){
        for (int i=0; i<a.size(); i++){
            int ia = a[i] - '0';
            int ib = b[i] - '0';
            int sum = ia + ib + carryOver;

            if (sum >= 10){
                carryOver = 1;
                sum %= 10;
            } else {
                carryOver = 0;
            }

            ret += (sum + '0');
        }

        if (carryOver == 1){
            ret += '1';
        }

        reverse(ret.begin(), ret.end());
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> a >> b;    

    cout <<  solve(a,b) << "\n";

    return 0;
}