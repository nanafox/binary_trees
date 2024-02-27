#include "binary_trees.h"

/**
 * binary_tree_node_count - Counts the number of nodes in a binary tree.
 * @tree: A pointer to the binary tree to count.
 *
 * Return: The number of nodes in the binary tree.
 */
size_t binary_tree_node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_node_count(tree->left) +
			binary_tree_node_count(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree is not NULL, otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_of_left;
	size_t height_of_right;

	if (tree == NULL)
		return (0);

	/* check the height of the left subtrees */
	height_of_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	/* check the height of the right subtrees */
	height_of_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* return the maximum height amongst the two */
	return (height_of_left > height_of_right ? height_of_left
											 : height_of_right);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* ensure the number nodes in tree is the expected number for it's depth */
	return ((int)binary_tree_node_count(tree) ==
			(1 << (binary_tree_height(tree) + 1)) - 1);
}
