#pragma once
#include "Template_vector.h"

template <class T>
class Queue
{
private:
	Template_vector<T> data;
public:
	// Очистка очереди
	void Clear() { data.Clear(); }

	// Работа с размером очереди
	int GetCount() const { return data.GetSize(); }
	bool IsEmpty() const { return data.isEmpty(); }

	// Добавление и удаление элементов
	void Add(const T& item);
	void Remove(T& item);
	void Peek(T& item);
};
template <class T>
void Queue<T>::Add(const T& item)
{
	data.Add(item);
}

template <class T>
void Queue<T>::Remove(T& item)
{
	if (!IsEmpty())
	{
		item = data[0];
		data.Remove(0);
		data.Add(item);
	}
	else
		item = 0;
}

template <class T>
void Queue<T>::Peek(T& item)
{
	if (!IsEmpty())
		item = data[0];
	else
		item = 0;
}
