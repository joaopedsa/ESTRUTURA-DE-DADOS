// "Copyright [2017] <João Pedro Santana>"

#include "./linked_list.h"

namespace structures {


template<typename T>
  //! CLASSE LINKEDQUEUE
class LinkedQueue : public LinkedList<T> {
 public:
    LinkedQueue() {
    }

    ~LinkedQueue() {
    }
    //! CLASSE LINKEDQUEUE
    void clear() {
        LinkedList<T>::clear();
    }  // limpar
    //! Metodo Enfilera
    void enqueue(const T& data) {
        LinkedList<T>::push_back(data);
    }  // enfilerar
    //! Metodo Desinfilera
    /*!
    Retira sempre do inicio,segundo a regra da fila
    */
    T dequeue() {
        return LinkedList<T>::pop_front();
    }  // desenfilerar
    //! Metodo front()
    /*!
    Puxa o primeiro dado do ponteiro
    */
    T& front() const {
        return LinkedList<T>::at(0);
    }  // primeiro dado
    //! Metodo Back()
    /*!
    Puxa o ultimo dado do ponteiro
    */
    T& back() const {	 	  	 	   	      	 	     	     	   	      	 	
        return LinkedList<T>::at(size()-1);
    }  // último dado
    //! Metodo Empty()
    bool empty() const {
        return LinkedList<T>::empty();
    }  // fila vazia
    //! Metodo Size()
    std::size_t size() const {
        return LinkedList<T>::size();
    }  // tamanho

 private:
    std::size_t size_;  // tamanho
};

}  // namespace structures
