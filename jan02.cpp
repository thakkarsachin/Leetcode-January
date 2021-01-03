/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and 
the answer must be a reference to a node in the cloned tree.

Follow up: Solve the problem if repeated values on the tree are allowed.
*/

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode*> que;
        que.push_back(cloned);
        while(!que.empty()){
            if(que[0]->val==target->val)
                return que[0];
            
            if(que[0]->left!=NULL)
                que.push_back(que[0]->left);
            if(que[0]->right!=NULL)
                que.push_back(que[0]->right);
            que.erase(que.begin());
        }
        return cloned;
    }

};