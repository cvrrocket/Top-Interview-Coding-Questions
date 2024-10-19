/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> umap;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return findMostFrequent(umap);
    }

private:    
    void dfs(TreeNode* root){
        if(root!=NULL){
            dfs(root->left);
            umap[root->val]+=1;
            dfs(root->right);
        }
        return;
    }

    vector<int> findMostFrequent(unordered_map<int, int>& freqMap) {
        int maxFreq = 0;//(max frequency)
        vector<int> result;

        // now iterating over word, freq pair 
        // and printing them in <, > format
        // unordered_map<string, int>:: iterator p;
        // for (p = freqMap.begin(); 
        //     p != freqMap.end(); p++)
        //     cout << "(" << p->first << ", " <<
        //                 p->second << ")\n";

        // Find the maximum frequency(freq)
        for (const auto& pair : freqMap) {//for (auto x : umap){..cout<<x.first<<x.second<<endl;..}
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                result.clear(); // Clear previous results as we found a new max
                result.push_back(pair.first);
            } else if (pair.second == maxFreq) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};

