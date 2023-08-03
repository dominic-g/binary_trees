#include "binary_trees.h"

/**
 * binary_tree_size - Calculates the size (number of nodes) of a binary tree
 * @tree: Pointer to the node to start calculating the size from
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t leftsize, rightsize;

if (tree == NULL)
return (0);

leftsize = binary_tree_size(tree->left);
rightsize = binary_tree_size(tree->right);

return (leftsize + rightsize + 1);
}
