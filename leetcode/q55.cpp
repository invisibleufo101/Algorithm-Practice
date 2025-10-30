class Solution {
public:
    // DP solution
    bool canJump(vector<int>& nums) {

        vector<int>dp (nums.size(), 0);
        dp[nums.size()-1] = 1;
        int lastIdx = nums.size() - 1;

        for (int i=nums.size()-2; i>=0; i--) {
            if ((nums[i] + i) >= lastIdx) {
                dp[i] = 1;
                lastIdx = i;
            }
        }

        for (int i : dp) cout << i << " ";
        cout << "\n";

        return dp[0];
    }
};
