#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a newnode as right child of a parent node
 * @parent: Pointer to the parent node
 * @value: Value of the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

if (parent == NULL)
return (NULL);

new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

if (!parent->right)
{
parent->right = new_node;
}
else
{
new_node->right = parent->right;
parent->right->parent = new_node;
parent->right = new_node;
}

return (new_node);
}
