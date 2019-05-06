#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) {
    node *n = malloc(sizeof(node));
    n->right=NULL;
    n->left=NULL;
    n->parent=NULL;
    n->name = malloc(MAX_NAME_SIZE*sizeof(char));
    strcpy(n->name, name);
    n->number = number;
    return n;
}

void delete_tree(node* root) {
    if(root==NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

node* insert (node* root, node* to_insert) {
   if(root==NULL){
       root=to_insert;
       return root;
   }
   if(to_insert->number < root->number){
       if(root->left==NULL){
           to_insert->parent=root;
           root->left=to_insert;
           while(root->parent!=NULL) root=root->parent;
           return root;
       }
       return insert(root->left, to_insert);
   }
   else{
       if(root->right==NULL){
           to_insert->parent=root;
           root->right=to_insert;
           while(root->parent!=NULL) root=root->parent;
           return root;
       }
       return insert(root->right, to_insert);
   }

}

node* find (node* root, int number) {
    if(root==NULL) return NULL;
    if(root->number==number) return root;
    if(root->number > number) return find(root->left, number);
    else return find(root->right, number);
}

node* find_minimum(node* root){
    if(root==NULL) return NULL;
    if(root->right==NULL) return NULL;
    root=root->right;
    while(root->left!=NULL) root=root->left;
    node *tmp = root->parent;
    if(tmp->left == root) tmp->left=root->right;
    else tmp->right = root->right;
    root->parent=NULL;
    root->right=NULL;
    return root;
}

node* delete(node* root, int number) {
    node* deletednode = find(root, number);
    if(deletednode==NULL) return root;

    node* n=find_minimum(deletednode);
    if(deletednode==root){
        if(n==NULL){
            root=root->left;
            root->parent=NULL;
        }
        else{
            n->parent = deletednode->parent;
            n->left = deletednode->left;
            n->right = deletednode->right;
            root=n;
        }
    }
    else{
        node* tmp=deletednode->parent;
        if(n==NULL){
            if(deletednode==tmp->right){
                tmp->right=deletednode->left;
                deletednode->left->parent = tmp;
            }
            else{
                tmp->left=deletednode->left;
                deletednode->left->parent=tmp;
            }
        }
        else{
            n->parent = tmp;
            n->left = deletednode->left;
            n->right = deletednode->right;
            if(deletednode==tmp->right) tmp->right = n;
            else tmp->left = n;
        }
    }
    free(deletednode);
    return root;

}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }

    while (r-- > 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }


    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}
