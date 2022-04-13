#include "node.h"
#include <iostream>

using namespace std;


void insert(node* &root, node* parent, node* current, int value)
{
  if (root == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      root = newNode;
      root->left = NULL;
      root->right = NULL;
    }
  else if (current == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      current = newNode;
      if (value < parent->data)
	{
	  parent->left = current;
	}
      if (value > parent->data)
	{
	  parent->right = current;
	}
    }
  else
    {
      parent = current;
      if (current->data > value)
	{
	  current = current->left;
	}
      else if (current->data < value)
	{
	  current = current->right;
	}
      insert(root, parent, current, value);
    }
}

void print(node* root)
{
  if (root != NULL)
    {
      print(root->left);
      cout << root->data << " ";
      print(root->right);
    }
}
/*
node* search(node* treeNodeHead, node* current, int searchNumber)
{
  
  if (current->data == searchNumber)
    {
      return current;
    }
  else if (current->data != searchNumber)
    {
      if (current->data > searchNumber)
	{
	  current = current->right;
	  search(treeNodeHead, current, searchNumber);
	}
      else
	{
	  if (current->data < searchNumber)
	    {
	      current = current->left;
	      search(treeNodeHead, current, searchNumber);
	    }
	}
      else if (current->left == NULL)
	{
	  cout << "number not found" << endl;
	}
      else if (current->right == NULL)
	{
	  cout << "number not found" << endl;
	}
    }
  
}
*/
