class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        
        while(l <= r){
            m = l + (r-l)/2;
            
            if(nums[m] == t) 
                return true;
            
            if(nums[m] == nums[l] && nums[m] == nums[r]) {++l; --r;} 
            else if(nums[m] >= nums[l]){
                if(t >= nums[l] && t < nums[m]) //左闭右闭
                    r = m - 1;
                else
                    l = m + 1;
            } else{
                if(t > nums[m] && t <= nums[r]) //左闭右闭
                    l = m + 1;
                else
                    r = m - 1;
            }
            
        }
        
        return false;
    }
};