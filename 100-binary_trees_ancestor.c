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
while (depth_first != depth_second)
{
deeper = deeper->parent;
if (deeper == NULL)
	return (NULL);
if (depth_first > depth_second)
depth_first--;
else
depth_second--;
}

while (deeper != shallower)
{
deeper = deeper->parent;
shallower = shallower->parent;
}

return ((binary_tree_t *)(deeper && shallower ? deeper : NULL));
}
