#pragma once
#include <iostream>
using namespace std;
template <typename T>
class DubleConnList
{
public:
	template <typename T>
	DubleConnList(T data)
	{
		firstElement = 0;
		add(data);
		lastElement = 0;
		cout << "Start constructor " << this << endl;

	}
	DubleConnList()
	{
		firstElement = 0;
		lastElement = 0;
		cout << "Start constructor " << this << endl;
	}
	~DubleConnList()
	{
		clear();
		cout << "Stard destructor " << this << endl;
	}

	void add(T data)
	{
		Element* new_element = new Element;
		new_element->data = data;
		new_element->ptrPrevElement = 0;
		new_element->ptrNextElement = 0;

		if (!lastElement)
		{
			firstElement = new_element;
		}
		else
		{
			lastElement->ptrNextElement = new_element;
			new_element->ptrPrevElement = lastElement;
		}
		lastElement = new_element;
	}
	void show()
	{
		if (!lastElement)
		{
			cout << "list empty" << endl;
			return;
		}

		Element* currnet_element = firstElement;
		cout << currnet_element->data << endl;

		while (currnet_element->ptrNextElement)
		{
			currnet_element = currnet_element->ptrNextElement;
			cout << currnet_element->data << endl;
		}
	}
	void reverse()
	{
		Element* rev = firstElement;
		while (rev)
		{
			swap(rev->ptrNextElement, rev->ptrPrevElement);
			rev = rev->ptrPrevElement;
		}
		swap(firstElement, lastElement);
	}
	void insert(T data, int index);
	void Void();
	void remove(int index);
	void clear();


	DubleConnList(const DubleConnList& other)
	{
		Element* current_element1 = other.firstElement; /* ������� ���������� ����� ���������� ���� Element(� ������� ���� 3 ��������� - 2 ��������� � ���������� ��� ������)
		� ����������� ���� ������ �� ������� ��������
		*/
		while (current_element1)
		{
			add(current_element1->data); // ����� �������� ������� ���������� � ������� ��������� ���� ����� ��� � � ������ ������� �� �������� ��� �� ������
			current_element1 = current_element1->ptrNextElement; // � ��������� ��� ������� �� ��������� �������, �� ��� ��� ���� ��� ������� �� ����� MULL.
		}
		std::cout << "start copy constructor " << this << std::endl;
	}
	void operator = (const DubleConnList& other) // � ������� �� ��������� ����������� �� ������� �������� ��� ��������� ��� ���� ����� ��������� � ���� ����� ��������
	{
		std::cout << "Start assignment operator " << std::endl;
		Element* current_element1 = other.firstElement;
		while (firstElement) 
		{
			lastElement = firstElement->ptrNextElement;
			delete firstElement;
			firstElement = lastElement;
		}
		while (current_element1) // ������������ �� ����������� ���������� ������ � �����
		{
			add(current_element1->data);
			current_element1 = current_element1->ptrNextElement;
		}
	}
	DubleConnList(DubleConnList&& other) noexcept // ���������� ������ � �������� ������ � ������������ ����������
	{
		Element* current_element1 = other.firstElement;
		while (current_element1)
		{
			add(current_element1->data); // ����� �������� ������� ���������� � ������� ��������� ���� ����� ��� � � ������ ������� �� �������� ��� �� ������
			current_element1 = current_element1->ptrNextElement; // � ��������� ��� ������� �� ��������� �������, �� ��� ��� ���� ��� ������� �� ����� MULL.
		}
		std::cout << "start move constructor " << this << std::endl;
		while (other.firstElement)
		{
			other.lastElement = other.firstElement->ptrNextElement;
			other.firstElement = nullptr; // other.firstElement = nullptr ����������� delete other.firstElement;
			other.firstElement = other.lastElement;
		}
	}
	void operator = (DubleConnList&& other) noexcept // �������� ������ � ���������� � ������� ����������, ���������� ������, � �������� ������������ ���������
	{
		std::cout << "Start move operator " << std::endl;
		Element* current_element1 = other.firstElement;
		while (firstElement)
		{
			lastElement = firstElement->ptrNextElement;
			delete firstElement;
			firstElement = lastElement;
		}
		while (current_element1)
		{
			add(current_element1->data); 
			current_element1 = current_element1->ptrNextElement; 
		}
		while (other.firstElement)
		{
			other.lastElement = other.firstElement->ptrNextElement;
			other.firstElement = nullptr; // other.firstElement = nullptr ����������� delete other.firstElement;
			other.firstElement = other.lastElement;
		}

	}
private: 
	struct Element
	{
		Element* ptrPrevElement;
		T data;
		Element* ptrNextElement;

	};
	void swap(Element*& a, Element*& b);
	Element* firstElement;
	Element* lastElement;

};

