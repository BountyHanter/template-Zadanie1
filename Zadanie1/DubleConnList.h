//#ifndef TEMPLATE_FUNC_H
//#define TEMPLATE_FUNC_H

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
		// доходим до элемента который ДО удаляемого 
		Element* PrevDel = Del->ptrPrevElement;
		Element* AfterDel = Del->ptrNextElement;
		// обозначаем элементы После и ДО удаляемого
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
		Element* current_element1 = other.firstElement; /* ñîçäàåì âíóòðåííþþ íîâóþ ïåðåìåííóþ òèïà Element(â êîòîðîì åñòü 3 ïàðàìåòðà - 2 óêàçàòåëÿ è ñèìâîëüíûé òèï äàííûõ)
		è çàñîâûââàåì òóäà äàííûå èç ïåðâîãî ýëåìåíòà
		*/
		while (current_element1)
		{
			add(current_element1->data); // äàëåå âûçûâàåì ôóíêöèþ äîáàâëåíèÿ â êîòîðîì ïîâòîðÿåì òîæå ñàìîå ÷òî è ñ ïåðâûì ñïèñêîì íî êîïèðóåì ýòî âî âòîðîé
			current_element1 = current_element1->ptrNextElement; // è ïåðåíîñèì íàø ýëåìåíò íà ñëåäóþùèé ýëåìåíò, äî òåõ ïîð ïîêà íàø ýëåìåíò íå ðàâåí MULL.
		}
		std::cout << "start copy constructor " << this << std::endl;
	}
	void operator = (const DubleConnList& other) // â îòëè÷èè îò êîíñòðóêòîðà êîïèðîâàíèÿ ìû ñíà÷àëà çà÷èùàåì íàø êîíòåéíåð äëÿ òîãî ÷òîáû ïåðåíåñòè â íåãî íîâûå çíà÷åíèÿ
	{
		clear();
		std::cout << "Start assignment operator " << std::endl;
		Element* current_element1 = other.firstElement;
		while (current_element1) // ïåðåïèñûâàåì èç êîïèðóåìîãî êîíòåéíåðà äàííûå â íîâûé
		{
			add(current_element1->data);
			current_element1 = current_element1->ptrNextElement;
		}
	}
	DubleConnList(DubleConnList&& other) noexcept // ïåðåìåùàåì äàííûå è çà÷èùàåì äàííûå â ïåðåìåùàåìîì êîíòåéíåðå
	{
		firstElement = other.firstElement; // çäåñü ìû ïðîñòî ïåðåìåùàåì óêàçàòåëè, íå íóæíî çà÷èùàòü íè÷åãî
		lastElement = other.lastElement;
		other.firstElement = NULL; // à ñòàðûå óêàçàòåëè çàíóëÿåì
		other.lastElement = NULL;
	}
	void operator = (DubleConnList&& other) noexcept // çà÷èùàåì äàííûå ñ êîíòåéíåðà â êîòîðûé ïåðåìåùàåì, ïåðåìåùàåì äàííûå, è çà÷èùàåì ïåðåìåùàåìûé êîíòåéíåð
	{
		std::cout << "Start move operator " << std::endl; // çäåñü ìû òîëüêî çà÷èùàåì ïåðâîíà÷àëüíûé êîíòåéíåð, ïåðåìåùàåì óêàçàòåëè, à ñòàðûå óêàçàòåëè çàíóëÿåì
		clear();
		firstElement = other.firstElement;
		lastElement = other.lastElement;
		other.firstElement = NULL;
		other.lastElement = NULL;
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

//#endif // TEMPLATE_FUNC_H