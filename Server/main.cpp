#include <QCoreApplication>

#include "Headers/Server.h"

int main(int argc, char *argv[])
{

    QCoreApplication qCoreApplication(argc, argv);
    Server server;

    return qCoreApplication.exec();
}

//    std::cout << "Hello!" << std::endl;
//    std::cout << "My name is Geo!" << std::endl;
//    std::cout << std::endl;
//
//    //песок крупный, средний, мелкий, пылеватый
//    std::cout << "Types of soil: " << std::endl;
//    std::cout << "1 - Coarse sand,\n2 - Medium sand,\n3 - Fine sand,\n4 - Silty sand" << std::endl;
//    std::cout << std::endl;
//
//    // for client
//
//    int soilNumber{ -1 };
//    float soilResistivity{ 0 };
//
//    std::cout << "Enter the number of soil: ";
//    std::cin >> soilNumber;
//
//    std::cout << "Enter soil resistivity: ";
//    std::cin >> soilResistivity;
//
//    WorkWithSand(soilNumber, soilResistivity);