#include "mage.h"

Mage::Mage(const std::string& name, State state, Race race, size_t accesoury_amount, size_t mana) : Character(name, state, race), accesoury_amount(accesoury_amount) {
    if (mana > max_mana) {
        throw exceptions::over_max_mana;
    }
    for (size_t i = 0; i < accesoury_amount; i++)
    {
        arr[i] = static_cast<accesoury>(i % 3);
    }
    
}

Mage::~Mage() {
    delete[] arr;
}

void Mage::set_mana(size_t i) {
    if (i > max_mana) {
        throw exceptions::over_max_mana;
    }
    mana = i;
}

size_t Mage::get_mana() const {
    return mana;
}

size_t Mage::get_accesoury_amount() const {
    return accesoury_amount;
}

Mage::accesoury Mage::get_accesoury(size_t index) {
    return arr[index];
}

void Mage::replace_accesoury(accesoury type, size_t index) {
    arr[index] = type;
}

Mage& Mage::operator=(const Mage& other) {
    if (this != &other) {
        delete[] arr;
        Character::operator=(other);
        mana = other.mana;
        accesoury_amount = other.accesoury_amount;
        arr = new accesoury[accesoury_amount];
        for (size_t i = 0; i < accesoury_amount; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Mage& other) {
    out << static_cast<const Character&>(other)  << " Mana: " << other.mana << " Accesoury amount: " << other.accesoury_amount << " Accesouries: ";
    for (size_t i = 0; i < other.accesoury_amount; i++) {
        switch (other.arr[i])
        {
        case Mage::accesoury::wand:
            out << "wand ";
            break;
        case Mage::accesoury::pond:
            out << "pond ";
            break;
        case Mage::accesoury::lock:
            out << "lock ";
            break;
        default:
            break;
        }
    }
    return out;
}

Mage::Mage(Mage&& other) : Character(std::move(other)), mana(std::move(other.mana)), accesoury_amount(std::move(other.accesoury_amount)) {
    arr = other.arr;
    other.arr = nullptr;
}