package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func getMinimumDifference(root *TreeNode) int {
	nums := []int{}
	sort(root, &nums)
	min := -1
	for i := 0; i < len(nums)-1; i++ {
		localMin := nums[i+1] - nums[i]
		if min == -1 || localMin < min {
			min = localMin
		}
	}
	return min
}

func sort(root *TreeNode, nums *[]int) {
	if root != nil {
		if root.Left != nil {
			sort(root.Left, nums)
		}
		*nums = append(*nums, root.Val)
		if root.Right != nil {
			sort(root.Right, nums)
		}
	}
}
