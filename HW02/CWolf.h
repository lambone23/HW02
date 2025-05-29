#pragma once
#include "CAnimal.h"

class CWolf : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Wolf; }
    virtual EAnimalType getType() override { return animalType; };

    CWolf() { setType(); }

private:
    EAnimalType animalType;
};

