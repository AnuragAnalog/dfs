#ifndef __BSTREE__H_
#define __BSTREE__H_
#include <stdlib.h>

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct btree
{
    int info;
    struct btree *left;
    struct btree *right;
} Btree;

// API
int insert(Btree **root, int data, int h);
void intraver(struct btree *root);
void pretraver(struct btree *root);
void posttraver(struct btree *root);
void printlevel(struct btree *root, int level, int wid);
void display(struct btree *root, int height);
int delnodel(struct btree *root, int key);
int delnoder(struct btree *root, int key);
int delleaf(struct btree *root, int key);
int findmax(struct btree *root);
void search(struct btree *root, int key);
void cleartree(struct btree *root);

#endif