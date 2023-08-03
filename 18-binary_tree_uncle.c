#include "binary_trees.h"

/**
 * binary_tree_uncle - Returns the uncle of a given node in a binary tree
 * @node: Pointer to the node to get the uncle for
 *
 * Return: Pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
binary_tree_t *parent, *grandparent;

if (node == NULL || node->parent == NULL)
return (NULL);

parent = node->parent;
grandparent = parent->parent;

if (grandparent)
{
if (grandparent->left == parent)
return (grandparent->right);
return (grandparent->left);
}

return (NULL);
}
