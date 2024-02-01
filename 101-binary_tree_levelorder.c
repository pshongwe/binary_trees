#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue, *current, **temp;
	size_t front = 0, rear = 0, queue_size = 1;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *));

	if (queue == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
		{
			if (rear == queue_size)
			{
				temp = realloc(queue, (queue_size * 2) * sizeof(binary_tree_t *));
				if (temp == NULL)
				{
					free(queue);
					return;
				}
				queue = temp;
				queue_size *= 2;
			}
			queue[rear++] = current->left;
		}

		if (current->right != NULL)
		{
			if (rear == queue_size)
			{
				temp = realloc(queue, (queue_size * 2) * sizeof(binary_tree_t *));
				if (temp == NULL)
				{
					free(queue);
					return;
				}
				queue = temp;
				queue_size *= 2;
			}
			queue[rear++] = current->right;
		}
	}
	free(queue);
}
