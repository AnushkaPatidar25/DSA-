class Solution {
public:
    string frequencySort(string s) {
     unordered_map<char,int> mp;
     for(char ch:s){
        mp[ch]++;
     }
     vector<string> buskect(s.length()+1);
     for(auto it: mp){
        char ch=it.first;
        int freq=it.second;
        buskect[freq]+=string(freq,ch);
     }
     string ans="";
     for(int i=s.length();i>=0;i--){
        ans+=buskect[i];
     }
     return ans;
    }
};