class Solution {
public:
    int maxProfit(vector<int>& prices) {
//Naive app.
//         //int max_profit=INT_MIN;
//         int max_profit=0;
//         for(int i=0;i<prices.size();i++){
//             for(int j=i+1;j<prices.size();j++){
//                 if(prices[j]-prices[i] >=0){
//                    max_profit=max(max_profit, prices[j]-prices[i]); 
//                 }
//             }
//         }
        
//         //return max_profit==INT_MIN?0:max_profit;
//         return max_profit;
// Valley & Peak based app.
            int max_profit=0;int minprice=INT_MAX;
            for(int i=0;i<prices.size();i++){
                if(prices[i]<minprice){
                    minprice=prices[i];
                }else if(prices[i]-minprice>max_profit){
                    max_profit=max(max_profit, prices[i]-minprice);
                }
            }
        
            return max_profit;
    }
};