class Solution{
    private:
    int first(vector<int> &nums,int target){
       int s=0;
       int e=nums.size()-1;
       int mid=s+(e-s)/2;
       int ans=-1;
       while(s<=e){
        if(nums[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
       } 
       return ans;
    }
    int second(vector<int> &nums,int target){
       int s=0;
       int e=nums.size()-1;
       int mid=s+(e-s)/2;
       int ans=-1;
       while(s<=e){
        if(nums[mid]==target){
            ans=mid;
            s=mid+1;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
       } 
       return ans;
    }
    
public:
    vector<int> searchRange(vector<int> &nums, int target) {
       vector<int>ans;
       int firstind= first(nums,target);
       int secondind =second(nums,target);
       ans.push_back(firstind);
       ans.push_back(secondind);
       return ans;
    }    
};