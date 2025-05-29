#include <iostream>
#include <cstdlib>
#include <ctime>

#include "CAnimal.h"
#include "CDog.h"
#include "CCat.h"
#include "CCow.h"
#include "CWolf.h"
#include "CPig.h"
#include "CCrow.h"
#include "CHorse.h"
#include "CDonkey.h"
#include "CTiger.h"
#include "CChicken.h"

#define EXIT 999

class Zoo;
void fnAdd(Zoo* _zoo, CAnimal* _animal);

class Zoo
{
private:
    CAnimal* animals[10]; // 동물 객체를 저장하는 포인터 배열

public:
    /*
        동물을 동물원에 추가하는 함수
        Animal 객체의 포인터를 받아 포인터 배열에 저장.
        같은 동물이라도 여러 번 추가될 수 있다.
        입력 매개변수 : Animal* (추가할 동물 객체)
        반환값 : 없음
    */
    void addAnimal(CAnimal* animal)
    {
        for (int idx = 0; idx < 10; idx++)
        {
            if (nullptr == animals[idx])
            {
                animals[idx] = animal;

                std::cout << std::endl;
                CAnimal::EAnimalType type = animal->getType();
                switch (type)
                {
                case CAnimal::EAnimalType::Dog:
                    std::cout << "Dog 개";
                    break;
                case CAnimal::EAnimalType::Cat:
                    std::cout << "Cat 고양이";
                    break;
                case CAnimal::EAnimalType::Cow:
                    std::cout << "Cow 소";
                    break;
                case CAnimal::EAnimalType::Wolf:
                    std::cout << "Wolf 늑대";
                    break;
                case CAnimal::EAnimalType::Pig:
                    std::cout << "Pig 돼지";
                    break;
                case CAnimal::EAnimalType::Crow:
                    std::cout << "Crow 소";
                    break;
                case CAnimal::EAnimalType::Horse:
                    std::cout << "Horse 말";
                    break;
                case CAnimal::EAnimalType::Donkey:
                    std::cout << "Donkey 당나귀";
                    break;
                case CAnimal::EAnimalType::Tiger:
                    std::cout << "Tiger 호랑이";
                    break;
                case CAnimal::EAnimalType::Chicken:
                    std::cout << "Chicken 닭";
                    break;
                case CAnimal::EAnimalType::END:
                    break;
                default:
                    break;
                }
                std::cout << "\t추가 완료!" << std::endl;
                break;
            }
        }
    }

    /*
        동물원에 있는 모든 동물의 행동을 수행하는 함수
        모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행.
        입력 매개변수 : 없음
        반환값 : 없음
    */
    void performAction()
    {
        int cnt = 0;
        for (int idx = 0; idx < 10; idx++)
        {
            if (nullptr != animals[idx])
            {
                cnt++;
                std::cout << idx + 1 << "번\t: ";
                animals[idx]->makeSound();  // 소리내기
                animals[idx]->move();       // 움직이기
            }
        }

        if (0 == cnt)
        {
            std::cout << "\n현재 동물원은 비어있습니다." << std::endl;
            std::cout << "동물을 추가하여 동물원을 채워보세요.\n" << std::endl;
        }
    }

    /*
        Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제.
        메모리 누수 방지하기 위해 동적 할당된 Animal 객체를 'delete'
        입력 매개변수 : 없음
        반환값 : 없음
    */
    ~Zoo()
    {
        for (int idx = 0; idx < 10; idx++)
        {
            if (nullptr != animals[idx])
            {
                delete animals[idx];
            }
        }
        //delete animals;
    }

    /*
        랜덤 동물을 생성하는 함수
        - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
        - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
        - 입력 매개변수: 없음
        - 반환값: Animal* (생성된 동물 객체의 포인터)
    */
    CAnimal* createRandomAnimal()
    {
        // 난수 생성
        static bool seeded = false;
        if (!seeded)
        {
            srand(static_cast<unsigned int>(time(0)));
            seeded = true;
        }
        int numb = rand() % 3; // 0, 1, 2

        CAnimal::EAnimalType type = static_cast<CAnimal::EAnimalType>(numb);
        switch (type)
        {
        case CAnimal::EAnimalType::Dog:
            return new CDog();
        case CAnimal::EAnimalType::Cat:
            return new CCat();
        case CAnimal::EAnimalType::Cow:
            return new CCow();
        default:
            return nullptr;
        }
    }

    // 생성자
    Zoo()
    {
        for (int idx = 0; idx < 10; idx++)
        {
            animals[idx] = nullptr;
        }
    }

    // 동물 수 구하기
    int getCntAnimals()
    {
        int returnValue = 0;
        for (int idx = 0; idx < 10; idx++)
        {
            if (nullptr != animals[idx])
            {
                returnValue++;
            }
        }
        return returnValue;
    }

    // 출력
    void printAnimals()
    {
        int cnt = 0;
        for (int idx = 0; idx < 10; idx++)
        {
            if (nullptr != animals[idx])
            {
                cnt++;
                CAnimal::EAnimalType type = (*(animals[idx])).getType();
                std::cout << idx + 1 << "번\t: ";
                switch (type)
                {
                case CAnimal::EAnimalType::Dog:
                    std::cout << "Dog 개" << std::endl;
                    break;
                case CAnimal::EAnimalType::Cat:
                    std::cout << "Cat 고양이" << std::endl;
                    break;
                case CAnimal::EAnimalType::Cow:
                    std::cout << "Cow 소" << std::endl;
                    break;
                case CAnimal::EAnimalType::Wolf:
                    std::cout << "Wolf 늑대" << std::endl;
                    break;
                case CAnimal::EAnimalType::Pig:
                    std::cout << "Pig 돼지" << std::endl;
                    break;
                case CAnimal::EAnimalType::Crow:
                    std::cout << "Crow 소" << std::endl;
                    break;
                case CAnimal::EAnimalType::Horse:
                    std::cout << "Horse 말" << std::endl;
                    break;
                case CAnimal::EAnimalType::Donkey:
                    std::cout << "Donkey 당나귀" << std::endl;
                    break;
                case CAnimal::EAnimalType::Tiger:
                    std::cout << "Tiger 호랑이" << std::endl;
                    break;
                case CAnimal::EAnimalType::Chicken:
                    std::cout << "Chicken 닭" << std::endl;
                    break;
                case CAnimal::EAnimalType::END:
                    break;
                default:
                    break;
                }
            }
        }

        if (0 == cnt)
        {
            std::cout << "\n현재 동물원은 비어있습니다." << std::endl;
            std::cout << "동물을 추가하여 동물원을 채워보세요.\n" << std::endl;
        }
    }//END-void printAnimals()
};

int main()
{
    //_CrtSetBreakAlloc(157);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //=============================
    // 필수 기능
    //=============================
    std::cout << "필수 기능" << std::endl;
    CAnimal* animalArr[3];
    animalArr[0] = new CDog;
    animalArr[1] = new CCat;
    animalArr[2] = new CCow;

    for (int idx = 0; idx < 3; idx++)
    {
        animalArr[idx]->makeSound();
        std::cout << std::endl;
    }

    for (int idx = 0; idx < 3; idx++)
    {
        delete animalArr[idx];
    }

    //=============================
    // 도전 기능
    //=============================
    std::cout << std::endl << "★★★★★ 도전 기능 ★★★★★" << std::endl;

    Zoo* myZoo = new Zoo;

    /*
         Debug - ERROR - C4703
         초기화되지 않았을 수 있는 로컬 포인터 변수 'myAnimal'이(가) 사용되었습니다.
     */
    CAnimal* myAnimal = new CDog;

    std::cout << "Welcome to the zoo!" << std::endl;
    while (true)
    {
        std::cout << "========== MyZoo ==========" << std::endl;
        std::cout << "동물 현황 확인\t: (숫자 0)" << std::endl;
        std::cout << "동물 추가\t: (숫자 1)" << std::endl;
        std::cout << "동물 행동 수행\t: (숫자 2)" << std::endl;
        std::cout << "종료를 원하면 (숫자 999)를 입력하세요." << std::endl;
        std::cout << "입력 : ";
        int input = 0;
        std::cin >> input;

        // 동물원 탈출
        if (EXIT == input)
        {
            break;
        }

        if (0 == input)
        {// 동물 현황 확인
            myZoo->printAnimals();
        }
        else if (1 == input)
        {// 동물 추가

            // 현재 채워진 동물 수 확인하여 추가.
            int cnt = myZoo->getCntAnimals();

            if (10 <= cnt)
            {
                std::cout << "\n수용량 초과\n더이상 추가할 수 없습니다.\n" << std::endl;
            }
            else
            {
                fnAdd(myZoo, myAnimal);
            }
        }
        else if (2 == input)
        {// 동물 행동 수행
            myZoo->performAction();
        }
    }
    std::cout << "========== 종료 ==========" << std::endl;

    delete myZoo;
    delete myAnimal;

    _CrtDumpMemoryLeaks();
    return 0;
}

// 동물 추가 전처리
void fnAdd(Zoo* _zoo, CAnimal* _animal)
{
    int cnt = _zoo->getCntAnimals();

    while (10 > cnt)
    {
        std::cout << "\n< 동물 추가 >"
            << "\n추가하려는 동물 앞의 숫자를 입력하세요."
            << "\n현재 동물 현황 : " << cnt << " / 10"
            << "\n--------------------"
            << "\n[0] : Dog\t개"
            << "\n[1] : Cat\t고양이"
            << "\n[2] : Cow\t소"
            << "\n[3] : Wolf\t늑대"
            << "\n[4] : Pig\t돼지"
            << "\n[5] : Crow\t까마귀"
            << "\n[6] : Horse\t말"
            << "\n[7] : Donkey\t당나귀"
            << "\n[8] : Tiger\t호랑이"
            << "\n[9] : Chicken\t닭"
            << "\n--------------------"
            << "\n랜덤으로 동물을 추가하려면 (숫자 100)을 입력하세요."
            << "\n동물 추가를 종료하려면 (숫자 999)를 입력하세요."
            << std::endl;
        std::cout << "입력 : ";
        int input = 0;
        std::cin >> input;

        // 추가 로직 탈출
        if (EXIT == input)
        {
            break;
        }

        // 랜덤
        if (100 == input)
        {
            _animal = _zoo->createRandomAnimal();
        }

        CAnimal::EAnimalType type = CAnimal::EAnimalType::END;
        type = static_cast<CAnimal::EAnimalType>(input);

        switch (type)
        {
        case CAnimal::EAnimalType::Dog:
            _animal = new CDog();
            break;
        case CAnimal::EAnimalType::Cat:
            _animal = new CCat();
            break;
        case CAnimal::EAnimalType::Cow:
            _animal = new CCow();
            break;
        case CAnimal::EAnimalType::Wolf:
            _animal = new CWolf();
            break;
        case CAnimal::EAnimalType::Pig:
            _animal = new CPig();
            break;
        case CAnimal::EAnimalType::Crow:
            _animal = new CCrow();
            break;
        case CAnimal::EAnimalType::Horse:
            _animal = new CHorse();
            break;
        case CAnimal::EAnimalType::Donkey:
            _animal = new CDonkey();
            break;
        case CAnimal::EAnimalType::Tiger:
            _animal = new CTiger();
            break;
        case CAnimal::EAnimalType::Chicken:
            _animal = new CChicken();
            break;
        case CAnimal::EAnimalType::END:
            break;
        }

        // 추가
        _zoo->addAnimal(_animal);

        cnt = _zoo->getCntAnimals();

        if (10 <= cnt)
        {
            std::cout << "수용량 초과\n더이상 추가할 수 없습니다.\n" << std::endl;
        }
    }//END-while (true)
}//END-void fnAdd(Zoo _zoo)
