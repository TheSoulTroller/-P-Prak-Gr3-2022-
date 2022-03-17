#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

enum Pet
{
    dummy = 0,
    Dog,
    Cat,
    Rabbit
};

struct Animal
{
    Pet pet;
    char name[32];
    int age;
    char sex;

    void createPet()
    {
        int userInput;
        cout << "\n1.Dog" << "\n2.Cat" << "\n3.Rabbit" << endl;
        cout << "Choose Pet: ";
        cin >> userInput;
        pet = (Pet)(userInput);

        cout << "Pet's name: ";
        cin.ignore();
        cin.getline(name,32);

        cout << "Pet's age: ";
        cin >> age;
        while(age < 0)
        {
            cout << "Age must be a non-negative number!" << "\nPet's age: ";
            cin >> age;       
        }

        cout << "Pet's gender(M/F): ";
        cin >> sex;
        while (sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f')
        {
            cout << "Gender can only be Male or Female!" <<  "\nPet's sex: ";
            cin >> sex;
        }
        
    }
    
    const char* enumToStr(Pet pet)
    {
        switch (pet)
        {
        case 1: return "Dog";
        case 2: return "Cat";
        case 3: return "Rabbit";
        default: return "Invalid value!";
        }
    }

    void printPet()
    {
        cout << endl << "Type of Pet: " << enumToStr(pet) << endl;
        cout << "Pet's name: " << name << endl;
        cout << "Pet's age: " << age << endl;
        cout << "Pet's gender: " << sex << endl;
    }

    int strToEnum(const char* str)
    {
        cout << str << endl;
        if(str == "Dog") return 1;
        if(str == "Cat") return 2;
        if(str == "Rabbit") return 3;

        return 0;   
    }

    void petToBinary(char* path)
    {
        std::ofstream out(path,std::ios::binary | std::ios::app);
        if(!out.is_open()) return;
        if(!out) return;

        out.write((char*)&pet, sizeof(pet));
        out.write(name, sizeof(name));
        out.write((char*)&age, sizeof(age));
        out.write((char*)&sex, sizeof(sex));

        out.close();
    }

    void binaryToPet()
    {
        std::ifstream in("pets.bin",std::ios::binary);
        if(!in.is_open()) return;
        if(!in) return;

        in.read((char*)&pet, sizeof(pet));
        in.read(name,sizeof(name));
        in.read((char*)&age,sizeof(age));
        in.read((char*)&sex ,sizeof(sex));

        in.close();
    }

};

struct ZooMag
{
    char shopName[32];
    Animal pets[10];
    int currPets;

    void createZooMag()
    {
        cout << "ZooShop name: ";
        cin.ignore();
        cin.getline(shopName,32);
        cout << "Enter currnet number of pets in the shop: ";
        cin >> currPets;
        while(currPets < 0)
        {
            cout << "Number of pets must be non-negative!" << "\nEnter currnet number of pets in the shop: ";
            cin >> currPets;
        }
    }

    void addPetToArr()
    {
        if(currPets == 10) 
        {
            cout << "Not enough space in the array!";
            return;
        }

        Animal addAnimal;
        addAnimal.createPet();
        pets[currPets].pet = addAnimal.pet;
        strcpy(pets[currPets].name, addAnimal.name);
        pets[currPets].age = addAnimal.age;
        pets[currPets].sex = addAnimal.sex;

        currPets++;
    }

    void getInfo(char name[32], Pet pet)
    {
        for(int i = 0; i < currPets; i++)
        {
            if(strcmp(name,pets[i].name) == 0 && pets[i].pet == pet) pets[i].printPet();
        }
    }

    void addArrToBinary(char* path)
    {
        for(int i = 0; i < currPets; i++)
        {
            pets[i].petToBinary(path);
        }
    }
   
};


int main()
{
    
    return 0;
}
