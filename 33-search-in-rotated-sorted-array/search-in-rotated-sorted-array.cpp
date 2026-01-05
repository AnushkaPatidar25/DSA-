class Solution {
public:
int getpivot(vector<int>&nums,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(nums[mid]>=nums[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int binarysearch(vector<int>& nums,int s,int e,int k){
   int mid=s+(e-s)/2;
    while(s<=e){
        if(nums[mid]==k){
           return mid;
        }
        if(k>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

    int search(vector<int>& nums,int target) {
        int pivot=getpivot(nums,nums.size());
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return binarysearch(nums,pivot,nums.size()-1,target);
        }
        else{
             return binarysearch(nums,0,pivot,target);
        }
    }
};