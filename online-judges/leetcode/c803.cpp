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
  void sortChilds(TreeNode* P, TreeNode** L, TreeNode** R) {
    if (!P->left) {
      *L = P->left;
      *R = P->right;
      return;
    }
    else if (!P->right) {
      *L = P->right;
      *R = P->left;
    } else {
      if (P->left->val < P->right->val) {
        *L = P->left;
        *R = P->right;
      } else {
        *L = P->right;
        *R = P->left;
      }
    }
  }

  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;
    TreeNode *r1L, *r1R, *r2L, *r2R;
    sortChilds(root1, &r1L, &r1R);
    sortChilds(root2, &r2L, &r2R);
    return flipEquiv(r1L, r2L) && flipEquiv(r1R, r2R);
  }
};
