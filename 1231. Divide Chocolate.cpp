class Solution {
public:
    int maximizeSweetness(vector<int>& nums, int m) {
        int l = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        int r = sum;
        
        while(l < r){
            int mid = l + (r-l+1)/2;
            if(isValid(nums, m+1, mid)){
                l = mid;
            } else {
                r = mid - 1;
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
            if(tmpSum <= 0){
                m -= 1;
                // --i;
                tmpSum = maxSum;
            }
        }
        
        
        if(m <= 0){
            return true;
        } else {
            return false;
        }
        

    }    
};