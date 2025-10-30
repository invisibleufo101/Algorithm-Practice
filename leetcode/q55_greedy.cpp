class Solution {
public:
    // Greedy Solution
    bool canJump(vector<int>& nums) {
        int reach = 0; //  This is the maximum jump destination 
        for (int i=0; i<nums.size(); i++) {
            // If current index is ahead of maximum jump destination, it means that there is no possible way of continuing to the end of the array, therefore returning false.
            if (i > reach) return 0;

            // Keep updating the maximum reach destination 
            reach = max(reach, nums[i] + i);
        }

        return 1;
    }
};
