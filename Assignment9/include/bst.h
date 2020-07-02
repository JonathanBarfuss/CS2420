#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

/* PART 1: implemenation */
template <typename T>
struct Node {
  T info;
  Node *left;
  Node *right;
  Node(): left(nullptr), right(nullptr) {}
  Node(T info) : info(info), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
  BinarySearchTree() : root(nullptr) {}
  BinarySearchTree(const BinarySearchTree<T> &bt) { copy(root, bt.root); }
  BinarySearchTree<T> &operator=(BinarySearchTree<T> &bt){
    if (this != &bt) {
      destroy(root);
      copy(root, bt.root);
    }

    return *this;
  }

  bool empty() const { return root == nullptr; }

  /* Returns how many nodes in the longest path between the root and a child */
  int height() const { return height(root); }
  int height(const Node<T> *node) const {
    //height and max_height recursively use eachother to find the maximum height
    if(node){
      return 1 + max_height(node->left, node->right);
    } else {
      return 0;
    }
  }
  int max_height(const Node<T> *left, const Node<T> *right) const {
    
    int left_height = 0;
    int right_height = 0;
    if(left) {
      left_height = height(left);
    } 
    if(right) {
      right_height = height(right);
    } 
    if (left_height > right_height){
      return left_height;
    } else {
      return right_height;
    }
  }

  /* Returns how many links between nodes it takes to get to node from the root */
  int level(T e) const{
    int count = 0;
    auto current = root;
    //Traverse the tree until the info is found. Increase count for each traverse
    while(current){
      if(e == current->info){
        return count;
      } else if(e < current->info){
        count++;
        current = current->left;
      } else if (e > current->info){
        count++;
        current = current->right;
      }
    }
    throw std::runtime_error("The binary tree doesn't have this information");
  } 

  /* Returns the node with the minimum value */
  const Node<T>* minimum() const{ return minimum(root); }
  const Node<T>* minimum(Node<T>* node) const{
    auto current = node;
    while(current){
      current = current->left;
      if(current->left == nullptr){
        return current;
      }
    }
    return current;
  }

  /* Returns the node with the maximum value */
  const Node<T>* maximum() const { return maximum(root); }
  const Node<T>* maximum(Node<T>* node) const {
    auto current = node;
    while(current){
      current = current->right;
      if(current->right == nullptr){
        return current;
      }
    }
    return current;
  }

  /* Returns how many node in a tree */
  int size() const { return size(root); }
  int size(const Node<T>* node) const {
    if(node){
      return 1 + size(node->left) + size(node->right);
    }else {
      return 0;
    }
  }

  /* Returns how many leaf nodes (nodes without children) in the tree */
  int leavesCount() const { return leavesCount(root); }
  int leavesCount(const Node<T>* node) const{
    if(node){
      if(!node->left && !node->right){
        return 1;
      }else{
        return leavesCount(node->left) + leavesCount(node->right);
      }
    } else {
      return 0;
    }
  }

  /* Puts the nodes of the tree into an array in ascending or descending order */
  void toSortedArray(Node<T>* &array, bool reversed = false){
    array = new Node<T>[size()];
    auto current = root;
    toSortedArrayCount = 0;
    toSortedArray(array, current, reversed);
  }
  void toSortedArray(Node<T>* &array, Node<T>* node, bool reversed = false){
    //Similar to inorderTraversal. Navigate through the tree and add to the array instead of showFunc
    if(node){
      if(!reversed){
        toSortedArray(array, node->left, reversed);
        array[toSortedArrayCount++].info = node->info;
        toSortedArray(array, node->right, reversed);
      } else {
        toSortedArray(array, node->right, reversed);
        array[toSortedArrayCount++].info = node->info;
        toSortedArray(array, node->left, reversed);
      }
    }
  }
  
  /* Implements inorder traversal */
  void inorderTraversal(void (*showFunc)(const Node<T>*, int)) const { inorderTraversal(showFunc, root, 0); }
  void inorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const{
    if(node){
      inorderTraversal(showFunc, node->left, depth + 1);
      showFunc(node, depth);
      inorderTraversal(showFunc, node->right, depth + 1);
    }
  }

   /* Implements preorder traversal */
  void preorderTraversal(void (*showFunc)(const Node<T>*, int)) const { preorderTraversal(showFunc, root, 0); }
  void preorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if (node){
      showFunc(node, depth);
      preorderTraversal(showFunc, node->left, depth + 1);
      preorderTraversal(showFunc, node->right, depth + 1);
    }
  }

   /* Implements postorder traversal */
  void postorderTraversal(void (*showFunc)(const Node<T>*, int)) const { postorderTraversal(showFunc, root, 0); }
  void postorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if(node){
      postorderTraversal(showFunc, node->left, depth + 1);
      postorderTraversal(showFunc, node->right, depth + 1);
      showFunc(node, depth);
    }
  }

  /* Returns true if e was found */
  const Node<T>* search(T e) const{
    auto current = root;
    while (current){
      if(e == current->info){
        return current;
      } else if(e < current->info){
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return current;
  }  

  /* Returns true if e was successfully inserted */
  bool insert(T e){
    if(root){
      auto current = root;
      Node<T>* beforeCurrent = nullptr;
      while(current){
        beforeCurrent = current;
        if(current->info == e){
          return false; // Element is already in the list
        }else if(e < current->info){
          current = current->left;
        }else if(e > current->info){
          current = current->right;
        }
      }

      if(e < beforeCurrent->info){
        beforeCurrent->left = new Node<T>(e);
      }else{
        beforeCurrent->right = new Node<T>(e);
      }
    } else {
      root = new Node<T>(e);
    }
    return true;
  } 

  bool remove(T e){
    return remove(root, e);
  }
  
  /* Returns true if e was successfully deleted */
  bool remove(Node<T>* &node, T e){
    if(node){
      if(e < node->info){
        return remove(node->left, e);
      }else if(e > node->info){
        return remove(node->right, e);
      }else if(node->left && node->right) {// Two children
        node->info = maximum(node->left)->info;
        return remove(node->left, node->info);
      }else{
        Node<T> *temp = node;
        node  = (node->left ) ? node->left : node->right;
        delete temp;
        return true;
      }
    }

    return false;
  }

  ~BinarySearchTree(){ destroy(root); }
  
private:
  Node<T> *root;
  int toSortedArrayCount = 0;
  void destroy(Node<T> *node) {
    if (node){
      destroy(node->left);
      destroy(node->right);

      delete node;
      node = nullptr;
    }
  }
  void copy(Node<T> *&dest, const Node<T> *src) {
    if (src){
      dest = new Node<T>(src->info);
      copy(dest->left, src->left);
      copy(dest->right, src->right);
    } else {
      dest = nullptr;
    }
  }
};

/* PART 2: Tree-traversal functions */
template <typename T> 
void showTree(const Node<T>* node, int depth){
  for(int i = 0; i < depth; i++){
    std::cout << "   ";
  }
  std::cout << node->info << std::endl;
}
#endif
