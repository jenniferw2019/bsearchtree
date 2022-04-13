#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct node
{
  int data;
  node* left;
  node* right;

};

node* search(node* treeNodeHead, node* current, int searchNumber);
void insert(node* &root, node* parent, node* current, int value);
void print(node* root);
#endif
