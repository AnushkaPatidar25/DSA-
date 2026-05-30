class Solution {
public:
int count=0;
void merge(vector<int>& nums,int s,int e){
    int mid=s+(e-s)/2;
    int len1= mid -s +1;
    int len2 = e-mid;
    int * first=new int[len1];
    int * second=new int [len2];
    int mainindex=s;
    for(int i=0;i<len1;i++){
        first[i]=nums[mainindex++];
    }
    mainindex=mid+1;
     for(int i=0;i<len2;i++){
        second[i]=nums[mainindex++];
     }
     int index1=0;
     int index2=0;
     mainindex=s;
     while(index1<len1 && index2<len2){
        if(first[index1]<=second[index2]){
          nums[mainindex++]=first[index1++];
        }
        else{
          
            nums[mainindex++]=second[index2++];
        }
     }
     while(index1<len1){
        nums[mainindex++]=first[index1++];
     }
     while(index2<len2){
        nums[mainindex++]=second[index2++];
     }
}
void total (vector<int> & nums,int s,int mid,int e){
    int j=mid+1;
    for(int i=s;i<=mid;i++){
        while(j<=e && 1LL*nums[i]>2LL*nums[j]) j++;
        count+=j-(mid+1);
    }
}
void mergeSort(vector<int>& nums,int s,int e){
    if(s>=e)return;
    int mid=s+(e-s)/2;
      mergeSort(nums,s,mid);
      mergeSort(nums,mid+1,e);
      total(nums,s,mid,e);
      merge(nums,s,e);
}
    int reversePairs(vector<int>& nums) {
       mergeSort(nums,0,nums.size()-1);
       return count;
    }
};