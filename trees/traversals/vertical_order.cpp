//Recursive approach
//
//void verticalTraversal(TreeNode *A, int level, map<int, vector<int>> &m){
//    if(!A) return;
//    m[level].push_back(A->val);
//    if(A->left) verticalTraversal(A->left, level-1, m);
//    if(A->right) verticalTraversal(A->right, level+1, m);
//}
//vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
//    vector<vector<int>> res;
//    if(!A) return res;
//    map<int, vector<int>> m;
//    verticalTraversal(A, 0, m);
//    for(auto x:m){
//        res.push_back(x.second);
//    }
//    return res;
//}
//

//The above solution doesn't print the currect order of nodes at the same level, see- https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> res;
    if(!A) return res;
    map<int, vector<int>> m;
    queue<pair<TreeNode *,int> > qu;
    qu.push(make_pair(A,0));
    while(!qu.empty()){
        pair<TreeNode *,int> fr=qu.front();
        qu.pop();
        m[fr.second].push_back(fr.first->val);
        if(fr.first->left) qu.push(make_pair(fr.first->left,fr.second-1));
        if(fr.first->right) qu.push(make_pair(fr.first->right,fr.second+1));
    }
    for(auto x:m){
        res.push_back(x.second);
    }
    return res;
}

//Time Complexity of above implementation is O(n Log n). Note that above implementation uses map which is implemented using self-balancing BST.
//
//We can reduce time complexity to O(n) using unordered_map. To print nodes in desired order, we can have 2 variables denoting min and max horizontal distance. We can simply iterate from min to max horizontal distance and get corresponding values from Map. So it is O(n)
