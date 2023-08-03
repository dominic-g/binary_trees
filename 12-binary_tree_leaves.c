#include "binary_trees.h"
#include "4-binary_tree_is_leaf.c"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree
 * @tree: Pointer to the node to start counting leaves from
 *
 * Return: The count of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t leftlf, rightlf;

if (tree == NULL)
return (0);

if (binary_tree_is_leaf(tree))
return (1);

leftlf = binary_tree_leaves(tree->left);
rightlf = binary_tree_leaves(tree->right);

return (leftlf + rightlf);
}
