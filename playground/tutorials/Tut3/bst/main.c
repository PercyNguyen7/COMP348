#include <stdio.h>
#include "bin_tree.h"

int main(int argc, char const *argv[])
{
    struct node *tree;
    tree = NULL;
    
    insert(2, &tree);
    insert(1, &tree);
    insert(4, &tree);
    insert(3, &tree);
    insert(5, &tree);
    insert(7, &tree);

    printf("DFS Inorder traversal: ");
    dfs_inorder(tree);
    printf("\n");

    // Why is struct node k = *search(10, tree); a bad idea? 
    // Answer: We are deferencing a NULL here, which will give a segmentation fault
    struct node *k = search(5, tree);
    printf("Pointer to node: %p\n", k);
    if (k != NULL) {
        printf("Value of node: %d\n", k->key_value);
    }

    return 0;
}