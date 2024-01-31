#include "binary_trees.h"

/**
 * binary_tree_height - find height of tree
 * @tree: tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t height_left = 0, height_right = 0;

if (tree == NULL)
return (0);


height_left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
height_right = tree->right ? binary_tree_height(tree->right) + 1 : 0;
return ((height_left > height_right) ? height_left : height_right);
}


/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root of the node
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL)
		return (0);

	l_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	r_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((int)l_height - r_height);
}
