#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
    slot->addSnack(bounty); //Добавляем батончик в слот
    slot->addSnack(snickers);
    VendingMachine* machine = new VendingMachine(5 /*Количество слотов для снеков*/);
    machine->addSlot(slot); // Помещаем слот обратно в аппарат

    cout << "Количество пустых слотов для снеков " << machine->getEmptySlotsCount() << endl; // Должно выводить количество пустых слотов для снеков

    cout << "Всего снеков в автомате " << machine->getSnacksCount() << endl;

    machine->giveSnack();
    machine->giveSnack();

    cout << "Количество пустых слотов для снеков " << machine->getEmptySlotsCount() << endl;

    cout << "Всего снеков в автомате " << machine->getSnacksCount() << endl;

    delete bounty;
    delete snickers;
    delete slot;
    delete machine;
    return 0;
}