//
//  tree.h
//  tree
//
//  Created by William McCarthy on 134//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//
#include <stdbool.h>
#ifndef tree_h
#define tree_h

//-------------------------------------------------
typedef struct inode inode;
struct inode{
  int line_num;
  inode* next;
};

typedef struct tnode tnode;
struct tnode {
  const char* word;
  int count;
  tnode* left;
  tnode* right;
  inode* line_node;
};


typedef struct tree tree;
struct tree {
  tnode* root;
  size_t size;
};


//-------------------------------------------------
inode* inode_create(int line_num);
void inode_append(inode* head, int line_num);
void inode_delete(inode* p);

tnode* tnode_create(const char* word, int line_num);
tree* tree_create(void);

tree* tree_from_stream(char* (*fgets)(char*, int, FILE*), FILE* fin);
tree* tree_from_console(void);
tree* tree_from_file(int argc, const char* argv[]);

void tree_delete(tree* t);
void tree_clear(tree* t);

bool tree_empty(tree* t);
size_t tree_size(tree* t);

tnode* tree_add(tree* t, char* word, int line_num);

void tree_print(tree* t);    // INORDER-printing

void tree_print_preorder(tree* t);
void tree_print_postorder(tree* t);
void tree_print_levelorder(tree* t);
void tree_print_reverseorder(tree* t);
void tree_test(tree* t);

//======================================================


int mygetword(char *word, int lim);
void wordFreq(int argc, const char* argv[]);
int isNoise(char* word);
#endif /* tree_h */
