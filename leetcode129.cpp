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
    int DFS(TreeNode* node, int sum){
        //cout << node->val << " sum: " << sum << endl;
        
        int t = sum*10 + node->val;  //每下ㄧ層就計算
        int l_sum =0 ,r_sum=0;
        if(node->left == NULL && node->right==NULL){//到底
            return t;  //1*10+2 =12
        }
        
        
        if(node->left){//sum=0  
            int val = node->val;//val = 1
            l_sum = DFS(node->left,sum*10+val);  //DFS(2,0*10+1)
        }
        
        if(node->right){
            int val = node->val;
            r_sum = DFS(node->right,sum*10+val);
        }
        
        return l_sum+r_sum;
        
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root->left && !root->right)
            return root->val;
        
        int answer = DFS(root,0);
        
       return answer;
    }
};
