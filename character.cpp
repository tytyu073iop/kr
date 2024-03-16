#include "сharacter.h"
#include <string>
#include <iostream>

int Character::idCounter = 0;
int Character::amount = 0;

void Character::makeMove() {
    std::cout << "moved" << '\n';
}

Character::Character(std::string name, State state, Race race) : id(idCounter++), name(name), state(state), race(race) {
    amount++;
}

Character::Character(const Character& other) : Character(other.name, other.state, other.race) {

}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        // std::static_cast<int>(id) = other.id;
        name = other.name;
        state = other.state;
        // race = other.race;
        // *this = Character(other);
        // return *this;
    }
    return *this;
}

int Character::getId() const {
    return id;
}

std::string Character::getName() const {
    return name;
}

Character::State Character::getState() const {
    return state;
}

Character::Race Character::getRace() const {
    return race;
}

void Character::setName(std::string n) {
    name = n;
}

void Character::setState(State s) {
    state = s;
}

std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << "id: " << c.id << ", name: " << c.name << ", state: ";
    switch (c.state) {
        case Character::State::normal:
            os << "normal";
            break;
        case Character::State::paralysed:
            os << "paralysed";
            break;
        case Character::State::dead:
            os << "dead";
            break;
    }
    os << ", race: ";
    switch (c.race) {
        case Character::Race::human:
            os << "human";
            break;
        case Character::Race::elf:
            os << "elf";
            break;
        case Character::Race::dwarf:
            os << "dwarf";
            break;
    }
    return os;
}

bool Character::operator<(const Character& other) const {
    return name < other.name;
}

Character::~Character() {
    amount--;
}

int Character::getAmount() const
{
    return amount;
}

Character::Character(Character&& other) : id(std::move(other.id)), name(std::move(other.name)), state(std::move(other.state)), race(std::move(other.race)) {

}