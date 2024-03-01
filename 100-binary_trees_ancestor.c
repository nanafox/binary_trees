#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor (LCA) of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: The lowest common ancestor (LCA) node of the two given nodes. NULL
 * is returned when an ancestor is not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *temp;
	binary_tree_t *first_ancestor, *second_ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = second;

	while (temp != NULL)
	{
		if (temp == first)
			return ((binary_tree_t *)first);
		temp = temp->parent;
	}

	temp = first;
	while (temp != NULL)
	{
		if (temp == second)
			return ((binary_tree_t *)second);
		temp = temp->parent;
	}

	first_ancestor = first->parent;
	second_ancestor = second->parent;

	while (first_ancestor != NULL)
	{
		while (second_ancestor != NULL)
		{
			if (first_ancestor == second_ancestor)
				return (first_ancestor);
			second_ancestor = second_ancestor->parent;
		}
		first_ancestor = first_ancestor->parent;
		second_ancestor = second->parent;
	}
	return (NULL);
}
