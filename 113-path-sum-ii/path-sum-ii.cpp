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
    void getPath(TreeNode* root, int targetSum, vector<int>& cur_path, vector<vector<int>>& all_paths){
        if(root->left == NULL && root->right == NULL) {
            int sum = root->val;
            for(int i=0;i<cur_path.size();i++){
                sum += cur_path[i];
            }
            if(sum == targetSum){
                cur_path.push_back(root->val);
                all_paths.push_back(cur_path);
                cur_path.pop_back();
                return;
            }
            else return;
        }
        else if(root->right == NULL){
            cur_path.push_back(root->val);
            getPath(root->left, targetSum, cur_path, all_paths);
            cur_path.pop_back();
        }
        else if(root->left == NULL){
            cur_path.push_back(root->val);
            getPath(root->right,targetSum, cur_path, all_paths);
            cur_path.pop_back();
        }
        else{
            cur_path.push_back(root->val);
            getPath(root->left, targetSum, cur_path, all_paths);
            getPath(root->right, targetSum, cur_path, all_paths);
            cur_path.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur_path;
        vector<vector<int>> all_paths;
        if(root == NULL) return all_paths;
        getPath(root, targetSum, cur_path, all_paths);
        return all_paths;
    }
};