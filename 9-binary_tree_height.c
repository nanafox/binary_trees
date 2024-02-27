#include "binary_trees.h"

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
