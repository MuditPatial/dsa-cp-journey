/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(map<TreeNode* , TreeNode*>&par , TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }

        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> par;
        makeParent(par,root);

        map<TreeNode* , bool > vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int curLev=0;

        while(!q.empty()){
            int sz=q.empty();

            if(curLev == k) break;
            curLev++;

            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }

                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(par[node] && !vis[par[node]]){
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }

        }

        vector<int>ans;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};