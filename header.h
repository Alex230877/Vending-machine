#pragma once
#include <iostream>

class  Snack
{
public:
    Snack(const std::string& name);
    Snack(const std::string& name, int energy);
    Snack(const std::string& name, int energy, double price);

    ~Snack() = default;

    std::string getName() const;
    void setName(const std::string& name);

    int getEnergy() const;
    void setEnergy(int energy);

    double getPrice() const;
    void setPrice(double price);

private:
    std::string name;
    int energy;
    double price;
};

class SnackSlot
{
public:
    SnackSlot(short slotSize);
    ~SnackSlot();

    short getSize() const;
    short getSnackCount() const;
    void addSnack(Snack* snañk);
    void giveSnack();

private:
    short size;
    short snackCount;
    Snack** snacks;
};

class  VendingMachine
{
public:
    VendingMachine(int size);
    ~VendingMachine();

    int getSize() const;
    int getSnacksCount() const;
    int getEmptySlotsCount();
    void addSlot(SnackSlot* slot);
    void giveSnack();

private:
    int size;
    int slotCount;
    int freeSlots;
    int snacksCount;
    SnackSlot** slots;
};