#include "binary_trees.h"

/**
 * binary_tree_leaves - count leaves
 * @tree: pointer to root node
 * Return: count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t leaves = 0;

if (tree == NULL)
	return (0);

leaves += (tree->left || tree->right) ? 0 : 1;
leaves += binary_tree_leaves(tree->right);
leaves += binary_tree_leaves(tree->left);
return (leaves);
}
