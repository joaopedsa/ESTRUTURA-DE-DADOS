// "Copyright [2017] <João Pedro Santana>"
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Lista Circular
class CircularList {
 public:
    CircularList() {
    size_ = 0;
    head = new Node((T)NULL , head);
    }
    ~CircularList() {
    clear();
    }
    //! Limpa Lista
    void clear() {
    while (!empty()) {
        pop_front();
    }
    }  // limpar lista
    //! insere na ultima posicao
    void push_back(const T& data) {
        if (empty()) {
            return push_front(data);
        } else {
            Node *atual = head->next();
            for (int i = 0; i < size_-1; ++i) {
                atual = atual->next();
            }
            atual->next(new Node(data, head));
            ++size_;
        }	 	  	 	   	      	 	     	     	   	      	 	
    }  // inserir no fim
    //! insere na primeira posicao
    void push_front(const T& data) {
        head->next(new Node(data, head->next()));
        size_++;
    }  // inserir no início
    //! insere na posicao index
    void insert(const T& data, std::size_t index) {
    if (index > size_) {
          throw std::out_of_range("Erro de posicao.");
        } else if (index == 0) {
            push_front(data);
        } else if (index == size_) {
            return push_back(data);
        } else {
            Node *prev = head->next();
            for (int i = 0; i < index-1; ++i) {
                prev = prev->next();
            }
            prev->next(new Node(data, prev->next()));
            ++size_;
        }
    }  // inserir na posição
    //! insere na posicao ordenada
    void insert_sorted(const T& data) {
            if (empty()) {
            return push_front(data);
        } else {
            Node* atual = head->next();
            int i = 0;
            while (i < size_ && data > atual->data()) {
                atual = atual->next();
                ++i;
            }
            insert(data, i);
        }	 	  	 	   	      	 	     	     	   	      	 	
    }  // inserir em ordem
    //! retorna  dado da posicao index
    T& at(std::size_t index) {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Erro de posicao.");
        } else {
            Node *atual = head->next();
            for (int i = 0; i < index; ++i) {
                atual = atual->next();
            }
            return atual->data();
        }
    }  // acessar em um indice (com checagem de limites)
    //! retorna dado da posicao index
    const T& at(std::size_t index) const {
    Node* atual = head -> next();
    for (int i = 0 ; i < index ; i++) {
        atual =atual -> next();
    }
    return atual -> data();
    }  // versão const do acesso ao indice
    //! retira da posicao index
    T pop(std::size_t index) {
        Node *atual, *del;
        T back;
        if (index >= size_) {
            throw std::out_of_range("Erro de posicao.");
        }
        if (index == 0) {
            pop_front();
        }
        atual = head->next();
        for (int i = 0; i < index-1; ++i) {
            atual = atual->next();
        }
        del = atual->next();
        back = del->data();
        atual->next(del->next());
        size_--;
        delete del;
        return back;
    }  // retirar da posição
    //! retira da ultima posicao
    T pop_back() {	 	  	 	   	      	 	     	     	   	      	 	
        if (size_ == 1) {
            return pop_front();
        } else {
            return pop(size_-1);
        }
    }  // retirar do fim
    //! retira da primeira posicao
    T pop_front() {
        T volta;
        Node *atual;
        if (empty()) {
            throw std::out_of_range("Empty.");
        } else {
            volta = head->next()->data();
            atual = head->next()->next();
            head->next(atual);
            --size_;
            return volta;
        }
    }  // retirar do início
    //! remove data da lista
    void remove(const T& data) {
    Node* atual = head -> next();
    Node* anterior = nullptr;
    Node* proximo = nullptr;
    for (int i = 0 ; i < size_-1; i++) {
        if (atual -> data() == data) {
            anterior -> next(proximo);
            delete atual;
            size_--;
        } else {
            anterior = atual;
            atual = atual -> next();
            proximo = atual -> next();
        }
    }	 	  	 	   	      	 	     	     	   	      	 	
    }  // remover dado específico
    //! retorna true caso a lista esteje vazia
    bool empty() const {
        return size_ == 0;
    }  // lista vazia
    //! retorna true caso paramentro data exista
    bool contains(const T& data) const {
        Node* posicao = head -> next();
        if (empty()) {
            throw std::out_of_range("VAZIO!");
        } else {
            for (int i = 0; i < size_ ; i++) {
                if (posicao -> data() == data) {
                    return true;
                } else {
                    posicao = posicao -> next();
                }
            }
        }
        return false;
    }  // lista contém determinado dado?
    //! acha a posicao do parametro data
    std::size_t find(const T& data) const {
        Node* posicao = head -> next();
        for (int i = 0 ; i < size_ ; i++) {
            if (posicao -> data() == data) {
                return i;
            } else {
            posicao = posicao -> next();
            }
            }
        return size_;
    }  // posição de um item na lista
    //! retorna o tamanho da lista
    std::size_t size() const {
        return size_;
    }  // tamanho da lista

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}	 	  	 	   	      	 	     	     	   	      	 	
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() {  // último nodo da lista
        auto it = head -> next();
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }	 	  	 	   	      	 	     	     	   	      	 	
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures

#endif
