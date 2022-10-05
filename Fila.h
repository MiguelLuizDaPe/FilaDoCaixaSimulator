#ifndef INCLUDE_FILA_H_
#define INCLUDE_FILA_H_

#include <iostream>

template<class T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;

	Node() {
		this->next = nullptr;
		this->prev = nullptr;
	}

};

template<class T>
struct Queue{
	Node<T> *head;
	Node<T> *tail;
	void enqueue(T data) {
		Node<T> *el = new Node<T>;
		el->data = data;
        if (this->tail == nullptr) { // quando for lista vazia
            el->next = this->head;
            el->prev = this->tail;
            this->head = el;
            this->tail = el;
        }
        else {
            el->next = this->tail;
            this->tail->prev = el;
            el->prev = nullptr;
            this->tail = el;
        }
	} // melhor: insert(int pos, const T& data)
	T dequeue() {
		if(this->tail == nullptr){
			throw "Lista Vazia\n";
		}
        if (this->tail->next == nullptr) { // quando for uma lista com um elemento
            Node<T> *del = tail;
            this->head = nullptr;
            this->tail = nullptr;
            T resto = del->data;
            delete del;
            return resto;
        }
        else {
            Node<T> *del = this->head;
            this->head = del->prev;
            del->prev->next = nullptr;
            T resto = del->data; 
            delete del;
            return resto;

        }
	}
	int size() {
		Node<T> *nav = this->tail;
		int n = 0;
		if (this->tail == nullptr) {
			return 0;
		}
		while (nav->next != nullptr) {
			nav = nav->next;
			n++;
		}
		return n + 1;
	}
	void print(){
		if(this->tail == nullptr) {
			std::cout << "Lista vazia" << std::endl;
		}else {
			auto nav = this->tail;
			while(nav->next != nullptr){
				std::cout << nav->data << " ";
				nav = nav->next;
			}
		std::cout << nav->data << "\n";
		}
	}

	Queue() {
		this->head = nullptr;
		this->tail = nullptr;
	}

};
#endif
