#include "binary_trees.h"

/**
 * recursive_depth - measures the depth of a node in a binary tree
 *
 * @tree: tree root
 * Return: depth of a node in a binary tree
 */
size_t recursive_depth(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (recursive_depth(tree->parent) + 1);
}

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

size_t depth_first = recursive_depth(first);
size_t depth_second = recursive_depth(second);

while (depth_first > depth_second)
{
first = first->parent;
depth_first--;
}

while (depth_first < depth_second)
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
