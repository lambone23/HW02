#pragma once
class CAnimal
{
public:
	virtual void makeSound() = 0;
	virtual void move() = 0;

    enum class EAnimalType
    {
        Dog,    // 0
        Cat,    // 1
        Cow,    // 2
        Wolf,   // 3
        Pig,    // 4
        Crow,   // 5
        Horse,  // 6
        Donkey, // 7
        Tiger,  // 8
        Chicken,// 9
        END
    };

    virtual void setType() = 0;
    virtual EAnimalType getType() = 0;

private:
    //EAnimalType type;
};

