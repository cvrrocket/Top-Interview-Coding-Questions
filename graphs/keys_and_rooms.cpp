class Solution {
public:
    int cntt=0;//no. of rooms opened with keys in starting from 0 rooms(1,2) then 1,2 can be opened so cnt=2 not cnt 1 for each 1,2(its not like level dist)
    bool check=false; 
    void dfs(vector<vector<int>>& rooms, int src, vector<int>& visited, int cnt){
        int size=rooms.size()-1;
        
        cout<<src<<endl;
        if(cntt>=size){//cnt==size;
            check=true;
        }
        for(auto i:rooms[src]){
            if(visited[i]==0){
              visited[i]=1;
                cntt++;
              dfs(rooms, i, visited, cnt+1);   
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        // bool check=false; 
        // check = dfs(rooms, 0, visited, 0);
        visited[0]=1;
        dfs(rooms, 0, visited, 0);//1-->cnt
        return check;
    }
};
