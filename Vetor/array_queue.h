// Copyright [2017] <João Pedro Santana>"
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {
template<typename T>
//! Classe ArrayStack
    /*!
    implementação da fila com vetores.
    */
class ArrayQueue {
  //! Métodos públicos
  /*!
  usada pela classe ArrayQueue
  */
 public:
    //! Método construtor da fila
    /*!
    Arrayqueue é o construtor,sem passagem de parâmentro.
    */
    ArrayQueue() {
        //* max_size_ recebe valor do DEFAULT_SIZE*/
        max_size_ = DEFAULT_SIZE;
        //* contents é atribuido a um vetor de T com tamanho DEFAULT_SIZE.*/
        contents = new T[DEFAULT_SIZE];
        //* size_ é atribuido -1*/
        size_ = -1;
    }
    //! Método construtor da fila com passagem de parâmetro
    /*!
    ArrayQueue é o construtor,com passagem de parâmentro.
    max variavel passada como parâmetro para identificação do tamanho do vetor.
    */
    explicit ArrayQueue(std::size_t max) {
        //* max_size_ recebe o valor de max.*/
        max_size_ = max;
        //* contents é atribuido ao vetor de T com tamanho max. */
        contents = new T[max];
        //* size_ é atribuido a -1*/
        size_ = -1;
    }	 	  	 	   	      	 	     	     	   	      	 	
    //! Método destrutor da fila.
    /*!
    ~ArrayQueue é o destrutor.
    */
    ~ArrayQueue() {
      //* deletando valores atribuidos ao contents
        delete[] contents;
    }
    //! metódo com um argumento sem retorno.
    /*!
    /param data um argumento endereço.
    */
    void enqueue(const T& data) {
     //* caso full() seja verdade*/
     if (full()) {
      //* é lançado ao sistema uma mensagem para não ocorrer erro*/
     throw std::out_of_range("CHEIO");
     //* caso full() seja falso executa oque esta atribuido dentro do else. */
     } else {
        //* size_ é incrementado*/
        size_++;
        //* contents na posição size recebe o endereço de data*/
        contents[size_] = data;
    }
    }
    //! metódo sem argumento,retornando um template T retirado da fila.
    /*!
    return um template.
    */
    T dequeue() {
     //* caso empty() seja verdade.*/
     if (empty()) {
     //*  é lançado uma mensagem para evitar erros*/
      throw std::out_of_range("VAZIO");
     //* caso empty() seja falso.*/
     } else {	 	  	 	   	      	 	     	     	   	      	 	
        //* size_ é decrementado*/
         size_--;
        //* aux recebe o valor que será retirado*/
         T aux = contents[0];
         //* for percorre o vetor*/
         for (int i = 1 ; i <= size() ; i++) {
            //* troca os valores para posição anterior*/
            contents[i-1] = contents[i];
         }
      // retorna o valor do aux*/
      return aux;
     }
    }
    //! metodo sem argumento,retornando o ultimo endereço do template T.
    /*!
    return um endereço do Template T.
    */
    T& back() {
     if (empty()) {
      throw std::out_of_range("VAZIO");
     } else {
        return contents[size_];
     }
    }
    //! metodo que renicia a posição do top_.
    /*!
    atribui -1 ao top_.
    */
    void clear() {
        size_ = -1;
    }
    //! metodo que retorna o tamanho do vetor da pilha.
    /*!
    retorna top_ incrementado
    */
    std::size_t size() {	 	  	 	   	      	 	     	     	   	      	 	
        return size_ +1;
    }
    //! metodo que retorna o tamanho máximo do vetor da pilha
    /*!
    retorna max_size_
    */
    std::size_t max_size() {
        return max_size_;
    }
    //! metodo que retorna se o vetor está vazio
    /*!
    retorna um valor booleano verdadeiro se for igual a -1 e falso se for outro valor diferente.
    */
    bool empty() {
        return size_ == -1;
    }
    //! metodo que retorna se o vetor está cheio
    /*!
    retorna um valor booleano verdadeiro se top_ for igual a max_size() -1
    */
    bool full() {
        return size_ == max_size() - 1;
    }
//! Variaveis e constantes privadas
/*!
 usadas pela classe Arrayqueue
*/
 private:
    //* contents é uma variavel Ponteiro para armazenar dados da fila.*/
    T* contents;
    //* size_ é a variavel com a posição do ultimo dado da fila
    std::size_t size_;
    //* max_size_ é uma variavel com valor maximo da fila.*/
    std::size_t max_size_;
    //* DEFAULT_SIZE é uma constante com valor para incializar a pilha.*/
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures
#endif
	 	  	 	   	      	 	     	     	   	      	 	
