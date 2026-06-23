class Solution {
public:
    string frequencySort(string s) {
      map<char,int>mp;
      for(char ch:s){
        mp[ch]++;
      } 
      vector<string>bucket(s.length()+1);
        for(auto a:mp){
            char ch=a.first;
            int freq=a.second;
            bucket[freq]+=string(freq,ch);
        }
        string ans="";
        for(int i=s.length();i>=0;i--){
          ans+=bucket[i];
        }
      return ans;
    }
};