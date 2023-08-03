#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Tree root.
 * Return: Size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
* tree_is_complete - Checks if a binary tree is complete.
*
* @tree: Pointer to the tree root.
* @i: Node index.
* @cnodes: Number of nodes.
* Return: 1 if tree is complete, 0 otherwise.
*/
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
if (tree == NULL)
return (1);

if (i >= cnodes)
return (0);

return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
* binary_tree_is_complete - Checks if a binary tree is complete.
*
* @tree: Tree root.
* Return: 1 if tree is complete, 0 otherwise.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
size_t cnodes;

if (tree == NULL)
return (0);

cnodes = binary_tree_size(tree);

return (tree_is_complete(tree, 0, cnodes));
}
