class Solution {
private:
    // Sort the values by actually combining both values in a+b and b+a order and see which one should come first
    // I thought that by comparing each digit from i=0, I could sort correctly, but I was wrong :(
    // {2,29} -> 292 > 229
    // {2,21} -> 221 > 212
    static bool cmp(string a, string b) {        
        return (a+b) > (b+a);
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for (int num : nums) v.push_back(to_string(num));

        sort(v.begin(), v.end(), cmp);

        if (v[0] == "0") return "0";

        string ret = "";
        for (string s : v) ret += s;
    
        return ret;
    }
};
