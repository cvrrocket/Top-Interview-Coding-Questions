
class Solution {
public:

float distance(int x2,int y2)
{
    float value= sqrt(pow((x2),2)+pow((y2),2));
    
    return value;
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    
    priority_queue<pair<float,int>>maxh;
    //priority_queue<pair<int, pair<int,int>>>maxh;
    for(int i=0;i<points.size();i++)
    {
        maxh.push({distance(points[i][0],points[i][1]),i});
        //maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1),{points[i][0], points[i][1]}}); // no need for sqrt(distance_x^2+distance_y^2); as we just get comparatively smaller no. but if all are not taken sqrt then also fine as they are larger then all are larger; x>y; x^2>y^2 ; sqrt(x)>sqrt(y)        
        if(maxh.size()>K) maxh.pop();
        
    }
    
    vector<vector<int>>ans;
    while(maxh.size()!=0)//maxh.size()>0
    {   //pair<int, int> p=maxh.top().second;
        //cout<<p.first<<"-"<<p.second<<endl<<" ";
        ans.push_back(points[maxh.top().second]);
        maxh.pop();
    }
    
    return ans;
}
};

/*
//implemented in java with a slight change where i don't store key value pair in heap but only store value in heap by doing calculation in Heap Comparartor

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        
        Queue<int[]> q = new PriorityQueue<int[]>((p1, p2) -> Integer.compare((p2[0] * p2[0] + p2[1] * p2[1]),(p1[0] * p1[0] + p1[1] * p1[1])));
                                                  
        for(int i=0; i<points.length; i++){
            q.add(points[i]);
            if(q.size() > k){
                q.poll();
            }
        }
        int[][] arr = new int[k][2];
        while(k>0){
            arr[--k] = q.poll();
        }
        return arr;
    }
}
*/

/*

Another simple approach

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<float,int> arr; vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
                arr.insert({sqrt(pow(points[i][0],2)+pow(points[i][1],2)),i});
        }
        
        for(auto& it:arr){
            if(k!=0){
                ans.push_back(points[it.second]); k--;}
            else break;
        }
        return ans;
    }
*/