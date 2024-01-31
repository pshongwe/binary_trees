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
 * binary_tree_size - tree size
 * @tree: pointer to root node
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t size_left = 0, size_right = 0;

if (tree == NULL)
	return (0);

size_left = binary_tree_size(tree->left);
size_right = binary_tree_size(tree->right);
return (1 + size_left + size_right);
}

/**
 * binary_tree_is_perfect - Checks if the binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t size;

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	return (size == (size_t)((1 << (height + 1)) - 1));
}
