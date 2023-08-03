#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor of two nodes in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor or NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
if (first == NULL || second == NULL)
return (NULL);

binary_tree_t *ancestor1 = (binary_tree_t *)first;
binary_tree_t *ancestor2 = (binary_tree_t *)second;

while (ancestor1 != ancestor2)
{

ancestor1 = ancestor1->parent;
ancestor2 = ancestor2->parent;

if (ancestor1 == NULL && ancestor2 == NULL)
return (NULL);


if (ancestor1 == NULL)
ancestor1 = (binary_tree_t *)second;
if (ancestor2 == NULL)
ancestor2 = (binary_tree_t *)first;
}

return (ancestor1);
}
