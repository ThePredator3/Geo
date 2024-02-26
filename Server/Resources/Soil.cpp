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

/*
 // Обобщенная функция, которая вычисляет свойство почвы
float Sand::SoilProperty(int property)
{
    int min{ 0 };
    int max{ 0 };

    SandData sandData;
    SoilName soilName{};

    // Выбираем нужный массив данных в зависимости от свойства
    float** data;
    switch (property)
    {
    case 0: // Угол внутреннего трения
        data = sandData.angleInternalFriction;
        break;
    case 1: // Специфическая адгезия
        data = sandData.specificAdhesion;
        break;
    default:
        return 0; // Неверное свойство
    }

    // Проверяем границы сопротивляемости почвы
    if (m_soilResistivity > data[0][9])
    {
        m_soilResistivity = data[0][9];
    }
    else if (m_soilResistivity < data[0][0])
    {
        m_soilResistivity = data[0][0];
    }

    // Находим ближайшие значения сопротивляемости почвы
    for (int i = 0; i < 10; i++)
    {
        if (m_soilResistivity >= data[0][i])
        {
            min = i;
            max = i + 1;
        }
    }

    // Интерполируем значение свойства почвы
    float minSoilResistivity = data[0][min];
    float maxSoilResistivity = data[0][max];
    float minSoilProperty = data[soilName][min];
    float maxSoilProperty = data[soilName][max];

    float soilProperty = minSoilProperty + (maxSoilProperty - minSoilProperty) /
                                               (maxSoilResistivity - minSoilResistivity) *
                                               (maxSoilResistivity - m_soilResistivity);

    return soilProperty;
}

// Перегруженные функции, которые вызывают обобщенную функцию с разными параметрами
float Sand::AngleInternalFriction()
{
    return SoilProperty(0); // 0 - код для угла внутреннего трения
}

float Sand::SpecificAdhesion()
{
    return SoilProperty(1); // 1 - код для специфической адгезии
}

 */