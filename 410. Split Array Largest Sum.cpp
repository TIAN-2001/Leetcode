class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        int r = sum;
        
        while(l < r){
            int mid = l + (r-l)/2;
            if(isValid(nums, m, mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
private:
    bool isValid(vector<int>& nums, int m, int maxSum){
        int i = 0;
        int tmpSum = maxSum;
    
        for(int i = 0; i < nums.size(); ++i){
            tmpSum -= nums[i];
            if(tmpSum < 0){
                m -= 1;
                if(m < 0){
                    return false;
                }
                --i;
                tmpSum = maxSum;
            }
        }
        
        if(tmpSum >= 0){
            m -= 1;
            if(m < 0){
                return false;
            }            
        }
        
        return true;

    }
};