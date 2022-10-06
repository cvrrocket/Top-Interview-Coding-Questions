vector<int> path;
class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& paths,int node)
    {
      path.push_back(node);

      if(node==graph.size()-1)
      {
        paths.push_back(path);
        path.pop_back();
        return;
      }

      for(int i=0;i<graph[node].size();i++)
            dfs(graph,paths,graph[node][i]);
      
      path.pop_back();
    }
  //as it is DAG no need to check for cyclic/visited conditions
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
      vector<vector<int> > paths;
      // for(int i=0;i<graph[0].size();i++)
      // {
      //   path.push_back(0);
      //   dfs(graph,paths,graph[0][i]);
      //   path.pop_back();
      // }
        //path.push_back(0);
        dfs(graph,paths,0);
        //path.pop_back();
      return paths;
    }
};
