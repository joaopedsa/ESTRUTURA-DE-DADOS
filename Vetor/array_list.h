// Copyright [2017] <João Pedro Santana>"
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Classe ArrayList
/*!
Implementação de Lista
*/
class ArrayList {
 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_MAX = 10u;
  //! Método Públicos
  /*!
  usados pela classe ArrayList;
  */
 public:
    //! Método Construtor
    /*!
    variavel max_size_ com tamanho do array;
    variavel contents atribuido ao array de Template;
    variavel size_ atribuido a -1;
    */
    ArrayList() {
        max_size_ = DEFAULT_MAX;
        contents = new T[max_size_];
        size_ = 0;
    }
    //! Método Construtor explicito
    /*!
    param max_size tamanho do array;
    variavel max_size_ com tamanho do array;
    variavel contents atribuido ao array de Template;
    variavel size_ atribuido a -1;
    */
    explicit ArrayList(std::size_t max_size) {	 	  	 	   	      	 	     	     	   	      	 	
        max_size_ = max_size;
        contents = new T[max_size_];
        size_ = 0;
    }
    //! Método Destrutor
    /*!
    deleta o valor atribuido ao contents;
    */
    ~ArrayList() {
        delete[] contents;
    }
    //! Método Limpa
    /*!
    variavel size_ atribuido a -1;
    */
    void clear() {
        size_ = 0;
    }
    //! Método de Inserção na ultima posição disponivel
    /*!
    metodo insert sendo instaciado passando como parametro,
    data e o size_ para inserir na ultima posição no array;
    */
    void push_back(const T& data) {
        if (size_ == max_size_) {
        throw std::out_of_range("CHEIO");
        } else {
        contents[size_] = data;
        size_++;
        }
    }
    //! Método de Inserção na primeira posição
    /*!
    metodo insert sendo instaciado passando como parametro,
    data e o 0 para inserir na primeira posição do array;
    */
    void push_front(const T& data) {	 	  	 	   	      	 	     	     	   	      	 	
        int p;
        if (full()) {
            throw std::out_of_range("ERRO_FULL");
        } else {
            p = size_;
            while ( p > 0 ) {
                contents[p] = contents[p-1];
                p--;
            }
            contents[0] = data;
        }
    size_++;
    }
    //! Método de Inserção
    /*!
    param data com o valor desejado
    param index na posição desejada
    */
    void insert(const T& data, std::size_t index) {
        if (full()) {
            throw std::out_of_range("CHEIO");
        } else if (empty()) {
            throw std::out_of_range("VAZIO");
        } else if (index <= size_-1) {
            for (int i = size_ ; i > index ; i--) {
            contents[i] = contents[i-1];
            }
        contents[index] = data;
        size_++;
        }
    }
    //! Método de Inserção em ordem
    /*!
    metodo insert sendo instaciado passando como parametro,
    data e colocando em posição de ordem no array;
    */
    void insert_sorted(const T& data) {	 	  	 	   	      	 	     	     	   	      	 	
        if (full()) {
            throw std::out_of_range("CHEIO");
        } else if (empty()) {
            contents[0] = data;
            size_++;
        } else {
        for (int i = 0 ; i < size_ ; i++) {
            if (contents[i] > data) {
            insert(data , i);
            break;
            } else if (i == size_-1) {
                contents[i+1] = data;
                size_++;
            break;
            }
        }
        }
    }
    //! Método popAt
    /*!
    retorna dados do array na posição do param index;
    */
    T pop(std::size_t index) {
        if (empty() || index >= size_) {
         throw std::out_of_range("FORA DO PADRAO!");
        }
        T aux = contents[index];
        for (int i = index; i < size_-1; i ++) {
            contents[i] = contents[i+1];
        }
        size_--;
        return aux;
    }
    //! Método pop_back
    /*!
    retorna dados do array na última posição do array;
    */
    T pop_back() {	 	  	 	   	      	 	     	     	   	      	 	
    if (empty()) {
     throw std::out_of_range("VAZIO");
    }
    size_--;
    return(contents[(size_)]);
    }
    //! Método pop_front
    /*!
    retorna dados do array na primeira posição do array;
    */
    T pop_front() {
    if (empty()) {
        throw std::out_of_range("VAZIO");
    }
    T aux = contents[0];
    for (int i = 0; i < size_-1 ; i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return aux;
    }
    //! Método remove
    /*!
    remove data do contents;
    */
    void remove(const T& data) {
        if (contains(data)) {
        int pos = find(data);
            for (int i = pos ; i < size_-1 ; i++) {
                contents[i] = contents[i+1];
            }
        size_--;
        }
    }
    //! Método full
    /*!
    retorna se o array está cheio
    */
    bool full() const {	 	  	 	   	      	 	     	     	   	      	 	
        return size_ == max_size_;
    }
    //! Método empty
    /*!
    retorna se o array esta vazio
    */
    bool empty() const {
        return size_ == 0;
    }
    //! Método contains
    /*!
    retorna se data existe dentro do array contents
    */
    bool contains(const T& data) const {
         if (empty()) {
         throw std::out_of_range("VAZIO");
         } else {
         for (int i = 0 ; i < max_size_ ; i++) {
             if (contents[i] == data) {
                 return true;
             }
         }
         }
        return false;
        }
    //! Método find
    /*!
    retorna posição em que o data esta;
    */
    std::size_t find(const T& data) const {
            if (empty()) {
            throw std::out_of_range("VAZIO");
            } else {
            for (int i = 0 ; i < size_ ; i++) {
                if (contents[i] == data) {
                    return i;
                }	 	  	 	   	      	 	     	     	   	      	 	
            }
            }
    return size_;
    }
    //! Método size
    /*!
    retorna a maior posição disponivel;
    */
    std::size_t size() const {
        return size_;
    }
    //! Método max_size
    /*!
    retorna o tamanho maximo do array;
    */
    std::size_t max_size() const {
        return max_size_;
    }
    //! Método at
    /*!
    retorna valor do array na posição index;
    */
    T& at(std::size_t index) {
        if (index <= size_) {
            return contents[index];
        } else {
            throw std::out_of_range("FORA DO LIMITE");
        }
    }
    //! Método []
    /*!
    retorna contents[index] no operator []
    */
    T& operator[](std::size_t index) {
    return contents[index];
    }	 	  	 	   	      	 	     	     	   	      	 	
    //! Método at
    /*!
    retorna valor do array na posição index;
    */
    const T& at(std::size_t index) const {
        if (index <= size_ && index > 0) {
            return contents[index];
        }
    }
    //! Método []
    /*!
    retorna contents[index] no operator []
    */
    const T& operator[](std::size_t index) const {
        return contents[index];
    }
};

}  // namespace structures

#endif
