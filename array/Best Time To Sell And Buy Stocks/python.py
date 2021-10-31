
'''
Idea 1: Array
The trick : track the minimum price and the maximum possible profit
Keep track of the buy price --> keep comparing the current price with prvious buy price and track of the minimum price while iterating through the list
However, if the current price is greater than the previous buy price
now check if you sell it now would you get a better profit than the previous one
Keep track of the maximum profit
'''

class Solution(object):
    def maxProfit(self, prices):
        
        buy_price = prices[0] # at the begining the minimum price is the first price
        profit = 0 # at the begining the minimum  profit is zero
        
        for i in range(1,len(prices)):
            #if the current price is less than the previous buy price ; update the buy_price
            if prices[i] < buy_price:
                buy_price = prices[i]
            else: # if not check if you sell with the current price would you get better profit than the previous one
                profit = max(profit, prices[i]-buy_price) # compare the previous profit with the current profit
                
        return profit
		
		#Runtime: 916 ms
		#Memory Usage: 23 MB
# * Idea 2 : Dynamic programming
# Track the minimum_price and the maximum profit together using a dp table
# Thus each dp table cell will hold two items --> dp = [[min_price, max_profit], [min_price, max_profit], ........[min_price, max_profit]]
class Solution(object):
    def maxProfit(self, prices):
        n = len(prices)
        dp = [0]*n # initializing the dp table
        dp[0] = [prices[0],0] # filling the the first dp table --> low_price = prices[0] max_profit=0
        min_price = max_profit = 0
        # Note that ---> indixing the dp table --> dp[i-1][0] stores minimum price and dp[i-1][1] stores maximum profit
        for i in range(1,n):
            min_price = min(dp[i-1][0], prices[i]) # min(previous_min_price, cur_min_price)
            max_profit = max(dp[i-1][1], prices[i]-dp[i-1][0]) # max(previoius_max_profit, current_profit)
            dp[i] =[min_price,max_profit]
                
        return dp[n-1][1]
		#Runtime: 1220 ms, 
		#Memory Usage: 32.4 MB,
