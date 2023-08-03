#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binarytree from a given node
 * @tree: Pointer to the node to start calculating the height from
 *
 * Return: The height of the tree from the given node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t lh, rh;

if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (0);

lh = binary_tree_height(tree->left);
rh = binary_tree_height(tree->right);

if (lh > rh)
return (lh + 1);
return (rh + 1);
}
