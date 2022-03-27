#pragma once
class Beer
{
private:
    char* name;
    int mil;

    void copy(const Beer& other);
    void erase();
public:
    void setName(const char* name);
    void setMil(int mil);

    const char* getName() const;
    int  getMil() const;

    Beer();
    Beer(const char* name, int mil);
    Beer(const Beer& other);
    ~Beer();

    void addBeer(Beer& other, int mil);
    bool check(const char* brand)const;

    void print() const;
};