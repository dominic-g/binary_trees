#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the new node, or NULL if memory allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Allocate memory for the new node */
    new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
    {
        return (NULL);
    }

    /* Initialize node values */
    new_node->value = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}
