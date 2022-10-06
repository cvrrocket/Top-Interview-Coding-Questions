//DFS SOLUTION || C++
class Solution {
public:
void dfs(vector<vector<int>> &adj, vector<vector<int>> &outNodes, vector<bool> &visited, int src, int parent, int &ans)
{

   visited[src] = true;
    if(parent != -1) {
        
        if(find(outNodes[src].begin(), outNodes[src].end(), parent) == outNodes[src].end())
            ans++;             // if we didn't find any outEdge from the current src node to it's child node, increase ans;
                                //no cycle with parent
    }
    
    for(auto v : adj[src]) {
        if(!visited[v])
        {
            dfs(adj, outNodes, visited, v, src, ans);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    
    vector<vector<int>> adj(n);
    vector<vector<int>> outNodes(n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(auto u : connections)
    {
        adj[u[0]].push_back(u[1]);
        adj[u[1]].push_back(u[0]);
        
        outNodes[u[0]].push_back(u[1]);
    }
    // for the 0th node, there is parent so i'm taking -1;
    dfs(adj, outNodes, visited, 0, -1, ans);
    return ans;
}
};
