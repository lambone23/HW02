#pragma once
#include "CAnimal.h"

class CChicken : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Chicken; }
    virtual EAnimalType getType() override { return animalType; };

    CChicken() { setType(); }

private:
    EAnimalType animalType;
};

