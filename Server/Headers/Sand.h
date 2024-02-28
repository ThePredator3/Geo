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
    float SoilProperty(int &property, int &soilNumber) override;
    float FirstSoilProperty(int &property) override;
    float SecondSoilProperty(int &property) override;
};
