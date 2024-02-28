#include "Headers/Sand.h"

const int ANGLE_INTERNAL_FRICTION = 0;
const int SPECIFIC_ADHESION = 1;

Sand::Sand(int &soilNumber, float &soilResistivity) :
    Soil(soilNumber, soilResistivity) {}

std::string Sand::GetName()
{
    return m_name;
}

float Sand::GetSoilResistivity()
{
    return m_soilResistivity;
}

float Sand::PorosityCoefficient()
{
    int min{ 0 };
    int max{ 0 };

    SandDataStaticProbing sandData;

    if (m_soilResistivity > sandData.porosityCoefficient[0][8])
    {
        m_soilResistivity = sandData.porosityCoefficient[0][8];
    }
    else if (m_soilResistivity < sandData.porosityCoefficient[0][0])
    {
        m_soilResistivity = sandData.porosityCoefficient[0][0];
    }

    for (int i = 0; i < 9; i++)
    {
        if (m_soilResistivity >= sandData.porosityCoefficient[0][i])
        {
            min = i;
            max = i + 1;
        }
    }

    float minSoilResistivity = sandData.porosityCoefficient[0][min];
    float maxSoilResistivity = sandData.porosityCoefficient[0][max];
    float minPorosityCoefficient = sandData.porosityCoefficient[1][max];
    float maxPorosityCoefficient = sandData.porosityCoefficient[1][min];

    m_porosityCoefficient = minPorosityCoefficient + (maxPorosityCoefficient - minPorosityCoefficient) /
            (maxSoilResistivity - minSoilResistivity) * (maxSoilResistivity - m_soilResistivity);

    return m_porosityCoefficient;
}

float Sand::SoilProperty(int &property, int &soilNumber)
{
    int min{ 0 };
    int max{ 0 };

    SandDataStaticProbing sandData;
//    SoilName soilName{};

    std::vector<std::vector<float>> data;

    switch (property)
    {
        case ANGLE_INTERNAL_FRICTION:
            data = sandData.angleInternalFriction;
            break;
        case SPECIFIC_ADHESION:
            data = sandData.specificAdhesion;
            break;
        default:
            return 0;
    }

    if (m_soilResistivity > data[0][9])
    {
        m_soilResistivity = data[0][9];
    }
    else if (m_soilResistivity < data[0][0])
    {
        m_soilResistivity = data[0][0];
    }

    for (int i = 0; i < 10; i++)
    {
        if (m_soilResistivity >= data[0][i])
        {
            min = i;
            max = i + 1;
        }
    }

    float minSoilResistivity = data[0][min];
    float maxSoilResistivity = data[0][max];
    float minSoilProperty = data[soilNumber][min];
    float maxSoilProperty = data[soilNumber][max];

    float soilProperty = minSoilProperty + (maxSoilProperty - minSoilProperty) /
                                           (maxSoilResistivity - minSoilResistivity) *
                                           (maxSoilResistivity - m_soilResistivity);

    switch (property)
    {
        case ANGLE_INTERNAL_FRICTION:
            m_angleInternalFriction = soilProperty;
            break;
        case SPECIFIC_ADHESION:
            m_specificAdhesion = soilProperty;
            break;
        default:
            return 0;
    }

    return soilProperty;
}

float Sand::FirstSoilProperty(int &property)
{
    switch (property)
    {
        case ANGLE_INTERNAL_FRICTION:
            m_firstAngleInternalFriction = m_angleInternalFriction / 1.1f;
            return m_firstAngleInternalFriction;
        case SPECIFIC_ADHESION:
            m_firstSpecificAdhesion = m_specificAdhesion / 1.5f;
            return m_firstSpecificAdhesion;
        default:
            return 0;
    }
}

float Sand::SecondSoilProperty(int &property)
{
    switch (property)
    {
        case ANGLE_INTERNAL_FRICTION:
            m_secondAngleInternalFriction = m_angleInternalFriction;
            return m_secondAngleInternalFriction;
        case SPECIFIC_ADHESION:
            m_secondSpecificAdhesion = m_specificAdhesion / 1.1f;
            return m_secondSpecificAdhesion;
        default:
            return 0;
    }
}

