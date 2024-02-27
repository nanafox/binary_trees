#include "binary_trees.h"

/**
 * binary_tree_count - Counts the number of number in a binary tree.
 * @tree: A pointer to the binary tree to count.
 *
 * Return: The number of nodes in the binary tree.
 */
static size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_count(tree->left) +
			binary_tree_count(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth, node_count;

	if (tree == NULL)
		return (0);

	depth = binary_tree_depth(tree->left) + binary_tree_depth(tree->right);
	node_count = binary_tree_count(tree);

	/* ensure the number nodes in tree is the expected number for it's depth */
	return (node_count == (1 << (depth + 1)) - 1);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node if tree is not NULL, otherwise 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	/* compute the length of the path from a node back to the root */
	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;

	return (depth);
}
