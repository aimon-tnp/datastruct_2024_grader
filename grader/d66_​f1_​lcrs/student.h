// You may include library here

int depth(node *n)
{
  // Write Code Here
  if (n == NULL){
    return -1;
  }

  int current_depth = 1 + depth(n->left_child);
  int sibling_depth = depth(n->right_sibling);

  return std::max(current_depth, sibling_depth);
}