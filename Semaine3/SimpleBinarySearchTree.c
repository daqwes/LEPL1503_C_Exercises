
{   if (tree == NULL  ) {
    return 0; ;
} 
 else {
    return search(value,tree->root) ;
    }
}


int search(int value, struct node *root)
{
  if( root != 0 )
  {
      if(value==root->value)
      {
          return 1;
      }
      else if(value<root->value)
      {
          return search(value, root->left);
      }
      else
      {
          return search(value, root->right);
      }
  }
  else return 0;
}