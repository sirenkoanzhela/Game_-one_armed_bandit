#pragma once
#include <iostream>

template <typename T>
class Template_vector
{
	T* vect;
	int size;
public:
	Template_vector();
	Template_vector(int);
	Template_vector(const T*, int);
	Template_vector(const Template_vector&);
	Template_vector(Template_vector&&);
	~Template_vector();

	void Print();

	int getSize()const;
	void Input(const T&, int);
	void Clear();
	bool isEmpty()const;
	void Add(const T&);
	void Insert(int, const T&);
	void Remove(int);
	Template_vector& operator++();
	Template_vector operator++(int);
	Template_vector& operator--();
	Template_vector operator--(int);
	Template_vector& operator=(const Template_vector&);
	Template_vector& operator=(Template_vector&&);

	int& operator[](int);
	Template_vector operator+(const Template_vector&);
	Template_vector operator+(int);
	Template_vector& operator+=(const Template_vector&);
	Template_vector operator - (const Template_vector& v);
	Template_vector operator - (int);
	Template_vector& operator -= (const Template_vector& v);
	Template_vector operator * (const Template_vector& v);
	Template_vector operator * (int);
	Template_vector& operator *= (int);

	friend std::istream& operator>>(std::istream&, Template_vector&);
	friend std::ostream& operator<<(std::ostream&, Template_vector&);
};

template <typename T>
Template_vector<T>::Template_vector() : size(0), vect(nullptr) { }

template <typename T>
Template_vector<T>::Template_vector(int _size)
{
	size = _size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = 0;
	}
}

template <typename T>
Template_vector<T>::Template_vector(const T* ptr, int _size)
{
	size = _size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = ptr[i];
	}
}

template <typename T>
Template_vector<T>::Template_vector(const Template_vector& obj)
{
	size = obj.size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = obj.vect[i];
	}
}

template <typename T>
Template_vector<T>::Template_vector(Template_vector&& obj)
{
	vect = obj.vect;
	size = obj.size;
	obj.size = 0;
	obj.vect = nullptr;
}

template <typename T>
Template_vector<T>::~Template_vector()
{
	if (vect != nullptr)
	{
		delete[]vect;
	}
}

template <typename T>
void Template_vector<T>::Print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << vect[i] << std::endl;
	}
}

template <typename T>
int Template_vector<T>::getSize()const
{
	return size;
}

template <typename T>
void Template_vector<T>::Clear()
{
	delete[]vect;
	vect = nullptr;
	size = 0;
}

template <typename T>
bool Template_vector<T>::isEmpty()const
{
	if (vect == nullptr && size == 0) { return true; }
	return false;
}

template <typename T>
void Template_vector<T>::Input(const T& _size, int value)
{
	if (vect != nullptr) { delete[]vect; }
	size = _size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = value;
	}
}

template <typename T>
void Template_vector<T>::Add(const T& item)
{
	size += 1;
	T* temp = new T[size];
	int i = 0;
	for (i = 0; i < (size - 1); i++)
	{

		temp[i] = vect[i];
	}
	temp[i] = item;
	delete[]vect;
	vect = temp;
}

template <typename T>
void Template_vector<T>::Insert(int index, const T& item)
{
	size += 1;
	T* temp = new T[size];
	for (int i = 0; i < index; i++)
	{
		temp[i] = vect[i];
	}
	temp[index] = item;
	for (int i = (index + 1); i < size; i++)
	{
		temp[i] = vect[i - 1];
	}
	delete[]vect;
	vect = temp;
}

template <typename T>
void Template_vector<T>::Remove(int index)
{
	size -= 1;
	T* temp = new T[size];
	for (int i = 0; i < index; i++)
	{
		temp[i] = vect[i];
	}
	for (int i = index; i < size; i++)
	{
		temp[i] = vect[i + 1];
	}
	delete[]vect;
	vect = temp;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator++()
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = ++vect[i];
	}
	return *this;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator++(int k)
{
	Template_vector temp_vect;
	temp_vect.vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		temp_vect.vect[i] = vect[i];
		vect[i] = ++vect[i];
	}

	return temp_vect;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator--()
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = --vect[i];
	}
	return *this;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator--(int k)
{
	Template_vector temp_vect;
	temp_vect.vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		temp_vect.vect[i] = vect[i];
		vect[i] = --vect[i];
	}

	return temp_vect;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator=(const Template_vector& obj)
{
	if (this == &obj) { return *this; }
	delete[] this->vect;
	size = obj.size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = obj.vect[i];
	}
	return *this;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator=(Template_vector&& obj)
{
	vect = obj.vect;
	size = obj.size;
	obj.size = 0;
	obj.vect = nullptr;
	return *this;
}

template <typename T>
int& Template_vector<T>::operator[](int index)
{
	return vect[index];
}

template <typename T>
Template_vector<T> Template_vector<T>::operator+(const Template_vector& obj)
{
	Template_vector temp;
	int index = 0;
	temp.size = size + obj.size;
	temp.vect = new T[temp.size];
	for (int i = 0; i < size; i++)
	{
		temp.vect[i] = vect[i];
	}
	for (int i = size; i < temp.size; i++)
	{
		temp.vect[i] = obj.vect[index];
		index++;
	}
	return temp;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator+(int item)
{
	for (int i = 0; i < size; i++)
	{
		vect[i] += item;
	}
	return *this;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator+=(const Template_vector& obj)
{
	T* temp = new T[size + obj.size];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		temp[i] = vect[i];
	}
	for (int i = size; i < (size + obj.size); i++)
	{
		temp[i] = obj.vect[index];
		index++;
	}
	delete[]vect;
	vect = temp;
	size += obj.size;
	return *this;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator-(const Template_vector& obj)
{
	Template_vector temp;
	if (size == obj.size)
	{
		temp.size = size;
		temp.vect = new T[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			temp.vect[i] = vect[i] - obj.vect[i];
		}
		return temp;
	}
	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size > obj.size) { temp.size = size; }
		else temp.size = obj.size;

		temp.vect = new T[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			if (size > obj.size)
			{
				for (int i = 0; i < obj.size; i++)
				{
					temp.vect[i] = vect[i] - obj.vect[i];
				}
				for (int i = obj.size; i < temp.size; i++)
				{
					temp.vect[i] = vect[i];
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					temp.vect[i] = vect[i] - obj.vect[i];
				}
				for (int i = size; i < temp.size; i++)
				{
					temp.vect[i] = obj.vect[i];
				}
			}
		}
		return temp;
	}
	if (size == 0)
	{
		temp.vect = new T[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			temp.vect[i] = obj.vect[i];
		}
	}
	else
	{
		temp.vect = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp.vect[i] = vect[i];
		}
	}
	return temp;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator-(int value)
{
	Template_vector temp;
	temp.size = size;
	temp.vect = new T[temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		temp.vect[i] = vect[i] - value;
	}
	return temp;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator-=(const Template_vector& obj)
{
	if (size == obj.size)
	{
		for (int i = 0; i < size; i++)
		{
			vect[i] = vect[i] - obj.vect[i];
		}
		return *this;
	}
	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size < obj.size)
		{
			T* temp = new T[obj.size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = vect[i] - obj.vect[i];
			}
			for (int i = size; i < obj.size; i++)
			{
				temp[i] = obj.vect[i];
			}
			delete[]vect;
			vect = temp;
			return *this;
		}
		else if (obj.size < size)
		{
			T* temp = new T[size];
			for (int i = 0; i < obj.size; i++)
			{
				temp[i] = vect[i] - obj.vect[i];
			}
			for (int i = obj.size; i < size; i++)
			{
				temp[i] = vect[i];
			}
			delete[]vect;
			vect = temp;
			return *this;
		}
	}
	if (size == 0 && vect == nullptr)
	{
		size = obj.size;
		vect = new T[size];
		for (int i = 0; i < size; i++)
		{
			vect[i] = obj.vect[i];
		}
		return *this;
	}
	else if (obj.size == 0 && obj.vect == nullptr)
	{
		return *this;
	}
}

template <typename T>
Template_vector<T> Template_vector<T>::operator*(const Template_vector& obj)
{
	Template_vector temp;
	if (size == obj.size)
	{
		temp.size = size;
		temp.vect = new T[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			temp.vect[i] = vect[i] * obj.vect[i];
		}
		return temp;
	}

	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size > obj.size) { temp.size = size; }
		else temp.size = obj.size;

		temp.vect = new T[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			if (size > obj.size)
			{
				for (int i = 0; i < obj.size; i++)
				{
					temp.vect[i] = vect[i] * obj.vect[i];
				}
				for (int i = obj.size; i < temp.size; i++)
				{
					temp.vect[i] = vect[i];
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					temp.vect[i] = vect[i] * obj.vect[i];
				}
				for (int i = size; i < temp.size; i++)
				{
					temp.vect[i] = obj.vect[i];
				}
			}
		}
		return temp;
	}
	if (size == 0)
	{
		temp.vect = new T[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			temp.vect[i] = obj.vect[i];
		}
	}
	else
	{
		temp.vect = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp.vect[i] = vect[i];
		}
	}
	return temp;
}

template <typename T>
Template_vector<T> Template_vector<T>::operator*(int value)
{
	Template_vector temp;
	temp.size = size;
	temp.vect = new T[temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		temp.vect[i] = vect[i] * value;
	}
	return temp;
}

template <typename T>
Template_vector<T>& Template_vector<T>::operator*=(int value)
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] * value;
	}
	return *this;
}

template <typename T>
std::istream&  operator>>(std::istream& is, Template_vector<T>& obj)
{
	int size = 0;
	T item = 0;
	std::cout << "ENTER SIZE OF VECTOR" << std::endl;
	std::cin >> size;
	std::cout << "PUSH BACK" << std::endl;
	std::cin >> item;
	if (obj.vect != nullptr) { delete[]obj.vect; }
	obj.size = size;
	obj.vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		obj.vect[i] = item;
	}
	return is;
}

template <typename T>
std::ostream&  operator<<(std::ostream& os, Template_vector<T>& obj)
{
	obj.Print();
	return os;
}
