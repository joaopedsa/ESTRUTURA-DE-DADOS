// "Copyright [2017] <João Pedro Santana>"
#define STRUCTURES_DOUBLY_LINKED_LIST_H
#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
  //! Lista Duplamente Encadeada
class DoublyLinkedList {
 public:
    DoublyLinkedList() {
        head = nullptr;
        size_ = 0;
    }
    ~DoublyLinkedList() {
        clear();
    }
    //! Clear
    void clear() {
    while (!empty()) {
        pop_front();
    }
    }
    //! Lista encadeada
    void push_back(const T& data) {
    Node* atual = head;
    Node* anterior = nullptr;
    if (empty()) {
        push_front(data);
    } else {
    for (int i = 0 ; i < size_ ; i++) {
        if (i == size_-1) {
            Node* novo = new Node(data);
            atual -> next(novo);
            atual -> prev(anterior);
            size_++;
            break;
        } else {	 	  	 	   	      	 	     	     	   	      	 	
           anterior = atual;
           atual = atual -> next();
        }
    }
    }
    }  // insere no fim
    //! Lista encadeada
    void push_front(const T& data) {
        Node* aux = head;
        Node* novo = new Node(data , aux);
        head = novo;
        size_++;
    }  // insere no início
    //! Lista encadeada
    void insert(const T& data, std::size_t index) {
    Node* atual = head;
    Node* anterior = nullptr;
    if (index < 0 || index > size_) {
        throw std::out_of_range("VAZIO");
    } else {
    for (int i = 0 ; i < size_ ; i++) {
        if (i == index) {
            Node* novo = new Node(data , atual);
            anterior -> next(novo);
            novo -> prev(anterior);
            size_++;
            break;
        } else {
            anterior = atual;
            atual = atual -> next();
        }
    }
    }
    }  // insere na posição
    //! Lista encadeada
    void insert_sorted(const T& data) {	 	  	 	   	      	 	     	     	   	      	 	
    Node* atual = head;
    Node* anterior = nullptr;
    if (empty()) {
        push_front(data);
    } else {
    for (int i = 0 ; i < size_ ; i++) {
        if (atual -> data() > data && i == 0) {
            push_front(data);
            break;
        } else if (atual -> data() > data) {
            Node* novo = new Node(data , atual);
            anterior -> next(novo);
            novo -> prev(anterior);
            size_++;
            break;
        } else if (i == size_-1) {
            push_back(data);
            break;
        } else {
            anterior = atual;
            atual = atual -> next();
        }
    }
    }
    }  // insere em ordem
    //! Lista encadeada
    T pop(std::size_t index) {
    T dado;
    if (index < 0 || index > size_-1) {
        throw std::out_of_range("FORA DOS PADRÔES");
    } else {
    Node* atual = head;
    Node* anterior = nullptr;
    Node* proximo = nullptr;
    for (int i = 0 ; i < size_ ; i++) {
        if (index == i) {	 	  	 	   	      	 	     	     	   	      	 	
            dado = atual -> data();
            delete atual;
            anterior -> next(proximo);
            proximo -> prev(anterior);
            size_--;
            break;
        } else {
            anterior = atual;
            atual = atual -> next();
            proximo = atual -> next();
        }
    }
    }
    return dado;
    }  // retira da posição
    //! Lista encadeada
    T pop_back()  {
        T dado;
        Node* atual = head;
        if (empty()) {
            throw std::out_of_range("VAZIO");
        } else {
        for (int i = 0 ; i < size_ ; i++) {
            if (i == size_-1) {
                dado = atual -> data();
                delete atual;
                size_--;
            } else {
                atual = atual -> next();
            }
        }
    }
    return dado;
    }  // retira do fim
    //! Lista encadeada
    T pop_front() {	 	  	 	   	      	 	     	     	   	      	 	
        T dado;
        Node* atual = head;
        if (empty()) {
            throw std::out_of_range("VAZIO");
        } else {
            head = head -> next();
            dado = atual -> data();
            delete (atual);
            size_--;
            return dado;
        }
    }  // retira do início
    //! Lista encadeada
    void remove(const T& data) {
    Node* atual = head;
    Node* anterior = nullptr;
    Node* proximo = nullptr;
    for (int i = 0 ; i < size_ ; i++) {
        if (atual -> data() == data) {
            delete atual;
            anterior -> next(proximo);
            proximo -> prev(anterior);
            size_--;
        } else {
            anterior = atual;
            atual = atual -> next();
            proximo = atual -> next();
        }
    }
    }  // retira específico
    //! Lista encadeada
    bool empty() const {
        return size_ == 0;
    }  // lista vazia
    //! Lista encadeada
    bool contains(const T& data) const {	 	  	 	   	      	 	     	     	   	      	 	
        Node* atual = head;
        for (int i = 0 ; i < size_ ; i++) {
            if (atual -> data() == data) {
                return true;
                break;
            } else {
                atual = atual -> next();
            }
        }
    return false;
    }  // contém
    //! Lista encadeada
    T& at(std::size_t index) {
        Node* atual = head;
        if (index < 0 || index > size_-1) {
            throw std::out_of_range("FORA DOS PADRÕES");
        } else {
            for (int i = 0 ; i < size_ ; i++) {
                if (i == index) {
                    return atual -> data();
                    break;
                } else {
                    atual = atual -> next();
                }
            }
        }
        return atual -> data();
    }  // acesso a um elemento (checando limites)
    //! Lista encadeada
    const T& at(std::size_t index) const {
            Node* atual = head;
            for (int i = 0 ; i < size_ ; i++) {
                if (i == index) {
                    return atual -> data();
                    break;
                } else {	 	  	 	   	      	 	     	     	   	      	 	
                    atual = atual -> next();
                }
            }
    return atual -> data();
    }  // getter constante a um elemento

    //! Lista encadeada
    std::size_t find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("VAZIO");
        } else {
            Node* atual = head;
            for (int i = 0 ; i < size_ ; i++) {
                if (atual -> data() == data) {
                    return i;
                    break;
                } else {
                    atual = atual -> next();
                }
            }
        }
    return size_;
    }  // posição de um dado
    //! Lista encadeada
    std::size_t size() const {
        return size_;
    }  // tamanho

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}	 	  	 	   	      	 	     	     	   	      	 	
        {}
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            next_{next},
            prev_{prev}
        {}
        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }
        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;
    std::size_t size_;
};

}  // namespace structures
	 	  	 	   	      	 	     	     	   	      	 	
