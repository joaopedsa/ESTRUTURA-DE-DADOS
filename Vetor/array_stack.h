// Copyright [2017] <João Pedro Santana>"
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
namespace structures {
template<typename T>
//! Classe ArrayStack
    /*!
    implementação da pilha com vetores.
    */
class ArrayStack {
  //! Métodos públicos
  /*!
  usada pela classe ArrayStack
  */
 public:
    //! Método construtor da pilha
    /*!
    ArrayStack é o construtor,sem passagem de parâmentro.
    */
    ArrayStack() {
      //* max_size_ recebe valor do DEFAULT_SIZE*/
        max_size_ = DEFAULT_SIZE;
      //* contents é atribuido a um vetor de T com tamanho DEFAULT_SIZE.*/
        contents = new T[DEFAULT_SIZE];
      //* top_ é atribuido a -1.*/
        top_ = -1;
        }
    //! Método construtor da pilha com passagem de parâmetro
    /*!
    ArrayStack é o construtor,com passagem de parâmentro.
    max variavel passada como parâmetro para identificação do tamanho do vetor.
    */
    explicit ArrayStack(std::size_t max) {
      //* max_size_ recebe o valor de max.*/
        max_size_ = max;
      //* contents é atribuido ao vetor de T com tamanho max. */
        contents = new T[max];
      //* top_ é atribuido a -1.*/
        top_ = -1;
    }	 	  	 	   	      	 	     	     	   	      	 	
    //! Método destrutor da pilha.
    /*!
    ~ArrayStack é o destrutor.
    */
    ~ArrayStack() {
      //* deletando valores atribuidos ao contents
        delete[] contents;
    }
    //! metódo com um argumento sem retorno.
    /*!
    /param data um argumento endereço.
    */
    void push(const T& data) {
     //* caso full() seja verdade*/
     if (full()) {
      //* é lançado ao sistema uma mensagem para não ocorrer erro*/
     throw std::out_of_range("CHEIO");
     //* caso full() seja falso executa oque esta atribuido dentro do else. */
     } else {
        //* top_ vai ser incrementado. */
        top_++;
        //* contents recebe valor de data. */
        contents[top_] = data;
     }
    }  // empilha
    //! metódo sem argumento,retornando um template T retirado da pilha.
    /*!
    return um template.
    */
    T pop() {
     //* caso empty() seja verdade.*/
     if (empty()) {
      //*  é lançado uma mensagem para evitar erros*/
      throw std::out_of_range("VAZIO");
     //* caso empty() seja falso.*/
     } else {	 	  	 	   	      	 	     	     	   	      	 	
        //* top_ é decrementado mudando a posição do ultimo elemento da pilha.*/
        top_--;
        //* return é igual ao elemento retirado da pilha.*/
        return contents[top_+1];
     }
    }  // desempilha
    //! metodo sem argumento,retornando o ultimo endereço do template T.
    /*!
    return um endereço do Template T.
    */
    T& top() {
     //* caso empty() seja verdadeiro.*/
     if (empty()) {
     //* é lançado uma mensagem para evitar erros*/
        throw std::out_of_range("VAZIO");
     //* caso empty() seja falso.*/
     } else {
        //* retorna o último valor da pilha.*/
        return contents[top_];
     }
    }
    //! metodo que renicia a posição do top_.
    /*!
    atribui -1 ao top_.
    */
    void clear() {
        top_ = -1;
    }  // limpa

    //! metodo que retorna o tamanho do vetor da pilha.
    /*!
    retorna top_ incrementado
    */
    std::size_t size() {
        return top_ + 1;
    }  // tamanho
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
        return top_ == -1;
    }  // vazia
    //! metodo que retorna se o vetor está cheio
    /*!
    retorna um valor booleano verdadeiro se top_ for igual a max_size() -1
    */
    bool full() {
        return top_ == max_size() - 1;
    }  // cheia
//! Variaveis e constantes privadas
/*!
 usadas pela classe ArrayStack
*/
 private:
    //* contents é uma variavel Ponteiro para armazenar dados da pilha.*/
    T* contents;
    //* top_ é uma variavel inteiro com valor do ultimo valor da pilha.*/
    int top_;
    //* max_size_ é uma variavel com valor maximo da pilha.*/
    std::size_t max_size_;
    //* DEFAULT_SIZE é uma constante com valor para incializar a pilha.*/
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif
	 	  	 	   	      	 	     	     	   	      	 	
