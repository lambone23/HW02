#pragma once
#include "CAnimal.h"

class CTiger : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Tiger; }
    virtual EAnimalType getType() override { return animalType; };

    CTiger() { setType(); }

private:
    EAnimalType animalType;
};

