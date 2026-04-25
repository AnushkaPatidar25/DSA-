class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1) return nums[0];
      if(nums[0]!=nums[1])return nums[0];
      if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
      int s=1;
      int e=nums.size()-2;
      int mid=s+(e-s)/2;
      while(s<=e){
        if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
            return nums[mid];
        }
        if(mid%2==0 && nums[mid]==nums[mid+1]|| mid%2==1 && nums[mid]==nums[mid-1]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
      }
      return -1;
    }
};