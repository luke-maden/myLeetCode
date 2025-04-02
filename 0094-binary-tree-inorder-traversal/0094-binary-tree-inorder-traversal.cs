/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();

        traverse(root,ref result);
        return result;
    }

    public void traverse(TreeNode root, ref IList<int> result) {
        if(root == null){
            return;
        }

        traverse(root.left, ref result);
        result.Add(root.val);
        traverse(root.right, ref result);
    }
}