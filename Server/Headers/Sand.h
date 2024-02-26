#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Soil.h"
#include "SoilData.h"

class Sand : public Soil
{
public:
    Sand(int &soilNumber, float& soilResistivity);

    std::string GetName() override;
    float GetSoilResistivity() override;
    float PorosityCoefficient() override;

//    float SpecificAdhesion() override;
//    float FirstSpecificAdhesion() override;
//    float SecondSpecificAdhesion() override;
//
//    float AngleInternalFriction() override;
//    float FirstAngleInternalFriction() override;
//    float SecondAngleInternalFriction() override;

    //так вроде лучше
    float SoilProperty(int &property, int &soilNumber) override;
    float FirstSoilProperty(int &property) override;
    float SecondSoilProperty(int &property) override;
};
