#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;

    public:
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        ~ListLinked() override {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n)
                throw std::out_of_range("Posición inválida!");

            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        T operator[](int pos) {
            return get(pos);
        }

        int search(T e) override {
            Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr) {
                if (aux->data == e)
                    return i;
                aux = aux->next;
                i++;
            }
            return -1;
        }

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n)
                throw std::out_of_range("Posición inválida!");

            if (pos == 0) {
                first = new Node<T>(e, first);
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                prev->next = new Node<T>(e, prev->next);
            }
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n)
                throw std::out_of_range("Posición inválida!");

            Node<T>* borrar;
            if (pos == 0) {
                borrar = first;
                first = first->next;
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                borrar = prev->next;
                prev->next = borrar->next;
            }

            T e = borrar->data;
            delete borrar;
            n--;
            return e;
        }

        friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
            out << "List => [";
            if (list.n > 0) {
                out << "\n";
                Node<T>* aux = list.first;
                while (aux != nullptr) {
                    out << "  " << aux->data << "\n";
                    aux = aux->next;
                }
            }
            out << "]";
            return out;
        }
};

#endif
