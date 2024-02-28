#pragma once

#include <string>

#include <QtNetwork>

class Soil
{
public:
    //песок крупный, средний, мелкий, пылеватый
    enum SoilName
    {
        Coarse_sand = 1,
        Medium_sand,
        Fine_sand,
        Silty_sand
    };

    Soil(int &soilNumber, float& soilResistivity);

protected:
    virtual std::string GetName() = 0;
    virtual float GetSoilResistivity() = 0;
    virtual float PorosityCoefficient() = 0; //e коэффициент фильтрации (e), м/сут
    virtual float SoilProperty(int &property, int &soilNumber) = 0; //обобщенная функция для cn, fn и всего, что сюда подходит
    virtual float FirstSoilProperty(int &property) = 0;
    virtual float SecondSoilProperty(int &property) = 0;

    std::string m_name{ "no name" }; //название грунта
    float m_soilResistivity{ -1 }; //qs удельное сопротивление грунта
    float m_porosityCoefficient{ - 1 }; //e_sand porosityCoefficient расчетное значение коэффициента фильтрации

    float m_specificAdhesion{ - 1 }; //cn_sand расчетное значение удельного сцепления (cn), МПа
    float m_firstSpecificAdhesion{ - 1 }; //cn_I
    float m_secondSpecificAdhesion{ - 1 }; //cn_II

    float m_angleInternalFriction{ -1 }; //fn_sand расчетное значение угла внутреннего трения (fn), д.ед
    float m_firstAngleInternalFriction{ -1 }; //fn_I
    float m_secondAngleInternalFriction{ -1 }; //fn_II

private:
    Soil() = default;
};
