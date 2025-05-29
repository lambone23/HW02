#pragma once
#include "CAnimal.h"

class CCat : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;

    virtual void setType() override { animalType = EAnimalType::Cat; }
    virtual EAnimalType getType() override { return animalType; };

    CCat() { setType(); }

private:
    EAnimalType animalType;
};
