#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
		T*arr;
		int max;
		int n;
		static const int MINSIZE;

		void resize(int new_size){
		
			T*nuevo = new T[new_size];
			for (int i = 0; i < n; i++){
				nuevo[i] = arr[i];
			}

			delete[]arr;
			arr = nuevo;
			max = new_size;
		
		}

	public:
		ListArray() {
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
		}

		~ListArray() override {
			delete[] arr;
		}

		bool empty() override {
			return n==0;
		}

		int size() override {
		
			return n;
		}

		T get(int pos) override {
			if (pos < 0 || pos >= n)
				throw std::out_of_range("¡posición inválida!");
			return arr[pos];
		
		}

		T operator[](int pos){
			return get(pos);
		}

		int search(T e) override {
			for (int i = 0; i < n; i++) {
				if (arr[i] == e)
					return i;
			}
			return -1;
		
		
		
		
		}
	void insert(int pos, T e) override {
		if (pos < 0 || pos > n)
			throw std::out_of_range("¡posición inválida!");

		if (n==max)
			resize(max*2);
		
		for (int i = n; i > pos; i--){
			arr[i] = arr[i -1];
		
		}
		arr[pos] = e;
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
			throw std::out_of_range("posición inválida");

		T e = arr[pos];
		for(int i = pos; i < n - 1; i++){
			arr[i] = arr[i+1];
		}
		n--;

		if (n < max / 4 && max / 2 >= MINSIZE)
			resize(max/2);

		return e;

	}


	friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
		out << "List => [";
		if(list.n > 0){
			out << "\n";
			for (int i = 0; i < list.n; i++){
				out << "  " << list.arr[i] << "\n";
			
			
			
			
			}
		
		
		
		}
		out << "]";
		return out;
	
	
	
	}
	
	


};

template <typename T>
const int ListArray<T>::MINSIZE = 2;

#endif
