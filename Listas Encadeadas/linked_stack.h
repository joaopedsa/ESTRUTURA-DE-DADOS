// "Copyright [2017] <João Pedro Santana>"
#include "./linked_list.h"

namespace structures {

template<typename T>
  //! LinkedStack
class LinkedStack : public LinkedList<T> {
 public:
    LinkedStack() {
    }

    ~LinkedStack() {
    }
  //! Clear
    void clear() {
        LinkedList<T>::clear();
    }  // limpa pilha
  //! push
    void push(const T& data) {
        LinkedList<T>::push_front(data);
    }  // empilha
  //! pop
    T pop() {
        return LinkedList<T>::pop_front();
    }  // desempilha
  //! top
    T& top() const {
        return LinkedList<T>::at(0);
    }  // dado no topo
  //! empty
    bool empty() const {
        return LinkedList<T>::empty();
    }  // pilha vazia
  //! size
    std::size_t size() const {
        return LinkedList<T>::size();
    }  // tamanho da pilha

 private:
    class Node {	 	  	 	   	      	 	     	     	   	      	 	
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);

        T& data();  // getter: info
        const T& data() const;  // getter-constante: info

        Node* next();  // getter: próximo
        const Node* next() const;  // getter-constante: próximo

        void next(Node* next);  // setter: próximo
     private:
        T data_;
        Node* next_;
    };
    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};

}  // namespace structures
