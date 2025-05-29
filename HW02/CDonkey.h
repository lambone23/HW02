#pragma once
#include "CAnimal.h"

class CDonkey : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Donkey; }
    virtual EAnimalType getType() override { return animalType; };

    CDonkey() { setType(); }

private:
    EAnimalType animalType;
};
