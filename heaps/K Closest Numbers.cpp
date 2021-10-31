#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;//size pf Array
	int k;cin>>k;//K value
	int x;cin>>x;//  Find the Number Closet to
	int arr[n];
	priority_queue<pair<int,int>> maxheap;
	vector<int> v1;
	
	for(int i =0;i<n;i++)
	{
	     cin>>arr[i];
	}
	
	for(int i = 0;i<n;i++)
	{
	     maxheap.push({abs(arr[i] - x), arr[i]});
	     if(maxheap.size()>k)
	     {
	          maxheap.pop();
	     }
	     
	}
	
	while(maxheap.size()>0)
	{
	     v1.push_back(maxheap.top().second);//cout<<maxheap.top().second<<endl<<" ";
	     maxheap.pop();
	}

     sort(v1.begin(),v1.end());
	
	for(auto x : v1)
	    cout<<x<<" ";
	

    /*
    Instead of using pair<int,int> we could use our own compare function instead.


template<int k>
class Compare
{
public:
  bool operator () (int a, int b)
  {
      return abs(k-a) < abs(k-b);
  }
};


And then create just create the heap by
priority_queue<int, vector<int>, Compare<5> > pq;
    */