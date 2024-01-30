#include "binary_trees.h"

/**
 * binary_tree_depth - node depth
 * @tree: pointer to tree node
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{

return ((tree && tree->parent) ? binary_tree_depth(tree->parent) + 1 : 0);
}
