#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front, back;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *));
	front = 0;
	back = 1;

	queue[0] = (binary_tree_t *)tree;

	while (front < back)
	{
		binary_tree_t *node = queue[front];

		func(node->n);

		if (node->left != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (back + 1));
			queue[back++] = node->left;
		}

		if (node->right != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (back + 1));
			queue[back++] = node->right;
		}

		front++;
	}

	free(queue);
}
