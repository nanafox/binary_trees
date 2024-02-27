#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: The number of leaves in the binary tree if not NULL, otherwise 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* increment count for leaf nodes */
	if (binary_tree_is_leaf(tree))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

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
