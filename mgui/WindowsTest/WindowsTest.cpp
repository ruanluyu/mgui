// WindowsTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../mgui-core/UUIDObject.h"



using namespace mgui;

void log_behaviour(std::string c, LogLevel level)
{
    switch (level)
    {
    case mgui::LOGLV_INFO:
        std::cout << "[Info]" << std::endl;
        break;
    case mgui::LOGLV_HINT:
        std::cout << "[Hint]" << std::endl;
        break;
    case mgui::LOGLV_WARNING:
        std::cout << "[Warning]" << std::endl;
        break;
    case mgui::LOGLV_ERROR:
        std::cout << "[Error]" << std::endl;
        break;
    default:
        break;
    }
    std::cout << c << std::endl << std::endl;
}


int main()
{
    SetLogger(Logger{ log_behaviour });

    {
        auto obj1 = UUIDObject::Create<UUIDObject>();
        auto obj2 = UUIDObject::Create<UUIDObject>();

        obj2->SetParent(obj1);

        obj1->SetName("obj1");
        obj2->SetName("obj2");


        UUIDObject::Finalize(obj1);
    }

    std::string s;
    std::cin >> s;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
