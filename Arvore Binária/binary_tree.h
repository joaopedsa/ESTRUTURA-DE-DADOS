// Copyright [2017] <João Pedro Santana>"

#include "array_list.h"

namespace structures {
template <typename T>
//! ARVORE BINARIA
class BinaryTree {
 public:
    BinaryTree() {
        root = nullptr;
        size_ = 0;
    }
    ~BinaryTree() {
    }
//! insersao
    void insert(const T& data) {
    if (empty()) {
        root = new Node(data);
    } else {
        root -> insert(data);
    }
    size_++;
    }
//! remoção
    void remove(const T& data) {
    if (empty()) {
        throw std::out_of_range("VAZIO");
    } else if (root->remove(data)) {
        size_--;
    }
    }
//! contem
    bool contains(const T& data) const {
    if (empty()) {
        throw std::out_of_range("Vazio");
    } else if (root->contains(data)) {	 	  	 	   	      	 	     	     	   	      	 	
        return true;
    }
    return false;
    }
//! checagem se esta vazio
    bool empty() const {
        return size_ == 0;
    }
//! checagem do tamanho
    std::size_t size() const {
        return size_;
    }
//! pre_ordenamento
    ArrayList<T> pre_order() const {
    structures::ArrayList<T> list{};
    if (empty()) {
        throw std::out_of_range("VAZIO");
    } else {
        root -> pre_order(list);
    }
    return list;
    }
//! em ordenamento
    ArrayList<T> in_order() const {
    structures::ArrayList<T> list{};
    if (empty()) {
        throw std::out_of_range("VAZIO");
    } else {
        root -> in_order(list);
    }
    return list;
    }
//! posordenamento
    ArrayList<T> post_order() const {
    structures::ArrayList<T> list{};
    if (empty()) {	 	  	 	   	      	 	     	     	   	      	 	
        throw std::out_of_range("VAZIO");
    } else {
        root -> post_order(list);
    }
    return list;
    }

 private:
    struct Node {
        explicit Node(const T& data_):
        data{data_}
        {}
        T data;
        Node* left{nullptr};
        Node* right{nullptr};
        void insert(const T& data_) {
        if (data_ > data) {
            if (right == nullptr) {
                right = new Node(data_);
            } else {
                right->insert(data_);
            }
        } else {
            if (left == nullptr) {
                left = new Node(data_);
            } else {
                left -> insert(data_);
            }
        }
        }
        bool remove(const T& data_) {
        if (data == data_) {
            if (right != nullptr && left != nullptr) {
                auto aux = valorMin(right);
                data = aux->data;
                return right->remove(data);
            } else {	 	  	 	   	      	 	     	     	   	      	 	
                if (right != nullptr) {
                    data = right->data;
                    return right->remove(data);
                } else if (left != nullptr) {
                    data = left->data;
                    return left->remove(data);
                } else {
                    delete this;
                    return true;
                }
            }
        } else if (data_ > data) {
            if (right != nullptr) {
                return right -> remove(data_);
            }
        } else {
            if (left != nullptr) {
                return left -> remove(data_);
            }
        }
        return false;
        }
        bool contains(const T& data_) const {
        if (data_ != data) {
            if (data_ > data) {
                if (right != nullptr)
                return right->contains(data_);
            } else {
                if (left != nullptr)
                return left->contains(data_);
            }
            return false;
        } else {
            return true;
        }
        }	 	  	 	   	      	 	     	     	   	      	 	
        void pre_order(ArrayList<T>& v) const {
        v.push_back(data);
        if (left != nullptr) {
            left -> pre_order(v);
        }
        if (right != nullptr) {
            right -> pre_order(v);
        }
        }
        void in_order(ArrayList<T>& v) const {
        if (left != nullptr) {
            left->in_order(v);
            }
            v.push_back(data);
            if (right != nullptr) {
                right->in_order(v);
            }
        }
        void post_order(ArrayList<T>& v) const {
        if (left != nullptr) {
                left->post_order(v);
            }
            if (right != nullptr) {
                right->post_order(v);
            }
            v.push_back(data);
        }
        Node* valorMin(Node* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures
	 	  	 	   	      	 	     	     	   	      	 	
