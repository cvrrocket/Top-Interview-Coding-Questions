
class Solution {
public:
//passes 29/32 cases on leetcode and exceeds time on the remaning cases, any improvements?
    string frequencySort(string s) 
    {
        unordered_map<char,int> m;
        int i,n=s.size();
        string res="";
        for(i=0;i<n;i++)
            m[s[i]]++;
        priority_queue<pair<int,char>> pq;//maxHeap
        for(auto it=m.begin();it!=m.end();it++)
            pq.push({it->second,(char)it->first});//here now need to check pq.size()>l and all
        while(pq.size()>0)
        {
            int c=pq.top().first;//freq;
            //int ele=pq.top().second();//ele;
            /*
                for(int i=0;i<freq;i++){
                    cout<<ele<<endl<<" ";
                }
                pq.pop();
            */
            while(c>0)
            {
                res=res+pq.top().second;
                c--;
            }
            pq.pop();
        }
        return res;
    }
};

//code implementation with compare function:
bool compare(pair<int,int> p1,pair<int,int> p2){
        if(p1.second == p2.second)
                return p1.first>p2.first;
        return p1.second<p2.second;
    }


vector<int> frequencySort(vector<int>& nums) {
        vector<int> vec;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){      //unordermap for frequency counting
            um[nums[i]]++;
        }
        
        vector<pair<int,int> > freq_arr(um.begin(),um.end());
        sort(freq_arr.begin(),freq_arr.end(),compare);
        
        for(int i=0;i<freq_arr.size();i++){
            for(int j=0;j<freq_arr[i].second;j++){
                vec.push_back(freq_arr[i].first);
            }
        }
        
        
        return vec;
        
    }

    /*
    this logic won't work if the frequency of two elements are same and we have to print the smaller one first
it's better to use map only
    */

//Can we not create a ordered_map<element, frequency>  and then traverse the map elements, print the a[i] no. of times, the frequency is in the map element ?
//something like -

int index = 0;
for (auto it = omap.begin(); it != omap.end(); ++it) {
      int freq = it->second;
      for (int i = index; i < index + freq; ++i) {
            a[i] = it->first;
      }
}


    //we can also use store the  pair of frequency and element then pop one by one

#include<bits/stdc++.h>
using namespace std;
void topK(int arr[],int n,int k)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	priority_queue<pair<int,int>>min_heap;
	for(int i=0;i<n;i++)
	{
		min_heap.push({mp[arr[i]],arr[i]});
	}
	while(min_heap.size())
	{
		cout<<min_heap.top().second<<" ";
		min_heap.pop();
	}
}
int main()
{
	int arr[]={1,1,1,3,2,2,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=2;
	topK(arr,n,k);
	return 0;
}





    vector<int> frequency_sort(vector<int> v) {
	unordered_map<int, int> mp;
	for (int i = 0; i < v.size(); i++) {
		mp[v[i]] ++;
	}
	priority_queue <pair<int, int>> pq;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		pq.push({i->second, i->first});
	}
	vector<int> result;
	while (!pq.empty()) {
		int times = pq.top().first;
		for (int j = 0; j < times; j++) {
			result.push_back(pq.top().second);
		}
		pq.pop();
	}
	return result;
}






JAVA CODE :
public class Main {
    public static void main(String[] args) {
        int[] arr = { 1,1,1,3,2,4,2 };
        PriorityQueue<Pair> q = new PriorityQueue<Pair>(new Pair());
        HashMap<Integer,Integer> map=new HashMap<>();

        for (int i = 0; i < arr.length; i++){
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
        }


        for(int kk:map.keySet()){
            q.add(new Pair(kk,map.get(kk)));
        }

        ArrayList<Integer> ans=new ArrayList<>();

        while(!q.isEmpty()){
            Pair obj=q.poll();
            for(int i=0;i<obj.value;i++){
                ans.add(obj.key);
            }
        }

        System.out.println(ans);

    }

}

class Pair implements Comparator<Pair> {
    int key;
    int value;

    Pair() {

    }

    Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public int compare(Pair p1, Pair p2) {
        if (p1.value == p2.value)
            return 0;     // no change
        if (p1.value < p2.value)
            return +1;   // change  the order
        else
            return -1;  // 
no change
    }
}
