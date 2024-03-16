#include "сharacter.h"
#include "mage.h"

int main() {
    Character test("ilya", Character::State::normal, Character::Race::dwarf);
    std::cout << "getName: " << test.getName() << std::endl;
    std::cout << "getState: ";
    switch (test.getState()) {
        case Character::State::normal:
            std::cout << "normal" << std::endl;
            break;
        case Character::State::dead:
            std::cout << "dead" << std::endl;
            break;
        case Character::State::paralysed:
            std::cout << "paralysed" << std::endl;
            break;
    }
    std::cout << "getRace: ";
    switch (test.getRace()) {
        case Character::Race::dwarf:
            std::cout << "dwarf" << std::endl;
            break;
        case Character::Race::elf:
            std::cout << "elf" << std::endl;
            break;
        case Character::Race::human:
            std::cout << "human" << std::endl;
            break;
    }
    std::cout << "getID: " << test.getId() << std::endl;
    std::cout << "test of <<: " << test << std::endl;
    Character test2(test);
    std::cout << "copy of test: " << test2 << std::endl;
    test.setName("van");
    test.setState(Character::State::dead);
    std::cout << "test after setting of name and state: " << test << std::endl;
    test2 = test;
    std::cout << "test2 after = test: " << test2 << std::endl;
    std::cout << "test < test2: " << (test < test2) << std::endl;
    std::cout << "test move: ";
    test.makeMove();
    std::cout << "get object amount: " << test.getAmount() << std::endl;
    std::cout << "\tmage test\n";
    Mage test3("mage", Character::State::normal, Character::Race::human, 3);
    std::cout << "test3: " << test3 << std::endl;
    std::cout << "GET mana: " << test3.get_mana() << std::endl;
    test3.makeMove();
    std::cout << "get_accesoury_amount: " << test3.get_accesoury_amount() << std::endl;
    test3.replace_accesoury(Mage::accesoury::wand, 2);
    std::cout << "test3 after replacing accesoury: " << test3 << std::endl;
    test3.set_mana(5);
    std::cout << "test3 after setting mana: " << test3.get_mana() << std::endl;
    Mage::accesoury i = test3.get_accesoury(1);
    switch (i)
        {
        case Mage::accesoury::wand:
            std::cout << "accesoury from 1 is " << "wand ";
            break;
        case Mage::accesoury::pond:
            std::cout << "accesoury from 1 is " << "pond ";
            break;
        case Mage::accesoury::lock:
            std::cout << "accesoury from 1 is " << "lock ";
            break;
        default:
            break;
        }
    std::cout << '\n';
    Mage test4("mage", Character::State::normal, Character::Race::human, 10, 3);
    std::cout << "test4: " << test4 << std::endl;
    test4 = test3;
    std::cout << "test4 after = test3: " << test4 << std::endl;
    auto test5(std::move(test3));
    std::cout << "test5 after move: " << test5 << std::endl;
    auto test6(std::move(test));
    std::cout << "test6 after move: " << test6 << std::endl;
    std::cout << "\ttask for 10\n";
    try {
        Mage test7("mage", Character::State::normal, Character::Race::human, 10, 110);
    } catch (...) {
        std::cout << "exception caught\n";
    }
    {
        const size_t N = 4;
        Character* arr[N];
        arr[0] = new Character("1", Character::State::normal, Character::Race::dwarf);
        arr[1] = new Character("2", Character::State::normal, Character::Race::dwarf);
        arr[2] = new Mage("3", Character::State::normal, Character::Race::dwarf, 3);
        arr[3] = new Mage("4", Character::State::normal, Character::Race::dwarf, 3, 20);
        {
            bool b = false;
            do {
                b = false;
                for (size_t i = 1; i < N; i++)
                {
                    if (arr[i - 1]->getName() > arr[i]->getName())
                    {
                        std::swap(arr[i - 1], arr[i]);
                        b = true;
                    }
                }
            } while (b);
        }
        {
            size_t c = 0, m = 0;
        for (int i = 0; i < N; i++) {
            std::cout << "arr[" << i << "]: is " << typeid(*arr[i]).name() << " info: ";
            if (typeid(*arr[i]) == typeid(Character)) {
                std::cout << (*arr[i]);
                c++;
            } else {
                std::cout << *(static_cast<Mage*>(arr[i]));
                m++;
            }
            std::cout << '\n' << "amount of Characters: " << c << " amount of mages: " << m << '\n';
        }
        }
        for (size_t i = 0; i < N; i++)
        {
            delete arr[i];
        }
        

    }
}