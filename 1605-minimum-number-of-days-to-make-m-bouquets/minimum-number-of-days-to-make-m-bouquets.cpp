class Solution {
public:
bool possible(vector<int> &bloomDay,int day,int m ,int k){
    int cnt=0;
    int num=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            num+=(cnt/k);
            cnt=0;
        }
    }
    num+=(cnt/k);
    return num>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m*1LL*k*1LL;
      if(bloomDay.size()<val) return -1;
      int mini=*min_element(bloomDay.begin(),bloomDay.end()); 
       int maxi=*max_element(bloomDay.begin(),bloomDay.end());  
       int s=mini;
       int e=maxi;
       int mid=s+(e-s)/2;
       while(s<=e){
        if(possible(bloomDay,mid,m,k)==true){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
       }
       return s;
    }

};