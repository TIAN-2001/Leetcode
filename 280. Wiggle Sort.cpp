class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        
        for(int i = 1; i < sz; ++i){
            if(i % 2 == 0){
                if(nums[i-1] < nums[i]){
                    swap(nums, i-1, i);
                }
            } else {
                if(nums[i] < nums[i-1]){
                    swap(nums, i-1, i);
                }
            }
        }
        
        return;
    }
    
private:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        
        return;
    }
};