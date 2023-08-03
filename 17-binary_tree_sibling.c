#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a given node in a binary tree
 * @node: Pointer to the node to find the sibling for
 *
 * Return: Pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
binary_tree_t *parent;

if (node == NULL)
return (NULL);

if (node->parent == NULL)
return (NULL);

parent = node->parent;

if (parent->left == node)
return (parent->right);
else
return (parent->left);
}
