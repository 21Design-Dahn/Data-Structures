#include <iostream>

template<typename T>
class Node{
  public: 
    Node(T value)
      : data(value)
    {
      left = nullptr;
      right = nullptr;
      parent = nullptr;
    }
    void insert(Node<T>* n){
      if(data < n->data){
        if(right == nullptr){
          right = n;
          right->parent = this;
        } else {
          right->insert(n);
        }
      } else if (data > n->data){
        if(left == nullptr){
          left = n;
          left->parent = this;
        } else {
          left->insert(n);
        }
      } 
    }

    void remove(Node<T>* n, T value){
      //find phase
      Node<T>* finder = find(n, value);
      if(finder == nullptr){
        std:: cout << "cannot delete a not existing node" << std::endl;
      }
      auto parent = finder->parent;

      //case 1: deleting the leaf
      if(finder->left == nullptr && finder->right == nullptr){
        if(parent->left->data == value){
          parent->left = nullptr;
          delete parent->left;
        } else if(parent->right->data == value){
          parent->right = nullptr;
          delete parent->right;
        }
      }
      
      // case 2 & 3 left or right is missing requirements parent & successor
      if(finder->left == nullptr && finder->right != nullptr){
        //get right
        //we can just swap the parent data to left right
        // then delete the right
        if(parent->right->data == value){
          parent->right = finder->right;
        } else if (parent->left->data == value){
          parent->right = finder->right;
        }
      } else if(finder->right == nullptr && finder->left != nullptr){

        if(parent->right->data == value){
          parent->left = finder->left;
        } else if(parent->left->data == value){
          parent->left = finder->left;
        }
      }
      // case 4 : find the closest number to the number you picked
      // swap it to the number you find recurse to case 1 2 or 3
      if(finder->right != nullptr && finder->left != nullptr){
        //successor can be both the left subtree or the smallest value on the right subtree

        //find the smallest number on the right subtree
        //swap it to the finder data and remove the smallest to satisfy the invariant
        auto smallest = findSmallest(finder->right);
        auto temp = smallest->data;
        finder->data = temp;
        remove(finder->right, smallest->data);

        // also this can be implemented using the largest value on the left subtree using this code:
        // auto largest = findLargest(finder->left);
        //finder->data = largest->data;
        //remove(finder->left, largest->data)
      }

      finder = nullptr;
      delete finder;
      //std::cout << finder->data << std::endl;
    }

    Node<T>* findSmallest(Node<T>* n){
      if(n->left == nullptr){
        return n;
      }

      findSmallest(n->left);
    }

    Node<T>* findLargest(Node<T>* n){
      if(n->right == nullptr){
        return n;
      } 

      findLargest(n->right);
    }

    Node<T>* find(Node<T>* n, T value){
      if(n == nullptr){
        return nullptr;
      }
      
      if(n->data == value){
        return n;
      }

      if(n->data < value){
        return find(n->right, value);
      } else{
        return find(n->left, value);
      }
    }

    bool search(Node<T>* n, T value){
      
      if(n == nullptr){
        return false;
      } 
      if(n->data == value){
        return true;
      }

      if(n->data < value){
        return search(n->right, value);
      } else {
        return search(n->left, value);
      }
    }

    void inorder(Node<T>* n){
      if(n != nullptr){
        n->inorder(n->left);
        std:: cout << n->data << std:: endl;

        n->inorder(n->right);
      }
    }

    void preorder(Node<T>* n){
      if(n != nullptr){
        std:: cout << n->data << std:: endl;
        n->preorder(n->left);
        n->preorder(n->right);
      }
    }

    void postorder(Node<T>* n){
      if(n != nullptr){
        n->postorder(n->left);
        n->postorder(n->right);
        std::cout << n->data << std:: endl; 
      }

    }

  private:
    T data;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
class BinarySearchTree{
  public:
    BinarySearchTree(){
      root = nullptr;
    }

    void Insert(T value){
      Node<T>* newNode = new Node<T>(value);

      if(root == nullptr){
        root = newNode;
        newNode = nullptr;
        delete newNode;
      } else {
        root->insert(newNode);
        newNode = nullptr;
        delete newNode;
      }
    }

    void Remove(T value){

      root->remove(root, value);
    }

    bool Search(T value){
      
      bool result = root->search(root, value);
      return result;
    }

    void Inorder(){
      root->inorder(root);
    }

    void Preorder(){
      root->preorder(root);
    }

    void Postorder(){
      root->postorder(root);
    }
  private:
    Node<T>* root;
};