//https://leetcode.com/problems/maximum-subarray/submissions/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs,gs; cs=gs=nums[0];
        for(int i=1;i<nums.size();i++){
            cs=max(nums[i],cs+nums[i]);
            if(cs>gs) gs=cs;
        }
        return gs;
    }
};
