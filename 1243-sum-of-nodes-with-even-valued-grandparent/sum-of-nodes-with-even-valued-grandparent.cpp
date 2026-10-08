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

    void solve(TreeNode* curr,bool doit,bool c,int& ans){
        if(curr==NULL){
            return;
        }
        if(doit==true){
            ans+=curr->val;
        }

        if(c==true){
            doit=true;
        }
        else{
            doit=false;
        }

        if(curr->val%2==0){
            c=true;
        }
        else{
            c=false;
        }

        solve(curr->left,doit,c,ans);
        solve(curr->right,doit,c,ans);

    }

    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        solve(root,false,false,ans);
        return ans;
    }
};