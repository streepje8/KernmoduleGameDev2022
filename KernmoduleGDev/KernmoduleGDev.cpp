#include <iostream>
#include <string>
#include "Vector3.h"
using namespace std;

int main()
{
    Vector3 vector(1, 0, 0);
    Vector3 secondvector(0, 0, 1);
    string str("result: ");
    str.append((vector + secondvector).to_string());
    std::cout << str;
}