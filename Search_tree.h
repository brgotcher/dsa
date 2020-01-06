template <class T>
class Search_tree: public Binary_tree<T> {
public:
   Error_code insert(const T &new_data);
   Error_code remove(const T &old_data);
   Error_code tree_search(T &target) const;
protected:

   // Auxiliary functions called by the public functions
   Error_code search_and_insert(Binary_node<T>* &sub_root, const T &new_data);
   Error_code search_and_delete(Binary_node<T>* &sub_root, const T &target);
   Binary_node<T>* search_for_node(Binary_node<T>* sub_root, const T &target) const;
};


template <class T>
Error_code Search_tree<T>::insert(const T &new_data)
{
   return search_and_insert(this->root, new_data);
}


template <class T>
Error_code Search_tree<T>::search_and_insert(
           Binary_node<T> *&sub_root, const T &new_data)
{
   if (sub_root == nullptr) {
      sub_root = new Binary_node<T>(new_data);
      return success;
   }
   else if (new_data < sub_root->data)
      return search_and_insert(sub_root->left, new_data);
   else if (new_data > sub_root->data)
      return search_and_insert(sub_root->right, new_data);
   else return duplicate_error;

}


template <class T>
Error_code Search_tree<T>::remove(const T &target)
/*
Post: If a T with a key matching that of target belongs to the
      Search_tree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, target);
}


template <class T>
Error_code Search_tree<T>::search_and_delete(
           Binary_node<T>* &sub_root, const T &target)
/*
Pre:  sub_root is either NULL or points to a subtree of the Search_tree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
    if (sub_root == nullptr)
      return not_present;
    else if (sub_root->data == target) {
      if (sub_root->right == nullptr) { // No right child
         Binary_node<T> *to_delete = sub_root;  //  Remember node to delete at end.
         sub_root = sub_root->left;
         delete to_delete;
      } else if (sub_root->left == nullptr) { // No left child
         Binary_node<T> *to_delete = sub_root;  //  Remember node to delete at end.
         sub_root = sub_root->right;
         delete to_delete;
      } else { // subroot has two children
        Binary_node<T> *successor_node = sub_root->right; 
        while (successor_node->left != nullptr) { 
            successor_node = successor_node->left;
         }
         // replace the target with the immediate predecessor
         sub_root->data = successor_node->data;  
		 search_and_delete(sub_root->right, sub_root->data);
      }
   } else if (target < sub_root->data)
      return search_and_delete(sub_root->left, target);
   else
      return search_and_delete(sub_root->right, target);
   return success;


}


template <class T>
Error_code Search_tree<T>::tree_search(T &target) const
/*
Post: If there is an entry in the tree whose key matches that in target,
      the parameter target is replaced by the corresponding T from
      the tree and a code of success is returned.  Otherwise
      a code of not_present is returned.
Uses: function search_for_node
*/
{
   Error_code result = success;
   Binary_node<T> *found = search_for_node(this->root, target);
   if (found == NULL)
      result = not_present;
   else
      target = found->data;
   return result;
}


template <class T>
Binary_node<T> *Search_tree<T>::search_for_node(
            Binary_node<T>* sub_root, const T &target) const
{
   if (sub_root == NULL || sub_root->data == target) return sub_root;
   else if (sub_root->data < target)
      return search_for_node(sub_root->right, target);
   else return search_for_node(sub_root->left, target);
}


