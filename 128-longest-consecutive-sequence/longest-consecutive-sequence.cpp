 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
       unordered_set<int> st;
       int cnt=0;
       int longest=1;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       }
       for(auto it:st){
        if(st.find(it-1)==st.end()){
            cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x+=1;
                cnt+=1;
            }
            longest=max(longest,cnt);
        }
       }
      return longest;
    }
};  