#pragma once
#include "сharacter.h"

class Mage : public Character {
public:
    enum class accesoury {
        wand,
        pond,
        lock
    };
    enum class exceptions {
        over_max_mana
    };
    Mage(const std::string& name, State state, Race race, size_t accesoury_amount, size_t mana = 0);
    virtual ~Mage();
    void set_mana(size_t mana);
    size_t get_mana() const;
    size_t get_accesoury_amount() const;
    accesoury get_accesoury(size_t index);
    void replace_accesoury(accesoury type, size_t index);
    Mage& operator=(const Mage& other);
    friend std::ostream& operator<<(std::ostream& out, const Mage& other);
    Mage(Mage&& other);
private:
    const size_t max_mana = 100;
    size_t mana;
    size_t accesoury_amount;
    accesoury* arr = new accesoury[accesoury_amount];
};