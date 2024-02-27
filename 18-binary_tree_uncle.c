#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the uncle node if found, NULL otherwise.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* return the uncle node (sibling of the node's parent) */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node if found, NULL otherwise.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* parent has only one child, so no other siblings exist */
	if (node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	/* return the sibling node */
	return ((node->parent->left == node) ? node->parent->right
										 : node->parent->left);
}
