class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            if(nums[i]==k)
            count++;
            for(int j=i+1;j<nums.size();j++){
                         sum+=nums[j];
                         if(nums[i]+sum==k){
                            count++;
                            continue;
                         }
                        
            
            }
        }
        return count;
    }
};