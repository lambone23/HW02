#pragma once
#include "CAnimal.h"

class CPig : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Pig; }
    virtual EAnimalType getType() override { return animalType; };

    CPig() { setType(); }

private:
    EAnimalType animalType;
};

