#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 3 
#define max 8

typedef struct trie_node trie_node;

struct trie_node {
    trie_node* child[2];
    char key; 
    trie_node* father;
};

trie_node *alloc_node() {
    trie_node *node = malloc(sizeof(trie_node));
    if (!node) {
        printf("failed to alloc node\n");
        return NULL;
    }
    node->child[0] = NULL;
    node->child[1] = NULL;
    node->father = NULL;
    node->key = 0;
    return node;
}

trie_node *create_tree() {
    trie_node *root = alloc_node();
    if (!root) {
        printf("failed to create node\n");
        return NULL;
    }
    return root;
}

bool search(trie_node *T, trie_node *x, int w) {
    trie_node *u = T; 
    for (int i = 0; i < w; i++) {
        int c = (x->key >> ((w - 1) - i)) & 1; 
        if (u->child[c] == NULL) 
            return false; 
        u = u->child[c];
        if (u->key != x->key)
            continue; 
        else
            return true; 
    }
    return false; 
}

int count(trie_node *node){
    return 0;
}

bool insert(trie_node *root, char key){
    if(count(root) >= max) {
        printf("max size reached");
        return false;
    }
    return false;
}

int main() {
    trie_node *root = create_tree();

    trie_node *search_node = alloc_node();
    search_node->key = 'a'; 

    bool found = search(root, search_node, N);
    
    if (found) {
        printf("Key found in trie\n");
    } else {
        printf("Key not found in trie\n");
    }

    return 0;
}
