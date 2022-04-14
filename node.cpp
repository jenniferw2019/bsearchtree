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

void visualize(node* root, int level)
{
  if (root != NULL)
    {
      visualize(root->right, level + 1);
      for (int i = 0; i < level; i++)
	{
	  cout << '\t';
	}
      cout << root->data << endl;
      visualize(root->left, level + 1);
    }
}

node* search(node* treeNodeHead, node* parent, node* current, int searchNumber)
{
  
  if (current->data == searchNumber)
    {
      return current;
    }
  else if (current == NULL)
    {
      if (parent->data == searchNumber)
	{
	  return parent;
	}
      else
	{
	  return NULL;
	}
    }
  else
    {
      if (current->data == searchNumber)
	{
	  return current;
	}
      else
	{
	  parent = current;
	  if (parent->data < searchNumber)
	    {
	      current = current->right;
	    }
	  else
	    {
	      current = current->left;
	    }
	  return search(treeNodeHead, parent, current, searchNumber);
	}
    }
  //return false;
}

