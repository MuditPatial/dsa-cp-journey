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
    int minF(TreeNode* root ){
        if(!(root->left)) return root->val;

        return minF(root->left);
    }

    int maxF(TreeNode* root){
        if(!(root->right)) return root->val;

        return maxF(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root->val == key){
            if(!root->left && !(root->right)){
                return nullptr;
            }
            else if(root->left && !(root->right)){
                int v = maxF(root->left);
                root->val=v;
                deleteNode(root->left,v);
            }
            else if(!(root->left) && root->right){
                int v = minF(root->right);
                root->val=v;
                deleteNode(root->right,v);

            }
            else{
                int v = minF(root->right);
                root->val=v;
                deleteNode(root->right,v);
            }
        }
        else if((root->val) > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }

        return root;
    }
};