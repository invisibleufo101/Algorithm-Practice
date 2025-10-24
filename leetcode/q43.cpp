#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<char> add(char a, char b, char carry) {
        int ia = a - '0'; int ib = b - '0';
        int ic = carry - '0';

        int sum = ia + ib + ic;

        int digit = sum % 10;
        int carryOver = sum / 10;

        return {char(digit + '0'), char(carryOver + '0')};
    }

    string addSubtotals(string a, string b) {
        char carry = '0';
        string addSum = "";
        for (int i=0; i<a.size() || i<b.size(); i++) {
            char ca = i < a.size() ? a[i] : '0';
            char cb = i < b.size() ? b[i] : '0';

            vector<char>addRes = add(ca, cb, carry);
            addSum += addRes[0];
            carry = addRes[1];
        }

        if (carry > '0') addSum += carry;

        return addSum;
    }

    vector<char> multi(char a, char b, char carry) {
        int ia = a - '0';
        int ib = b - '0';
        int ic = carry - '0';

        int sum = (ia * ib) + ic;

        int digit = sum % 10;
        int carryOver = sum / 10;

        return {char(digit + '0'), char(carryOver + '0')};
    }

    string solve(string firstNum, string secondNum) {

        vector<string> subtotals;
        for (int i=0; i<firstNum.size(); i++) {
            char carry = '0';
            string sum = "";
            sum += string(i, '0');
            for (int j=0; j<secondNum.size(); j++) {
                vector<char> res = multi(firstNum[i], secondNum[j], carry);
                sum += res[0];
                carry = res[1];
            }

            if (carry > '0') sum += carry;

            subtotals.push_back(sum);
        }

        string ret = subtotals.back();
        subtotals.pop_back();

        if (subtotals.size()) {
            for (string sub : subtotals) {
                ret = addSubtotals(ret, sub);
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res = solve(num1, num2);
        return res;
    }
};