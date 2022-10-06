class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        int c=0;
        for(int i=0;i<g.size();i++)
        {
            if(g[i][i])
            {
                c++;
                dfs(g,i);
            }
        }
        return c;
    }
    void dfs(vector<vector<int>>& g,int x)
    {
        g[x][x]=0;
        //visited[x] = True
        for(int i=0;i<g[x].size();i++)
        {
            if(g[x][i] && g[i][i])//!visited[x]
                dfs(g,i);
        }
        return;
    }
};
