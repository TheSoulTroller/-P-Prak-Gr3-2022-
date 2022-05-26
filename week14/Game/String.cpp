#include "String.h"

void String::copy(const String& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->symbols = new char[this->capacity];
    strcpy(this->symbols, other.symbols);
}
void String::resize()
{
    this->capacity *= 2;
    char* temp = new char[this->capacity];
    strcpy(temp, this->symbols);
    delete[] this->symbols;
    this->symbols = temp;
}
void String::downsize()
{
    if(this->size * 3 <= this->capacity)
    {
        this->capacity /= 2;
        char* temp = new char[this->capacity];
        strcpy(temp, this->symbols);
        delete[] this->symbols;
        this->symbols = temp;
    }
}
void String::erase()
{
    delete[] this->symbols;
}

String::String()
{
    this->symbols = new char[1];
    this->symbols[0] = '\0';
    this->size = 0;
    this->capacity = 1;
}
String::String(const char* source)
{
    this->size = strlen(source);
    this->capacity = this->size * 2;
    this->symbols = new char[this->capacity];
    strcpy(this->symbols, source);
}
String::String(const String& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->symbols = new char [this->capacity];
    strcpy(this->symbols, other.symbols);
}
String& String::operator=(const String& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
String& String::operator=(String&& other)
{
    if(this != &other)
    {
        this->erase();
        this->size = other.size;
        this->capacity = other.capacity;
        this->symbols = other.symbols;
        other.symbols = nullptr;
    }
    return *this;
}
String::~String()
{
    this->erase();
}

String String::copyFromToIndex(const int start, int end)
{
    if (start < 0 || end < 0)
    {
        throw std::invalid_argument("Start or end index is negative");
    }
    if (start > end)
    {
        throw std::invalid_argument("Start index is bigger than end index");
    }
    if (end > this->size)
    {
        throw std::invalid_argument("End index is bigger than string size");
    }

    String result;
    result.size = end - start + 1;
    result.capacity = result.size * 2;
    result.symbols = new char[result.capacity];
    for (int i = 0; i < result.size; i++)
    {
        result.symbols[i] = this->symbols[start + i];
    }
    result.symbols[result.size] = '\0';

    return result;
}
const int String::lenght() const
{
    return this->size;
}
bool String::hasSubstr(const String& find) const
{
    if (find.size > this->size)
    {
        throw std::invalid_argument("Substr is bigger than string");
    }

    bool flag;
    for (int i = 0; i < this->size - find.size + 1; i++)
    {
        flag = true;
        for (int j = 0; j < find.size; j++)
        {
            if (this->symbols[i + j] != find.symbols[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }

    return false;
}
void String::reverse()
{
    char temp;
    for(int i = 0; i < this->size / 2; i++)
    {
        temp = symbols[i];
        symbols[i] = symbols[this->size - i - 1];
        symbols[this->size - i - 1] = temp;
    }

    
}
void String::clearStr()
{
    this->erase();
    this->symbols = new char[1];
    this->symbols[0] = '\0';
    this->size = 0;
    this->capacity = 1;
}
bool String::isEmpty() const
{
    return this->size == 0;
}
String::String(String&& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->symbols = other.symbols;
    other.size = 0;
    other.capacity = 1;
    other.symbols = nullptr;
}
void String::replace(const String& find, const String& replace)
{
    if (this->symbols == nullptr)
    {
        throw std::logic_error("String is empty");
    }
    if (this->size < find.size)
    {
        throw std::invalid_argument("Find string is bigger than string");
    }

    if (!hasSubstr(find))
    {
        throw std::invalid_argument("String doesn't have substring");
    }

    int index = 0;
    int findIndex = 0;
    int replaceIndex = 0;
    int newSize = this->size;
    while (index < this->size)
    {
        if (this->symbols[index] == find.symbols[findIndex])
        {
            findIndex++;
            if (findIndex == find.size)
            {
                newSize -= find.size;
                newSize += replace.size;
                index += find.size;
                findIndex = 0;
                replaceIndex = 0;
                while (replaceIndex < replace.size)
                {
                    this->symbols[index] = replace.symbols[replaceIndex];
                    index++;
                    replaceIndex++;
                }
            }
        }
        else
        {
            index++;
            findIndex = 0;
        }
    } 
}

bool String::operator==(const String& other) const
{
    if (this->size != other.size)
    {
        return false;
    }

    for (int i = 0; i < this->size; i++)
    {
        if (this->symbols[i] != other.symbols[i])
        {
            return false;
        }
    }

    return true;
}
bool String::operator!=(const String& other) const
{
    return !(*this == other);
}
bool String::operator>(const String& other) const
{
    int i = 0;
    while(this->symbols[i] == other.symbols[i])
    {
        i++;
    }

    if (this->symbols[i] > other.symbols[i])
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}
bool String::operator<(const String& other) const
{
    return !(*this > other);
}
bool String::operator>=(const String& other) const
{
    return (*this > other) || (*this == other);
}
bool String::operator<=(const String& other) const
{
    return (*this < other) || (*this == other);
}

String String::operator+(const String& other)
{
    String result;
    result.size = this->size + other.size;
    result.capacity = result.size * 2;
    result.symbols = new char[result.capacity];
    strcpy(result.symbols, this->symbols);
    strcat(result.symbols, other.symbols);

    return result;
}
String& String::operator+=(const String& other)
{
    while (this->size + other.size >= this->capacity)
    {
        this->resize();
    }

    strcat(this->symbols, other.symbols);
    this->size += other.size;
    return *this;
}
String String::operator-(const String& find)
{
    if (this->size < find.size)
    {
        throw std::invalid_argument("Substr is bigger than string");
        return *this;
    }

    if (!hasSubstr(find))
    {
        throw std::invalid_argument("String doesn't have substring");
        return *this;
    }

    String result;
    result.size = this->size;
    result.capacity = this->capacity;
    result.symbols = new char[result.capacity];
    strcpy(result.symbols, this->symbols);

    int index = 0;
    int count = 0;
    while (index < result.size - find.size + 1)
    {
        if (result.symbols[index] == find.symbols[0])
        {
            bool flag = true;
            for (int i = 0; i < find.size; i++)
            {
                if (result.symbols[index + i] != find.symbols[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int i = index; i < result.size - find.size + 1; i++)
                {
                    result.symbols[i] = result.symbols[i + find.size];
                }
                result.size -= find.size;
                count++;
            }
            else
            {
                index++;
            }
        }
        else
        {
            index++;
        }
    }

    result.downsize();

    return result;
}
String& String::operator-=(const String& find)
{
    String result = *this - find;
    this->size = result.size;
    this->capacity = result.capacity;
    strcpy(this->symbols, result.symbols);
    return *this;
}
const char& String::operator[](int index) const
{
    if (index < 0 || index >= this->size)
    {
        throw std::invalid_argument("Index is out of range");
    }
    return this->symbols[index];
}
char& String::operator[](int index)
{
    if (index < 0 || index >= this->size)
    {
        throw std::invalid_argument("Index is out of range");
    }
    return this->symbols[index];
}
String& String::operator=(const char* source)
{
    this->size = strlen(source);
    this->capacity = this->size * 2;
    this->symbols = new char[this->capacity];
    strcpy(this->symbols, source);
    return *this;
}
std::ostream& operator<<(std::ostream& out, const String& str)
{
    if(str.symbols == nullptr)
    {
        out << "String is empty!" << endl;
    }
    else
    {
    out << str.symbols;
    }
    return out;
}
std::istream& operator>>(std::istream& in, String& str)
{
    const int buffSz = 16;
    char buff[buffSz];    
    str.size = 0;
    str.capacity = buffSz * 2;
    str.erase();
    str.symbols = new char[str.capacity];
    int iter = 0;

    while(in.get(buff, buffSz, '\n'))
    {
        if (iter == 0)
        {
            str.size = strlen(buff);
            strcpy(str.symbols, buff);
            iter++;
        }
        else
        {
            if (str.size + strlen(buff) >= str.capacity)
            {
                str.resize();
            }
            str.size += strlen(buff);
            strcat(str.symbols, buff);
        }
    }
    return in;
}