#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *                         in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
size_t depth_first, depth_second;

if (first == NULL || second == NULL)
return (NULL);

if (first == second)
return ((binary_tree_t *)first);

depth_first = binary_tree_depth(first);
depth_second = binary_tree_depth(second);

while (depth_first > depth_second)
{
first = first->parent;
depth_first--;
}

while (depth_second > depth_first)
{
second = second->parent;
depth_second--;
}

while (first != second)
{
first = first->parent;
second = second->parent;
}

return ((binary_tree_t *)first);
}

/**
* binary_tree_depth - Calculates the depth of a node in a binary tree.
*
* @tree: Pointer to the node.
* Return: Depth of the node or 0 if tree is NULL.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree != NULL)
{
tree = tree->parent;
depth++;
}

return (depth);
}
