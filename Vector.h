#pragma once
#include <initializer_list>
#include <ostream>
#include <iostream>
#include <sstream>
setlocale( LC_ALL, "RUS" );

namespace Miit::Vector
{
	template <typename T>
	class Vector final
	{
	public:
		/*
		@brief Èíèöèàëèçàöèÿ íîâîãî ýêçåìïëÿðà òèïà vector ñ ïîìîùüþ initializer_list
		@param list Ëèñò ñ ïîìîùüþ êîòîðãî áóäåò ñîçäàí vector
		*/
		
		Vector(const std::initializer_list<T> list);

		/*
		@brief Óäàëÿåò, ÷èñòèò ïàìÿòü ïîñëå âåêòîðà
		*/
		~Vector();

		/*
		@brief Ïîëó÷åíèå êîëëè÷åñòâà ýëåìåíòîâ â âåêòîðå
		@return Êîëëè÷åñòâî ýëåìåíòîâ â âåêòîðå
		*/
		T getSize() const;

		/*
		@brief Óäàëåíèå ýëåìåíòà èç âåêòîðà ïî èíäåêñó ýëåìåíòà
		@param index Èíäåêñ ýëåìåíòà
		*/


		void deleteI(size_t index);

		/*
		@brief Ïîëó÷åíèå èíäåêñà ýëåìåíòà â âåêòîðå
		@param value Ýëåìåíò êîòîðûé ìû èùåì
		@return Èíäåêñ ýëåìåíòà â âåêòîðå, âåðíåò -1, åñëè ýëåìåíòà â âåêòîðå íåò
		*/
		size_t findI(T value) const;

		/*
		@brief Ïðîâåðêà íà îòñóòñòâèå ýëåìåíòîâ â âåêòîðå
		@return true åñëè ýëåìåíòîâ íåò è false åñëè îíè åñòü
		*/
		bool isEmpty() const noexcept;

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà êâàäðàòíûõ ñêîáîê
		@param index Èíäåêñ ýëåìåíòà â âåêòîðå
		@return Ýëåìåíò èç âåêòîðà ïî çàäàííîìó èíäåêñó
		*/
		T& operator[](size_t index);

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà êîïèðîâàíèÿ
		@param Vector Âåêòîð êîòîðûé áóäåò ñêîïèðîâàí
		@return Ñêîïèðîâàííûé Vector
		*/
		Vector& operator=(const Vector& vector);

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà ïåðåìåùåíèÿ
		@param Vector Âåêòîð äëÿ ïåðåìåùåíèÿ
		@return Âåêòîð
		*/
		Vector& operator=(Vector&& vector);

		/*
		@brief Ïåðåãðóçêà êîíñòðóêòîðà ïåðåìåùåíèÿ
		@param vector Âåêòîð äëÿ ïåðåìåùíèÿ
		*/
		Vector(const Vector& vector);

		/*
		@brief Ïåðåãðóçêà êîíñòðóêòîðà êîïèðîâàíèÿ
		@param vector Âåêòîð äëÿ êîïèðîâàíèÿ
		*/
		Vector(Vector&& vector);

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà âûâîäà
		@param os Ïîòîê âûâîäà
		@param vector Âåêòîð äëÿ âûâîäà
		*/
		friend std::ostream& operator<<(std::ostream& os, Vector& vector);

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà ðàâíî
		@param rha Ïåðâûé àðãóìåíò äëÿ ñðàâíåíèÿ
		@param lha Âòîðîé àðãóìåíò äëÿ ñðàâíåíèÿ
		@return false - åñëè ðàâíû, true - åñëè íå ðàâíû
		*/
		friend bool operator==(const Vector& rha, const Vector& lha);

		/*
		@brief Ïåðåãðóçêà îïåðàòîðà íå ðàâíî
		@param rha Ïåðâûé àðãóìåíò äëÿ ñðàâíåíèÿ
		@param lha Âòîðîé àðãóìåíò äëÿ ñðàâíåíèÿ
		@return true - åñëè ðàâíû, false - åñëè íå ðàâíû
		*/
		friend bool operator!=(const Vector& rha, const Vector& lha);

		/*
		@brief Ïðåîáðàçîâàíèå îáúåòà â ñòðîêó
		@return Ñòðîêà èç îáúåêòà
		*/
		std::string toString() const noexcept

	private:
		size_t size;
		T* array;

	};
	template <typename T>
	Miit::Vector::Vector<T>::Vector(const std::initializer_list<T> list)
		:size(list.size())
	{
		this->array = new int[this->size];
		std::copy(list.begin(), list.end(), this->array);
	}

	template <typename T>
	Miit::Vector::Vector<T>::~Vector()
	{
		delete[] this->array;
	}

	template <typename T>
	T Miit::Vector::Vector<T>::getSize() const
	{
		return this->size;
	}

	template <typename T>
	bool Miit::Vector::Vector<T>::isEmpty() const
	{
		return this->size == 0;
	}

	template <typename T>
	Miit::Vector::Vector<T>& Miit::Vector::Vector<T>::operator=(const Vector& vector)
	{
		if (vector == *this)
		{
			return *this;
		}
		if (!this->isEmpty())
		{
			delete[] this->array;
			this->array = nullptr;
			this->size = 0;
		}
		this->array = new T[this->size];
		std::copy(vector.array, vector.array + vector.size, this->array);
		return *this;
	}

	template <typename T>
	Miit::Vector::Vector<T>& Miit::Vector::Vector<T>::operator=(Vector&& vector) noexcept
	{
		std::swap(vector.array, this->array);
		std::swap(vector.size, this->size);
		return *this;
	}

	template <typename T>
	Miit::Vector::Vector<T>::Vector(const Vector& vector)
		:size(vector.getSize()), array(nullptr)
	{
		std::copy(vector.array, vector.array + vector.getSize(), this->array);
	}

	template <typename T>
	Miit::Vector::Vector<T>::Vector(Vector&& vector) noexcept
		:size(0), array(nullptr)
	{
		std::swap(vector.array, this->array);
		std::swap(vector.size, this->size);
	}

	template <typename T>
	T& Miit::Vector::Vector<T>::operator[](T index)
	{
		if (this->isEmpty() || index >= this->size or index < 0)
		{
			throw std::out_of_range("Incorrect Index");
		}
		return this->array[index];
	}

	template <typename T>
	void Miit::Vector::Vector<T>::deleteI(T index)
	{
		if (this->size == 0 or index < 0 or index >= this->size)
		{
			throw std::out_of_range("Incorrect Index");
		}
		T* vector1 = new int[this->size - 1];
		T now = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			if (i != index)
			{
				vector1[now] = this->array[i];
				now++;
			}
		}
		delete[] this->array;
		this->array = vector1;
		this->size--;
	}

	template <typename T>
	T Miit::Vector::Vector<T>::findI(T value) const
	{
		if (this->isEmpty())
		{
			return -1;
		}
		T index = 0;
		while ((index < this->size) && this->array[index] != value)
		{
			index++;
		}
		if (index == this->size)
		{
			return -1;
		}
		else
		{
			return index;
		}
	}

	template <typename T>
	std::string Miit::Vector::Vector<T>::toString() const noexcept
	{
		std::stringstream sstring;
		for (size_t i = 0; i < this->size; i++)
		{
			sstring << this->array[i] << " ";
		}
		return sstring.str();
	}


	template <typename T>
	bool operator==(const Miit::Vector::Vector<T>& rha, const Miit::Vector::Vector<T>& lha) noexcept
	{
		return (rha.toString() == lha.toString());
	}

	template <typename T>
	bool operator!=(const Miit::Vector::Vector<T>& rha, const Miit::Vector::Vector<T>& lha) noexcept
	{
		return !(rha == lha);
	}
};
