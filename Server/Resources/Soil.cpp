#include "../Headers/Soil.h"

Soil::Soil(int &soilNumber, float &soilResistivity)
{
    switch(soilNumber)
    {
        case SoilName::Coarse_sand:
            m_name = "Coarse sand";
            break;
        case SoilName::Medium_sand:
            m_name = "Medium sand";
            break;
        case SoilName::Fine_sand:
            m_name = "Fine sand";
            break;
        case SoilName::Silty_sand:
            m_name = "Silty sand";
            break;

        default:
            break;
    }

    m_soilResistivity = soilResistivity;
}