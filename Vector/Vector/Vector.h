#pragma once
#ifndef Vector_h
#define Vector_h
#include<iostream>
using namespace std;

template<class T>
class Vector
{
private:
	T *ptr;     // данные
	int cnt;   // размерность вектора
public:
	Vector(Vector& a)
	{
		ptr = new T[a.cnt];
		if (ptr == NULL)
			throw ("Не удалось выделить память");
		cnt = a.cnt;
		for (int i = 0; i < cnt; i++)
			ptr[i] = a.ptr[i];
	}

	Vector(int CountElem = 5)
	{
		ptr = new T[CountElem];
        if (ptr == NULL)
			throw ("Не удалось выделить память");
		cnt = CountElem;
	}
	~Vector()
	{
		delete[] ptr;
		cnt = 0;
	}

	int GetCnt()
	{
		return cnt;
	}

	int SetCnt(int& n)
	{
		T *tmp = new T[n];
		if (ptr == NULL)
			throw ("Не удалось выделить память");
		int k = n;
		if (cnt < n)
			k = cnt;
		for (int i = 0; i < k; i++)
			tmp[i] = ptr[i];
		delete[] ptr;
		ptr = tmp;
		cnt = n;
		return 1;

	}

	T GetPtr() // double *GetPtr()
	{
		return *ptr;
	}

	///int SetPtr(int n, double* newptr)
	int SetPtr(int n, T newptr)
	{
		if (n < 0 || n > cnt)
			return 0;
		ptr[n] = newptr;
		/*
				for (int i = 0; i < cnt; i++)
					ptr[i] = newptr[i];
			*/
		return 1;
	}

	int addElement(T newElement)
	{
		T *tmp;
		tmp = new T[cnt + 1];
		if (tmp == nullptr)
			return 0;
		for (int i = 0; i < cnt; i++)
			tmp[i] = ptr[i];
		tmp[cnt] = newElement;
		delete[]ptr;
		cnt++;
		ptr = tmp;
		return 1;
	}

	int DelElement(int indexDelElement)
	{
		T *tmp;
		int i;
		tmp = new T[cnt - 1];
		if (tmp == nullptr)
			return 0;
		for (i = 0; i < indexDelElement; i++)
			tmp[i] = ptr[i];
		for (i = indexDelElement + 1; i < cnt; i++)
			tmp[i - 1] = ptr[i];
		delete[]ptr;
		cnt--;
		ptr = tmp;
		return 1;
	}

	friend Vector operator+ (Vector& a, Vector& b)
	{
		if (a.cnt != b.cnt)
			throw("Операция невозможна");
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] + b.ptr[i];
		return v;
	}

	friend Vector operator+ (Vector& a, T& b)
	{
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		if (v.ptr == nullptr)
			throw ("Не удалось выделить память");
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] + b;
		return v;
	}

	friend Vector operator+ (T& b, const Vector<T>& a)
	{
		Vector<T> v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		if (v.ptr == NULL)
			throw ("Не удалось выделить память");
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = b + a.ptr[i];
		return v;
	}

	friend Vector operator- (Vector& a, Vector& b)
	{
		if (a.cnt != b.cnt)
			throw("Операция невозможна");
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] - b.ptr[i];
		return v;
	}

	/*
	   friend Vector operator- (Vector& a, double& b)
	   {
		   Vector v;
		   v.cnt = a.cnt;
		   v.ptr = new double[v.cnt];
		   if (v.ptr == nullptr)
			   throw ("Не удалось выделить память");
		   for (int i = 0; i < a.cnt; i++)
			   v.ptr[i] = a.ptr[i] - b;
		   return v;
	   }

	   friend Vector operator- (double& b, Vector& a)
	   {
		   return ((-1)*(a - b));
	   }
   */
	friend Vector operator* (Vector& a, Vector& b)
	{
		if (a.cnt != b.cnt)
			throw("Операция невозможна");
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] * b.ptr[i];
		return v;
	}

	friend Vector operator* (Vector& a, T& b)
	{
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		if (v.ptr == NULL)
			throw ("Не удалось выделить память");
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] * b;
		return v;
	}

	friend Vector operator* (T& b, Vector& a)
	{
		Vector<T> v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		if (v.ptr == NULL)
			throw ("Не удалось выделить память");
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = b * a.ptr[i];
		return v;
	}


	friend Vector operator/ (Vector& a, Vector& b)
	{
		if (a.cnt != b.cnt)
			throw("Операция невозможна");
		Vector v;
		v.cnt = a.cnt;
		v.ptr = new T[v.cnt];
		for (int i = 0; i < b.cnt; i++)
		{
			if (b.ptr[i] == 0)
				throw("Деление на ноль невозможно");
		}
		for (int i = 0; i < a.cnt; i++)
			v.ptr[i] = a.ptr[i] / b.ptr[i];
		return v;
	}



	Vector operator= (const Vector& b)
	{
		delete[]ptr;
		ptr = new T[b.cnt];
		cnt = b.cnt;
		for (int i = 0; i < cnt; i++)
			ptr[i] = b.ptr[i];
		return *this;

	}



	friend ostream& operator<<(ostream& o, Vector& a)
	{
		o << "\nVector[" << a.cnt << "] = ";
		for (int i = 0; i < a.cnt; i++)
			o << a.ptr[i] << ' ';
		return o;
	}

	friend istream& operator>>(istream& stream, Vector& a)
	{
		for (int i = 0; i < a.cnt; i++)
			stream >> a.ptr[i];
		return stream;
	}

};
#endif