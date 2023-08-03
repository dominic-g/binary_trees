#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree
 * @node: Pointer to the node to calculate the depth for
 *
 * Return: The depth of the node in the tree
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
size_t dp = 0;

if (node == NULL || node->parent == NULL)
return (0);

dp = binary_tree_depth(node->parent) + 1;

return (dp);
}
