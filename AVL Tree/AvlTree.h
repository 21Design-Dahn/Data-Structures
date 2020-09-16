#include <algorithm>

template<typename T>
struct Node{
    Node(T value)
      : value(value)
    {
    }

    Node(const Node<T>& other)
      : value(other.value), balanceFactor(other.balanceFactor),
        height(other.height), left(other.left), right(other.right)
    {
    }

    Node<T>& operator=(const Node<T>& other){
      if(this == &other){ return *this; }

      this->value = other.name;
      this->balanceFactor = other.balanceFactor;
      this->height = other.height;

      this->left = other.left;
      this->right = other.right;

      return *this;
    }

    ~Node(){
      delete left;
      delete right;
    }

    T value;
    int balanceFactor = 0;
    unsigned int height = 0;

    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    
};

template<typename T>
class AVLTree{
  public:

    bool Insert(T value){
      if(!contains(root, value)){
        root = insert(root, value);
        nodeCount++;
        return true;
      }

      return false;
    }

    bool Remove(T value){
      if(contains(root, value)){
        root = remove(root, value);
        nodeCount--;
        return true;
      }

      return false;
    }

    bool Contains(T value) const { return contains(root, value); }
    unsigned int GetNodeCount() const { return GetNodeCount; }
    unsigned int GetHeight() const {
      if(root == nullptr) return 0;
      return root->GetHeight();
    }
    bool GetSize() const { return nodeCount; }
  private:
    Node<T>* rightRotation(Node<T>* n){

    }
    bool contains(Node<T>* n, T value){
      if(n == nullptr) return false;

      int cmp = n->value > value ? -1 : 1;
      if(cmp < 0) { return contains(n->left, value); }
      if(cmp > 0) { return contains(n->left, value); }

      return true;
    }

    Node<T>* insert(Node<T>* n, T value){
      if(n == nullptr) {
        Node<T>* newNode = new Node<T>(value);
        return newNode;
      }

      int cmp = n->value > value ? -1 : 1;
      if(cmp < 0){
        n->left = insert(n->left, value);
      } else {
        n->right = insert(n->right, value);
      }

      update(n);
      return balance(n);
    }

    Node<T>* remove(Node<T>* n, T value){
      if(n = nullptr){ return nullptr; }

      int cmp = n->value > value ? -1 : 1;
      if(cmp < 0){ 
        n->left = remove(n->left, value);
      } else if(cmp > 0){
        n->right = remove(n->left, value);
      } else {

        if(n->left == nullptr) { return n->right; }
        else if(n->right == nullptr) { return n->left; }
        else {
          if(n->left->height > n->right->height){
            T successorValue = findMax(n->left);
            n->value = successorValue;

            n->left = remove(n->left, successorValue);
          } else {
            T successorValue = findMin(n->right);
            n->value = successorValue;

            n->right = remove(n->right, successorValue);
          }
        }
      }
      
      update(n);
      return balance(n);
    }

    void update(Node<T>* n){
      int lh = n->left == nullptr ? -1 : n->left->height;
      int rh = n->right == nullptr ? -1 : n->right->height;

      n->height = 1 + std::max(lh, rh);
      n->balanceFactor = rh - lh;
    }

    Node<T>* balance(Node<T>* n){
      if(n->balanceFactor == -2){
        if(n->left->balanceFactor <=0){
          return leftLeftCase(n);
        } else {
          return leftRightCase(n);
        }
      } else if(n->balanceFactor == 2){
        if(n->right->balanceFactor >= 0){
          return rightRightCase(n);
        } else {
          return rightLeftCase(n);
        }
      }

      return n;
    }

    Node<T>* rightRotate(Node<T>* n){
      auto newParent = n->left;
      n->left = newParent->right;
      newParent->right = n;

      update(n);
      update(newParent);

      return newParent;
    }

    Node<T>* leftRotate(Node<T>* n){
      auto newParent = n->right;
      n->right = newParent->left;
      newParent->left = n;

      update(n);
      update(newParent);

      return newParent;
    }

    Node<T>* leftLeftCase(Node<T>* n){
      return rightRotate(n);
    }
    Node<T>* leftRightCase(Node<T>* n){
      n->left = leftRotate(n->left);
      return leftLeftCase(n);
    }
    Node<T>* rightRightCase(Node<T>* n){
      return leftRotate(n);
    }
    Node<T>* rightLeftCase(Node<T>* n){
      n->right = rightRotate(n->right);
      return rightRightCase(n);
    }

    T findMax(Node<T>* n){
      while(n->right != nullptr) { n = n->right; }
      return n->value;
    }

    T findMin(Node<T>* n){
      while(n->left != nullptr){ n = n->left; }
      return n->value;
    }
  private:
    Node<T>* root = nullptr;
    unsigned int nodeCount = 0;
}; 
