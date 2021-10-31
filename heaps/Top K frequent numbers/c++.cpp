
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int,int>m1;
        vector<int>ans;
 priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >minHeap;
        for(auto it:nums)
        {
            m1[it]++;
        }
        for(auto it1:m1)    
         {                 
            minHeap.push(make_pair(it1.second,it1.first));  //{it1.second,it1.first}
            if(minHeap.size()>k)
            {
                minHeap.pop();
            }
        }
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};