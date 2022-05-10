#pragma once
#include <string>
template <typename T>
class List
{
	private:
		T* data = new T[0];
		int size = 0;
public:
	int count();
	T get(int index);
	void add(T item);
	void remove(T item);
	void remove(int index);
	int indexOf(T item);
	bool contains(T item);
	std::string toString();
};

template <typename T>
int List<T>::count() {
	return size;
}

template <typename T>
T List<T>::get(int index) {
	if (index < size && index >= 0) {
		return data[index];
	}
	else {
		throw "streep.lang.IndexOutOfRangeException";
	}
}

template <typename T>
void List<T>::add(T item) {
	T* newData = new T[size + 1];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	newData[size] = item;
	size++;
	delete[] data;
	data = newData;
}

template <typename T>
void List<T>::remove(int index) {
	int newSize = size - 1;
	if (newSize < 0) newSize = 0;
	T* newData = new T[newSize];
	for (int i = 0; i < size; i++) {
		if (i < index) {
			newData[i] = data[i];
		}
		else if (i > index) {
			newData[i - 1] = data[i];
		}
	}
	size--;
	delete [] data;
	data = newData;
}

template <typename T>
void List<T>::remove(T item) {
	int index = indexOf(item);
	int newSize = size - 1;
	if (newSize < 0) throw "Item was not found in list!";
	T* newData = new T[newSize];
	for (int i = 0; i < size; i++) {
		if (i < index) {
			newData[i] = data[i];
		}
		else if (i > index) {
			newData[i - 1] = data[i];
		}
	}
	size--;
	delete [] data;
	data = newData;
}

template <typename T>
int List<T>::indexOf(T item) {
	for (int i = 0; i < size; i++) {
		if (data[i] == item) {
			return i;
		}
	}
	return -1;
}

template <typename T>
bool List<T>::contains(T item) {
	return indexOf(item) != -1;
}

template <typename T>
std::string List<T>::toString() {
	std::string endresult = "[";
	for (int i = 0; i < size; i++) {
		endresult.append(get(i));
		if (i != (size - 1)) endresult.append(",");
	}
	endresult.append("]");
	return endresult;
}

