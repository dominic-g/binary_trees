#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 * Return: Pointer to the new root after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;

	if (new_root->left)
		new_root->left->parent = tree;

	tree->right = new_root->left;
	new_root->left = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
