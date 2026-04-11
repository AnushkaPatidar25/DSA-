class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        for(int j=1;j<prices.size();j++){
            mini=min(mini,prices[j]);
                maxi=max(maxi,prices[j]-mini);
            } 
      return maxi;
    }
};