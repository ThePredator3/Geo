#pragma once

#include <vector>
#include <string>

struct SoilData
{
    SoilData(const std::string& soilName, const float&  resistivity, const float& porosityCoefficient,
             const float& specificAdhesion, const float& firstSpecificAdhesion, const float& secondSpecificAdhesion,
             const float& angleInternalFriction, const float& firstAngleInternalFriction,
             const float& secondAngleInternalFriction)
    {
        this->soilName = soilName;
        this->resistivity = resistivity;
        this->porosityCoefficient = porosityCoefficient;
        this->specificAdhesion = specificAdhesion;
        this->firstSpecificAdhesion = firstSpecificAdhesion;
        this->secondSpecificAdhesion = secondSpecificAdhesion;
        this->angleInternalFriction = angleInternalFriction;
        this->firstAngleInternalFriction = firstAngleInternalFriction;
        this->secondAngleInternalFriction = secondAngleInternalFriction;
    }

//    SoilData& operator += (const std::string& str)
//    {
//        soilName += str;
//        return *this;
//    }

    std::string Dump() const
    {
        std::string result = soilName + ";";
        result += std::to_string(resistivity) + ";";
        result += std::to_string(porosityCoefficient) + ";";
        result += std::to_string(specificAdhesion) + ";";
        result += std::to_string(firstSpecificAdhesion) + ";";
        result += std::to_string(secondSpecificAdhesion) + ";";
        result += std::to_string(angleInternalFriction) + ";";
        result += std::to_string(firstAngleInternalFriction) + ";";
        result += std::to_string(secondAngleInternalFriction) + ";";

        return result;
    }

    std::string soilName{};
    float resistivity{};
    float porosityCoefficient{};
    float specificAdhesion{};
    float firstSpecificAdhesion{};
    float secondSpecificAdhesion{};
    float angleInternalFriction{};
    float firstAngleInternalFriction{};
    float secondAngleInternalFriction{};
};

struct SandDataStaticProbing
{
public:
    //нормативные значения коэффициента фильтрации (e) в зависимости от удельного сопротивления грунта (qs)
    std::vector<std::vector<float>> porosityCoefficient = {
            {1, 2, 3, 5, 10, 15, 20, 30, 50},
            {0.82, 0.74, 0.70, 0.64, 0.58, 0.53, 0.50, 0.46, 0.41} };

    //Нормативные значения удельного сцепления (cn) для четырех видов песка
    //Первая строка - нормативные значения удельного сопротивления грунта (qs)
    //(немного другое деление в отличие от массива выше)
    std::vector<std::vector<float>> specificAdhesion = {
            { 1, 2, 3, 5, 8, 10, 15, 20, 30, 31 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.001, 0.001, 0.002, 0.002 },
            { 0.0, 0.0, 0.0, 0.001, 0.001, 0.002, 0.002, 0.002, 0.003, 0.003 },
            { 0.0, 0.0, 0.001, 0.002, 0.002, 0.003, 0.004, 0.004, 0.005, 0.006 },
            { 0.0, 0.002, 0.003, 0.004, 0.004, 0.005, 0.006, 0.006, 0.007, 0.008 } };

    //Нормативные значения угла внутреннего трения (fn) для четырех видов песка
    //Первая строка - нормативные значения удельного сопротивления грунта (qs)
    //(немного другое деление в отличие от массива выше)
    std::vector<std::vector<float>> angleInternalFriction = {
            { 1, 2, 3, 5, 8, 10, 15, 20, 30, 31 },
            { 30, 32, 34, 36, 38, 39, 40, 41, 42, 43 },
            { 28, 30, 32, 35, 36, 37, 38, 38, 39, 40 },
            { 26, 29, 30, 32, 34, 35, 36, 36, 37, 38 },
            { 24, 26, 28, 30, 32, 33, 34, 34, 35, 36 } };
};

//struct  SandDataWithoutProbing
//{
//
//};