#include "Goods.h"
#include <ostream>
#include <string>
using namespace std;


Goods::Goods()
{
	title = " ";
	dataOfRegister = new Date(0, 0, 0);
	quantity = new int(0);
	numberOfDoc = new int(0);
	price = new Money(0, 0);
	
}

Goods::Goods(Money price, string title, Date dataOfRegister, int quantity, int numberOfDoc)
{
	this->title = title;
	this->dataOfRegister = new Date(dataOfRegister);
	this->quantity = new int (quantity);
	this->numberOfDoc = new int (numberOfDoc);
	this->price = new Money(*price.getRub(), *price.getCop());
}

Goods::Goods(const Goods& other)
{
	this->title = other.title;
	this->dataOfRegister = new Date(*other.dataOfRegister);
	this->quantity = new int(*other.quantity);
	this->numberOfDoc = new int(*other.numberOfDoc);
	this->price = new Money(*other.price->getRub(), *other.price->getCop());
}

Goods& Goods::operator=(const Goods& other)
{
	if (&other != this)
	{
		this->title = other.title;
		*this->dataOfRegister = *other.dataOfRegister;
		*this->quantity = *other.quantity;
		*this->numberOfDoc = *other.numberOfDoc;
		*this->price = *other.price;
	}
	return *this;
}

Goods::~Goods()
{
	price = nullptr;
	delete price;
	dataOfRegister = nullptr;
	delete dataOfRegister;
	quantity = nullptr;
	delete quantity;
	numberOfDoc = nullptr;
	delete numberOfDoc;
}

void Goods::changeThePrice(int rub, int cop)
{
	*this->price = Money(rub, cop);
}

void Goods::changeTheQuantity(int a)
{
	*this->quantity += a;
}

double Goods::toCost()
{
	double totalCost = (*quantity) * (*this->price->getRub() + (*this->price->getCop()) / 100.0);
	return totalCost;
}

string Goods::toSString()
{
	string str = "стоимость товара: " + to_string(toCost());
	return str;
}


void Goods::markDown(Date date)
{
	int overdueDays = date.daysBetween(*dataOfRegister);
	if (overdueDays > 0)
	{
		double discountFactor = 1 - (overdueDays * 0.01); 
		int totalCents = *price->getRub() * 100 + *price->getCop();
		totalCents = (int)(totalCents * discountFactor);

 		int newRub = totalCents / 100;
		int newCop = totalCents % 100;
		changeThePrice(newRub, newCop);
	}
}

ostream& operator<<(ostream& out, const Goods& other)
{
	out << "Наименование товара: " << other.title << "\n" <<
		"Цена товара: " << *other.price << '\n' <<
		"Дата регистрации: " << other.dataOfRegister->day << "."
		<< other.dataOfRegister->month << "." << other.dataOfRegister->year << "\n" <<
		"Количество: " << *other.quantity << "\n" <<
		"Номер документа: " << *other.numberOfDoc << "\n";
	return out;
}
