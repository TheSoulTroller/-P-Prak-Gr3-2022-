#include "String.h"

int main()
{
    // default constructor
    String str1;
    cout << "str1 -> " << str1 << endl;

    // parameterized constructor
    String str2("Hello");
    cout << "str2 -> " << str2 << endl;

    // copy constructor
    String str3(str2);
    cout << "str3 -> " << str3 << endl;

    // overloaded operator = 
    String str4 = str2;
    cout << "str4 -> " << str4 << endl;
    String str5 = "HelloWorldHelloEarth";
    cout << "str5 -> " << str5 << endl;

    // copyFromToIndex
    String str6 = str2.copyFromToIndex(1, 3);
    cout << "str6 -> " << str6 << endl;
    
    // lenght
    cout << "str6 lenght: " << str6.lenght() << endl;

    // hasSubstr
    cout << "str2.hasSubstr(str6): " << boolalpha << str2.hasSubstr(str6) << endl;

    // reverse
    cout << "Before reverse: \n" << str2 << endl;
    str2.reverse();
    cout << "After reverse: \n" << str2 << endl;

    // clearStr
    cout << "Before clearStr: " << str6 << endl;
    str6.clearStr();
    cout << "After clearStr: " << str6 << endl;

    // isEmpty
    bool checkStr6 = str6.isEmpty();
    bool checkStr2 = str2.isEmpty();
    cout << "str6 isEmpty: " << boolalpha << checkStr6 << endl;
    cout << "str2 isEmpty: " << boolalpha << checkStr2 << endl;

    // move constructor
    cout << "Before move constructor:\nstr5 -> " << str5 << endl;
    String str7(std::move(str5));
    cout << "After move constructor:\nstr7 -> " << str7 << endl;
    cout << "str5 -> " << str5 << endl;

    // replace
    str6 = "ell";
    cout << "Before replace str7 -> " << str7 << endl;
    cout << "str6 -> " << str6 << endl;
    cout << "str3 -> " << str3 << endl;
    str7.replace(str6,str3);
    cout << "After replace: " << str7 << endl;

    // // overloaded operators
    // bool checkEqual = str1 == str2;
    // bool checkNotEqual = str6 != str3;
    // bool checkLess = str3 < str6;
    // bool checkGreater = str7 > str2;
    // bool checkLessEqual = str2 <= str6;
    // bool checkGreaterEqual = str7 >= str3;
    // cout << "str1 == str2: " << boolalpha << checkEqual << endl;
    // cout << "str6 != str3: " << boolalpha << checkNotEqual << endl;
    // cout << "str3 < str6: " << boolalpha << checkLess << endl;
    // cout << "str7 > str2: " << boolalpha << checkGreater << endl;
    // cout << "str2 <= str6: " << boolalpha << checkLessEqual << endl;
    // cout << "str7 >= str3: " << boolalpha << checkGreaterEqual << endl;

    // overloaded operators +
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    String str8 = str2 + str3;
    cout << "str2 + str3 / str8: " << str8 << endl;

    // overloaded operators +=
    cout << "Before operator +=: " << str7 << endl;
    str7 += str3;
    cout << "After operator +=: " << str7 << endl;

    // overloaded operators -
    cout << "str7: " << str7 << endl;
    cout << "str3: " << str3 << endl;
    String str9 = str7 - str3;
    cout << "str7 - str3 / str9: " << str9 << endl;

    // overloaded operators -=
    cout << "Before operator -= \nstr7 -> " << str7 << endl;
    cout << "str6 -> " << str6 << endl;
    str7 -= str6;
    cout << "After operator -=: \nstr7-> " << str7 << endl;

    // overloaded operator []
    char ch = str8[0];
    cout << "str8[0] / operator []: " << ch << endl;

    // overloaded operator <<
    cout << "str1 -> " << str1 << endl;
    cout << "str2 -> " << str2 << endl;
    cout << "str3 -> " << str3 << endl;
    cout << "str4 -> " << str4 << endl;
    cout << "str5 -> " << str5 << endl;
    cout << "str6 -> " << str6 << endl;
    cout << "str7 -> " << str7 << endl;
    cout << "str8 -> " << str8 << endl;
    cout << "str9 -> " << str9 << endl;

    // overloaded operator >>
    String str10;
    cin >> str10;
    cout << str10 << endl;

    return 0;
}