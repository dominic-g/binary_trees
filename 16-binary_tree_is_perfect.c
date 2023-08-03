#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "15-binary_tree_is_full.c"

/**
 * confirm_leaves - Checks if all leaves are at the same level
 * @tree: Pointer to the node to start checking
 * @cur: Current level of the current leaf
 * @level: Level of past leaves
 *
 * Return: 1 if all leaves are at the same level, 0 otherwise
 */
int confirm_leaves(const binary_tree_t *tree, int cur, int *level)
{
if (tree == NULL)
return (0);

if (tree->right == NULL && tree->left == NULL)
{
if (*level == 0)
{
*level = cur;
return (1);
}
return (*level == cur);
}

return (confirm_leaves(tree->left, cur + 1, level) &&
confirm_leaves(tree->right, cur + 1, level));
}

/**
 * binary_tree_is_perfect - Checks if binary tree is perfect(full and balanced)
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int level = 0;

if (tree == NULL)
return (0);

if (binary_tree_is_full(tree) && (!binary_tree_balance(tree)))
{
return (confirm_leaves(tree, 0, &level));
}

return (0);
}
