#include "binary_trees.h"

/**
 * print_t - Recursively stores each level in a string array for printing
 *
 * @tree: Pointer to the node to be printed
 * @offset: Offset for printing
 * @depth: Depth of the node
 * @s: Buffer array
 *
 * Return: Length of the printed tree after processing
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->value);
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height of
 *
 * Return: The height of the tree starting from @node
 */
static size_t _height(const binary_tree_t *tree)
{
    size_t height_left;
    size_t height_right;

    height_left = tree->left ? 1 + _height(tree->left) : 0;
    height_right = tree->right ? 1 + _height(tree->right) : 0;
    return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Displays a binary tree
 *
 * @tree: Pointer to the root node of the tree to be printed
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t tree_height, i, j;

    if (!tree)
        return;
    tree_height = _height(tree);
    s = malloc(sizeof(*s) * (tree_height + 1));
    if (!s)
        return;
    for (i = 0; i < tree_height + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255);
        if (!s[i])
            return;
        memset(s[i], 32, 255);
    }
    print_t(tree, 0, 0, s);
    for (i = 0; i < tree_height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (s[i][j] != ' ')
                break;
            s[i][j] = '\0';
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
