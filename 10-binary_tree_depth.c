#include "binary_trees.h"

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
