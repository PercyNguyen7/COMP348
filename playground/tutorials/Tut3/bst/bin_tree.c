#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

void insert(int key, struct node **leaf) {
    if ((*leaf) == NULL) {
        // we've hit the lowest leaf level, insert node here
        (*leaf) = (struct node *) malloc(sizeof(struct node));
        (*leaf)->key_value = key;
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
    } else if (key < (*leaf)->key_value) {
        insert(key, &(*leaf)->left);
    } else if (key > (*leaf)->key_value) {
        insert(key, &(*leaf)->right);
    }
}

void dfs_inorder(const struct node *current_node) {
    if (current_node != NULL) {
        dfs_inorder(current_node->left);
        printf("%d ", current_node->key_value);
        dfs_inorder(current_node->right);
    }
}

struct node *search(int key, struct node *leaf) {
    if (leaf != NULL) {
        if (key == leaf->key_value) {
            return leaf;
        } else if (key < leaf->key_value) {
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right);
        }
    }
    else return NULL;
}
