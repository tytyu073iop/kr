#pragma once
#include <string>
#include <iostream>

class Character
{
public:
    enum class State {
        normal,
        paralysed,
        dead
    };
    enum class Race {
        human,
        elf,
        dwarf
    };
    void makeMove();
    Character(std::string name, State state, Race race);
    Character(const Character& other);
    Character& operator=(const Character& other);
    int getId() const;
    std::string getName() const;
    State getState() const;
    Race getRace() const;
    void setState(State state);
    void setName(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const Character& other);
    bool operator<(const Character& other) const;
    virtual ~Character();
    int getAmount() const;
    Character(Character&& other);
private:
    static int amount;
    static int idCounter;
    const int id;
    std::string name;
    State state;
    const Race race;
};
