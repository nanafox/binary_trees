#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: The pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	/* handle when the tree is empty */
	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL); /* malloc failed */

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	/* handle node adjustment for non-empty left nodes */
	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}

	/* insert node at the left of its parent */
	parent->left = node;

	return (node);
}
