#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0); /* not a leaf */

	/* it's a leaf node if it has no children */
	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0); /*  assume non-leaf node by default */
}
