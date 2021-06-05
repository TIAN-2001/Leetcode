class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res;
        
        int maxtmp = -pow(2, 31)+1;
        int len = nums.size();
        vector<int> max(len, maxtmp);
        
        max[0] = nums[0];
            
        for(int i = 0; i < len-1; ++i)
        {
            if(max[i] < 0)
                max[i+1] = nums[i+1];
            else
                max[i+1] = nums[i+1] + max[i];
        }
        
        int tmp = maxtmp;
        for (int i = 0; i < len; ++i)
        {
            if(max[i] > tmp)
            {
                res = max[i];
                tmp = max[i];
            }
                
        }
        // res = max_element(max);
        return res;
        
    }
};