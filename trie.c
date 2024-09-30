#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define w 3

typedef struct trie_node trie_node;

struct trie_node {
    char key; 
    trie_node *father;
    trie_node *child[2];
};

trie_node *alloc_node() {
    trie_node *node = malloc(sizeof(trie_node));
    if (!node) {
        printf("Failed to allocate node\n");
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
        printf("Failed to create root node\n");
        return NULL;
    }
    return root;
}

trie_node *new_node(char key) {
    trie_node *T = alloc_node();
    if (T != NULL)
        T->key = key;
    return T;
}

bool search(trie_node *T, trie_node *x) {
    if (!T) return false;

    trie_node *u = T;
    for (int i = 0; i < w - 1; i++) {
        int c = ((x->key - '0') >> ((w - 1) - i)) & 1;
        if (u->child[c] == NULL)
            return false;
        if (u->key != x->key)
            u = u->child[c];
        else
            return true;
    }
    return false;
}

int count(trie_node *node) {
    return 0; // Not implemented, so always returns 0 for now
}

bool insert(trie_node *T, trie_node *x) {
    if (!T || !x) {
        puts("invalid inputs");
        return false;
    }

    if (count(T) >= pow(2, w)) { // not working yet
        printf("Max size reached\n"); 
        return false;
    }

    trie_node *u = T;
    int c;
    for (int i = 0; i < w - 1; i++) {
        c = ((x->key - '0') >> ((w - 1) - i)) & 1;
        if (u->child[c] == NULL)
            break;
        if (u->key == x->key) {
            printf("Already inserted key\n");
            return false;
        }
        u = u->child[c];
    }

    x->father = u;
    u->child[c] = x;
    return true;
}

int main() {
    trie_node *root = create_tree();
    if (!root) {
        printf("Failed to create root\n");
        return 1;
    }

    trie_node *x = new_node('a');
    bool inserted = insert(root, x);

    if(!inserted) {
        printf("not inserted %c\n", x->key);
        return false;
    }

    printf("inserted %c\n", x->key);

    trie_node *search_node = alloc_node();
    if (!search_node) {
        printf("Failed to create search node\n");
        return 1;
    }

    search_node->key = 'a';

    bool found = search(root, search_node);
    
    if (found) {
        printf("Key found in trie\n");
    } else {
        printf("Key not found in trie\n");
    }

    free(search_node);
    free(root);

    return 0;
}
