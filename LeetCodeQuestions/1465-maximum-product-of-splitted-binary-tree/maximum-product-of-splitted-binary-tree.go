var tree_sum int64 = 0;

func trav(root *TreeNode) {
    if root != nil {
        trav(root.Left);
        trav(root.Right);
        tree_sum += int64(root.Val);
    }
}

var answer int64 = 0;

func dfs(root *TreeNode) int64 {
    if root == nil {
        return 0;
    }
    
    if root.Left == nil && root.Right == nil {
        return int64(root.Val);
    }

    left_sum := dfs(root.Left);
    right_sum := dfs(root.Right);

    if root.Left != nil {
        tmp := tree_sum - left_sum;
        ans := tmp * left_sum; 
        if ans > answer {
            answer = ans;
        }
    }

    if root.Right != nil {
        tmp := tree_sum - right_sum;
        ans := tmp * right_sum;
        if ans > answer {
            answer = ans;
        }
    }

    return left_sum + right_sum + int64(root.Val);
}

func maxProduct(root *TreeNode) int {
    tree_sum = 0;
    answer = 0;
    trav(root);
    dfs(root);
    mod := int64(1e9) + 7;

    return int(answer % mod);    
}