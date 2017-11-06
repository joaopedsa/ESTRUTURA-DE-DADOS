// "Copyright [2017] <João Pedro Santana>"
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
  //! Lista Circular Dupla
class DoublyCircularList {
 public:
    DoublyCircularList() {
        head = nullptr;
        size_ = 0;
    }
    ~DoublyCircularList() {
    clear();
    }
    //! Limpa Lista com o metodo pop_front()
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    //! insere na ultima posição
    void push_back(const T& data) {
    if (empty()) {
        push_front(data);
     } else {
    Node* ult = head -> prev();
    Node* novo = new Node(data , ult , head);
    head -> prev(novo);
    ult -> next(novo);
    size_++;
    }	 	  	 	   	      	 	     	     	   	      	 	
    }  // insere no fim
    //! insere na primeira posição
    void push_front(const T& data) {
    Node* novo = new Node(data);
        if (novo == nullptr) {
            throw std::out_of_range("lista cheia!");
        }
        if (empty()) {
            head = novo;
            novo->next(head);
            novo->prev(head);
            ++size_;
        } else {
            novo->next(head);
            novo->prev(head->prev());
            head = novo;
            (head->prev())->next(head);
            ++size_;
        }
    }  // insere no início
    //! insere na posição do index
    void insert(const T& data, std::size_t index) {
    if (index == 0) {
        push_front(data);
    } else if (index > size_) {
        throw std::out_of_range("FORA DOS PADRÔES");
    } else {
        Node* atual = head;
        for (int i = 0 ; i < index-1 ; i++) {
            atual = atual -> next();
        }
        Node* novo = new Node(data , atual , atual -> next());
        (atual -> next()) -> prev(novo);
        atual -> next(novo);
        size_++;
    }	 	  	 	   	      	 	     	     	   	      	 	
    }  // insere na posição
    //! insere em ordem crescente
    void insert_sorted(const T& data) {
    if (empty()) {
        return push_front(data);
    }
    auto atual = head;
    int index = 0;
    while (index < size_ && data > atual->data()) {
        atual = atual->next();
        index++;
        }
    return insert(data, index);
    }  // insere em ordem
    //! retira da posicao index
    T pop(std::size_t index) {
        T dado;
        if (index == 0) {
            pop_front();
        } else if (index >= size_) {
            throw std::out_of_range("FORA DOS PADRÕES");
        } else {
            Node* atual = head;
            for (int i = 0 ; i != index ; i++) {
                atual = atual -> next();
            }
            (atual->prev()) -> next(atual->next());
            (atual->next()) -> prev(atual->prev());
            dado = atual->data();
            delete atual;
            size_--;
        }
        return dado;
    }  // retira da posição
    //! retira da ultima posicao
    T pop_back() {	 	  	 	   	      	 	     	     	   	      	 	
        if (empty()) {
            throw std::out_of_range("VAZIO");
        }
        if (size_ == 1) {
            return pop_front();
        }
        auto data = head->prev()->data();
        auto del = head->prev();
        del->prev()->next(head);
        head->prev(del->prev());
        delete del;
        size_--;
        return data;
    }  // retira do fim
    //! retira da primeira posição
    T pop_front() {
        Node *atual = head;
        T dado;
        if (empty()) {
            throw std::out_of_range("VAZIO");
        } else {
            dado = atual->data();
            Node *ult = head -> prev();
            head = atual->next();
            head -> prev(ult);
            ult -> next(head);
            size_--;
            delete atual;
            return dado;
        }
    }  // retira do início
    //! retira o dado passado como parametro
    void remove(const T& data) {
    pop(find(data));
    }  // retira específico
    //! retorna true caso esteje vazio
    bool empty() const {	 	  	 	   	      	 	     	     	   	      	 	
        return size_== 0;
    }  // lista vazia
    //! retornar true caso exista o paramentro data
    bool contains(const T& data) const {
        if (empty()) {
            throw std::out_of_range("lista vazia!");
        } else if (find(data) == size_) {
            return false;
        } else {
            return true;
        }
    }  // contém
    //! retorna o dado da posicao index
    T& at(std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Erro de posicao.");
        } else if (empty()) {
            throw std::out_of_range("Empty.");
        } else {
            auto curr = head;
            for (int i = 0u; i < index; i++) {
                curr = curr->next();
            }
            return curr->data();
        }
    }  // acesso a um elemento (checando limites)
    //! retorna o dado da posicao index
    const T& at(std::size_t index) const {
        Node* atual = head;
    for (int i = 0 ; i < index ; i++) {
        atual =atual -> next();
    }
    return atual -> data();
    }  // getter constante a um elemento
    //! retorna posicao do paramentro data
    std::size_t find(const T& data) const {	 	  	 	   	      	 	     	     	   	      	 	
        if (empty()) {
            throw std::out_of_range("Empty.");
        } else {
            Node* atual = head;
            for (int i = 0; i < size_; ++i) {
                if (atual->data() == data) {
                    return i;
                }
                atual = atual->next();
            }
            return size_;
        }
    }  // posição de um dado
    //! retorna o tamanho da lista
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
        prev_{prev},
        next_{next}
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

#endif
	 	  	 	   	      	 	     	     	   	      	 	
