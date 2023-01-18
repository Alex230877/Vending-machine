#include "header.h"
#include <iostream>
using namespace std;

Snack::Snack(const std::string& namå)
{
	this->name = namå;
	this->energy = 0;
	this->price = 0;
}

Snack::Snack(const std::string& name, int energy)
{
	this->name = name;
	this->energy = energy;
	this->price = 0;
}

Snack::Snack(const std::string& name, int energy, double price)
{
	this->name = name;
	this->energy = energy;
	this->price = price;
}

string Snack::getName() const
{
	return name;
}

void Snack::setName(const std::string& name)
{
	this->name = name;
}

int Snack::getEnergy() const
{
	return energy;
}

void Snack::setEnergy(int energy)
{
	this->energy = energy;
}

void Snack::setPrice(double price)
{
	this->price = price;
}

double Snack::getPrice() const
{
	return price;
}


SnackSlot::SnackSlot(short slotSize)
{
	this->size = slotSize;
	this->snackCount = 0;
	this->snacks = new Snack * [size];
}

SnackSlot::~SnackSlot()
{
	delete[] snacks;
}

short SnackSlot::getSize() const
{
	return size;
}

short SnackSlot::getSnackCount() const
{
	return snackCount;
}

void SnackSlot::addSnack(Snack* snack)
{
	if (snackCount < size)
	{
		snacks[snackCount] = snack;
		++snackCount;
	}
}

void SnackSlot::giveSnack()
{
	if (snackCount > 0)
	{
		--snackCount;
	}
}

VendingMachine::VendingMachine(int size)
{
	this->size = size;
	this->freeSlots = size;
	this->slotCount = 0;
	this->snacksCount = 0;
	this->slots = new SnackSlot * [size];
}

VendingMachine::~VendingMachine()
{
	delete[] slots;
}

int VendingMachine::getSize() const
{
	return size;
}

int VendingMachine::getSnacksCount() const
{
	return snacksCount;
}

int VendingMachine::getEmptySlotsCount()
{
	return freeSlots;
}

void VendingMachine::addSlot(SnackSlot* slot)
{
	slots[slotCount] = slot;
	--freeSlots;
	++slotCount;
	snacksCount += slot->getSnackCount();
}

void VendingMachine::giveSnack()
{
	--snacksCount;
	slots[slotCount - 1]->giveSnack();
	if (slots[slotCount - 1]->getSnackCount() == 0)
	{
		++freeSlots;
	}
}