#include "binary_trees.h"

/**
 * height - Returns the height of a binary tree
 * @tree: Pointer to the node to start calculating the height from
 *
 * Return: The height of the binary tree
 */
size_t height(const binary_tree_t *tree)
{
size_t lefthgt, righthgt;

if (tree == NULL)
return (0);

lefthgt = height(tree->left);
righthgt = height(tree->right);

if (lefthgt > righthgt)
return (lefthgt + 1);
return (righthgt + 1);
}

/**
 * binary_tree_balance - Calc the balance factor of a binary tree at root node
 * @tree: Pointer to the root node of the tree
 *
 * Return: The balance factor of the tree at the root node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int leftsd, rightsd, balfactor;

if (tree == NULL)
return (0);

leftsd = height(tree->left);
rightsd = height(tree->right);
balfactor = leftsd - rightsd;

return (balfactor);
}
