class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int len = nums.size();
        
        int l = 0;
        int r = len-1;
        
        // find the left boundary
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                res[0] = m;
                r = m - 1;
            } 
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        l = 0;
        r = len - 1;
        // find the right boundary
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                res[1] = m;
                l = m + 1;
            } 
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }        
        
        
        return res;
    }
    
};