#include "binary_trees.h"

/**
 * bst_helper - Helper function for checking if a binary tree is valid BST
 * @tree: Pointer to the root node of the tree to check
 * @prev: Pointer to the previous node's value during in-order traversal
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!bst_helper(tree->left, prev))
		return (0);

	if (tree->n <= *prev)
		return (0);

	*prev = tree->n;
	return (bst_helper(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev =  INT_MIN;

	return (bst_helper(tree, &prev));
}
