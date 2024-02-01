#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *current, **temp;
	int null_seen = 0;
	size_t front = 0, rear = 0, queue_size = 1;

	queue = malloc(1 * sizeof(binary_tree_t *));

	if (tree == NULL)
	{
		return (0);
	}

	if (queue == NULL)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];

		if (null_seen && current != NULL)
		{
			free(queue);
			return (0);
		}

		if (current == NULL)
		{
			null_seen = 1;
		}
		else
		{
			if (current->left != NULL || current->right != NULL)
			{
				if (rear + 2 > queue_size)
				{
					temp = realloc(queue, (queue_size * 2) * sizeof(binary_tree_t *));

					if (temp == NULL)
					{
						free(queue);
						return (0);
					}
					queue = temp;
					queue_size *= 2;
				}
				queue[rear++] = current->left;
				queue[rear++] = current->right;
			}
		}
	}
	free(queue);
	return (1);
}
