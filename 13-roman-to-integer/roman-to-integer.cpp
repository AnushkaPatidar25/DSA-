class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
     unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      for(int i=0;i<s.length();i++){
        int j=i+1;
            if(mp[s[i]]<mp[s[j]]){
                sum-=mp[s[i]];
            }
            else{
                sum+=mp[s[i]];
          
            }
        }
 
      return sum;
    }
};