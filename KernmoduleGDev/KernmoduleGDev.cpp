#include <iostream>
#include <string>
#include "Vector3.h"
#include <SFML/Graphics.hpp>
#include "List.h"
using namespace std;

int main()
{
    List<std::string> stringlist = List<std::string>();
    stringlist.add("MEH");
    stringlist.add("IS");
    stringlist.add("DA");
    stringlist.add("WORST");
    stringlist.add("BEST");
    stringlist.remove("WORST");
    std::cout << stringlist.toString();
}