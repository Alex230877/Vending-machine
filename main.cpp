#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10/*���������� ����������, ������� ���������� � ����*/);
    slot->addSnack(bounty); //��������� �������� � ����
    slot->addSnack(snickers);
    VendingMachine* machine = new VendingMachine(5 /*���������� ������ ��� ������*/);
    machine->addSlot(slot); // �������� ���� ������� � �������

    cout << "���������� ������ ������ ��� ������ " << machine->getEmptySlotsCount() << endl; // ������ �������� ���������� ������ ������ ��� ������

    cout << "����� ������ � �������� " << machine->getSnacksCount() << endl;

    machine->giveSnack();
    machine->giveSnack();

    cout << "���������� ������ ������ ��� ������ " << machine->getEmptySlotsCount() << endl;

    cout << "����� ������ � �������� " << machine->getSnacksCount() << endl;

    delete bounty;
    delete snickers;
    delete slot;
    delete machine;
    return 0;
}