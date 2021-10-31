class Solution {
    
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int max, min;
        max = min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] == Math.min(min, prices[i])) max = min = prices[i];
            else maxProfit = Math.max(maxProfit, prices[i] - min);
        }
        return maxProfit;
    }
    
}
