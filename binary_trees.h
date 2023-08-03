#include <stdlib.h>

#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Structure for a binary tree node */
typedef struct binary_tree_s
{
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;


#endif
