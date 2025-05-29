#pragma once
#include "CAnimal.h"

class CCrow : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Crow; }
    virtual EAnimalType getType() override { return animalType; };

    CCrow() { setType(); }

private:
    EAnimalType animalType;
};

