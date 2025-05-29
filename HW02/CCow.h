#pragma once
#include "CAnimal.h"

class CCow : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Cow; }
    virtual EAnimalType getType() override { return animalType; };

    CCow() { setType(); }

private:
    EAnimalType animalType = EAnimalType::Cow;
};

