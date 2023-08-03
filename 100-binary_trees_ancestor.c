#include <stddef.h>
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

if (first == second)
return ((binary_tree_t *)first);

/* Create arrays to store paths from the root to the nodes */
binary_tree_t *path_first[100] = {NULL};
binary_tree_t *path_second[100] = {NULL};

/* Get paths from root to both nodes */
int len_first = 0, len_second = 0;
const binary_tree_t *temp = first;
while (temp != NULL)
{
path_first[len_first++] = (binary_tree_t *)temp;
temp = temp->parent;
}

temp = second;
while (temp != NULL)
{
path_second[len_second++] = (binary_tree_t *)temp;
temp = temp->parent;
}

/* Compare the paths to find the lowest common ancestor */
int i = len_first - 1;
int j = len_second - 1;
binary_tree_t *ancestor = NULL;
while (i >= 0 && j >= 0)
{
if (path_first[i] != path_second[j])
break;
ancestor = path_first[i];
i--;
j--;
}

return (ancestor);
}
