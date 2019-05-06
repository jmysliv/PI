#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {
    node * n = malloc(sizeof(node));
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    n->value=val;
    return n;
}

void delete_tree(node* root) {
    if(root==NULL) return;
    delete_tree(root->right);
    delete_tree(root->left);
    free(root);
}

void insert (node* root, node* to_insert) {
    if(to_insert->value<root->value){
        if(root->left==NULL){
            root->left=to_insert;
            to_insert->parent=root;
            return;
        }
        insert(root->left, to_insert);
    }
    else{
        if(root->right==NULL){
            root->right=to_insert;
            to_insert->parent=root;
            return;
        }
        insert(root->right, to_insert);
    }
}

void print_in_order(node* root) {
    if(root==NULL) return;
    print_in_order(root->left);
    printf("%d\n", root->value);
    print_in_order(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int val;

    if (n-- > 0) {
        scanf("%d", &val);
        root = create_node(val);
    }
    while (n-- > 0) {
        scanf("%d", &val);
        insert(root, create_node(val));
    }

    print_in_order(root);

    delete_tree(root);
}
