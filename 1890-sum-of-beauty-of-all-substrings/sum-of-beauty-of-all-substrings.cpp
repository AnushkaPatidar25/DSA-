class Solution {
public:
    int beautySum(string s) {
        int ans=0;
    for (int i=0;i<s.length();i++){
     map<char,int>freq;
     for(int j=i;j<s.length();j++){
       freq[s[j]]++;
     
     int mini=INT_MAX;
     int maxi=INT_MIN;
     for(auto it:freq){
       maxi=max(maxi,it.second);
       mini=min(mini,it.second);
     } 
        ans+=maxi-mini;
     }
     }
     return ans; 
    }
};