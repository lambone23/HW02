#pragma once
#include "CAnimal.h"

class CDog : public CAnimal
{
public:
    virtual void makeSound() override;
    virtual void move() override;
    
    virtual void setType() override { animalType = EAnimalType::Dog; }
    virtual EAnimalType getType() override { return animalType; };

    CDog() { setType(); }

private:
    EAnimalType animalType;
};
