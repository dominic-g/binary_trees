#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the node to start counting nodes from
 *
 * Return: The count of nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t leftnd, rightnd, nds = 0;

if (tree == NULL)
return (0);

if (tree->left || tree->right)
nds++;

leftnd = binary_tree_nodes(tree->left);
rightnd = binary_tree_nodes(tree->right);

nds += (leftnd + rightnd);
return (nds);
}
