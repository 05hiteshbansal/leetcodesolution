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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long int>pq;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        long long int sum=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr){
                if(!q.empty()){
                    q.push(nullptr);
                    pq.push(sum);
                    sum=0;
                }
            }
            else{
                sum+=node->val;
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }

            //cout<<sum<<endl;
        }

pq.push(sum);
if(k>pq.size())
{
    return -1;
}        
while(k>1){
            pq.pop();
            k--;
        }
        //cout<<pq.top()<<endl;
        return pq.top();
    }
};