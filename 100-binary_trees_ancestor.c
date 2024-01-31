#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor
 * node of the two nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
size_t depth_first = binary_tree_depth(first);
size_t depth_second = binary_tree_depth(second);
const binary_tree_t *deeper = depth_first > depth_second ? first : second;
const binary_tree_t *shallower = depth_first > depth_second ? second : first;

if (!first || !second)
	return (NULL);

if (first == second)
return ((binary_tree_t *)first);

deeper = first->parent;
shallower = second->parent;
if (first == shallower || !deeper || (!deeper->parent && shallower))
return (binary_trees_ancestor(first, shallower));
else if (deeper == second || !shallower || (!shallower->parent && deeper))
return (binary_trees_ancestor(deeper, second));
return (binary_trees_ancestor(deeper, shallower));
}
