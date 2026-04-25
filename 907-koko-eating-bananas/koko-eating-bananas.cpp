class Solution {
public:
long long int  calculate (vector<int>& piles,int h){
    long long int totalh=0;
    for(long long int bananas:piles){
        totalh+= (bananas+h-1)/h;
    }
    return totalh;
}
    int minEatingSpeed(vector<int>& piles, int h) {
      int maxval=*max_element(piles.begin(),piles.end());
      int s=1;
      int e=maxval;
      int mid=s+(e-s)/2;
      long long int ans=maxval;
      while(s<=e){
        long long int hour=calculate(piles,mid);
        if(hour<=h){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
      }  
      return ans;
    }
};