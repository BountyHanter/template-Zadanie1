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
	void insert(T data, int index)
	{
		int i = 0;

		Element* Ins = firstElement;

		while (i < index)
		{
			if (Ins->ptrNextElement == 0)
				return;
			Ins = Ins->ptrNextElement;
			i++;
		}

		if (index < 1 || index > i + 1)
		{
			cout << "Incorrect position !!!\n";
			return;
		}
		if (index == i + 1)
		{
			add(data);
			return;
		}
		else if (index == 0)
		{
			Element* temp = new Element;

			temp->ptrPrevElement = 0;
			temp->data = data;
			temp->ptrNextElement = firstElement;

			if (firstElement != 0)
				firstElement->ptrPrevElement = temp;

			if (i == 0)
				firstElement = lastElement = temp;
			else
				firstElement = temp;
			return;
		}


		Element* PrevIns = Ins->ptrPrevElement;

		Element* temp = new Element;

		temp->data = data;

		if (PrevIns != 0 && PrevIns->ptrNextElement != 0)
			PrevIns->ptrNextElement = temp;

		temp->ptrNextElement = Ins;
		temp->ptrPrevElement = PrevIns;
		Ins->ptrPrevElement = temp;

	}
	void Void();
	void remove(int index)
	{
		int i = 0;

		Element* Ins = firstElement;

		while (i < index)
		{
			if (Ins->ptrNextElement == 0)
				break;
			Ins = Ins->ptrNextElement;
			i++;
		}
		if (index < 1 || index > i)
		{
			cout << "Incorrect position !!!\n";
			return;
		}

		int g = 0;
		Element* Del = firstElement;

		while (g < index)
		{
			Del = Del->ptrNextElement;
			g++;
		}
		// ������� �� �������� ������� �� ���������� 
		Element* PrevDel = Del->ptrPrevElement;
		Element* AfterDel = Del->ptrNextElement;
		// ���������� �������� ����� � �� ����������
		if (PrevDel != 0 && PrevDel->ptrNextElement != 0)
			PrevDel->ptrNextElement = AfterDel;
		if (AfterDel != 0)
			AfterDel->ptrPrevElement = PrevDel;

		if (index == 1)
			firstElement = AfterDel;
		if (index == i)
			lastElement = PrevDel;

		delete Del;

	}
	void clear()
	{
		while (firstElement)
		{
			lastElement = firstElement->ptrNextElement;
			delete firstElement;
			firstElement = lastElement;
		}
	}


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
	void swap(Element*& a, Element*& b)
	{
		{
			Element* c = b;
			b = a;
			a = c;
		}
	}
	Element* firstElement;
	Element* lastElement;
};

