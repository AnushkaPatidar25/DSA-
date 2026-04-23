class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int s=0;
     int e=nums.size()-1;
     int mid=s+(e-s)/2;
     bool found=false;
     int ans=nums.size();
     while(s<=e){
        if(nums[mid]==target){
            found=true;
            return mid;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
     }   
     if(!found){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target){
                ans=i;
                break;
            }
        }
     }
     return ans;
    }
};