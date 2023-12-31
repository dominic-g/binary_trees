#include "binary_trees.h"

/* Forward declaration */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int));

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Tree root.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height = 0;
size_t right_height = 0;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* binary_tree_levelorder - Prints data in level-order traversal.
*
* @tree: Tree root.
* @func: Pointer to a function.
* Return: No return.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
size_t height, level;

if (tree == NULL || func == NULL)
return;

height = binary_tree_height(tree);

for (level = 1; level <= height; level++)
{
print_level(tree, level, func);
}
}

/**
* print_level - Prints nodes at the same level.
*
* @tree: Tree root.
* @level: Level node.
* @func: Pointer to a function.
* Return: No return.
*/
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
if (tree == NULL)
return;

if (level == 1)
func(tree->n);
else if (level > 1)
{
print_level(tree->left, level - 1, func);
print_level(tree->right, level - 1, func);
}
}
