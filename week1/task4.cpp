#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

enum Sex
{
    dummy = 0,
    Male,
    Female
};

struct Doctor
{
    char surname[32];
    int expirience;
    char hospitalName[64];
    Sex sex;

    void createDoctor()
    {
        int userInput;

        cout << "Enter Surname: ";
        cin.getline(surname,32);
        if(surname[0]>='a' && surname[0] <= 'z') surname[0] = surname[0] - ' '; //('a' - 'A')

        cout << "Enter years of expirience: ";
        cin >> expirience;
        while(expirience < 0)
        {
            cout << "Invalid value!" << "\nEnter years of expirience: ";
            cin >> expirience;
        }

        cin.ignore();

        cout << "Enter hospital name: ";
        cin.getline(hospitalName,64);

        cout << "Choose gender(1-Male; 2-Female): ";
        cin >> userInput;
        sex = (Sex)(userInput);

        cin.ignore();
    }

    void showDoctor()
    {
        cout << endl;
        cout << "Surname: " << surname << endl;
        cout << "Years of expirience: " << expirience << endl;
        cout << "Working at hospital: " << hospitalName << endl;
        if(sex == 1)   cout << "Gender: Male" << endl;
        else cout << "Gender: Female" << endl;
    }

    void changeHospital()
    {
        cout << endl << "Enter new hospital: ";
        char *newHospital = new char[64];
        cin.getline(newHospital,64);
        strcpy (hospitalName,newHospital);
        delete[] newHospital;
    }

    void changeSurname()
    {
        if(sex == 2)
        {
            cout << endl << "Enter new Surname: ";
            char *newSurname = new char[64];
            cin.getline(newSurname, 64);
            strcpy(surname, newSurname);
            if(surname[0]>='a' && surname[0] <= 'z') surname[0] = surname[0] - ' '; 
            delete[] newSurname;
        } else cout << "Males can't change their Surname! ";
    }
};

void sortByExpirience(Doctor doctors[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(doctors[i].expirience < doctors[j].expirience)
            {
                Doctor temp = doctors[i];
                doctors[i] = doctors[j];
                doctors[j] = temp;
            }
        }
    }

    cout << endl << "List of all the doctors by expirience:" << endl;
    for(int i = 0; i < size; i++)
    {
        doctors[i].showDoctor();
    }
}

const int MAX_SIZE = 10;

int main()
{
    Doctor doctor;
    doctor.createDoctor();
    doctor.showDoctor();
    doctor.changeHospital();
    doctor.changeSurname();
    doctor.showDoctor();

    Doctor doctors[MAX_SIZE];
    int n;
    cout << endl << "How many doctors would you like to add(MAX 10): ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        doctors[i].createDoctor();
    }
    
    cout << endl << "List of all the doctors:" << endl;
    for(int i = 0; i < n; i++)
    {
        doctors[i].showDoctor();
    }

    sortByExpirience(doctors, n);

    return 0;
}