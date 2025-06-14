#ifndef _BIN_TREE_H
#define _BIN_TREE_H

struct node {
    int key_value;
    struct node *left;
    struct node *right;
};


void insert(int , struct node**);
void dfs_inorder(const struct node*);
struct node *search(int, struct node*);

#endif // _BIN_TREE_H