#pragma once
#include "CAnimal.h"

class CHorse : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Horse; }
    virtual EAnimalType getType() override { return animalType; };

    CHorse() { setType(); }

private:
    EAnimalType animalType;
};

