#pragma once
#include <iostream>
#include <string>

class Prototype
{
protected:
    std::string m_prototypeName;
    float       m_prototypeField = 0;

public:
    Prototype()
    {
    }

    Prototype(std::string prototypeName): m_prototypeName(prototypeName)
    {
    }

    virtual            ~Prototype() = default;
    virtual Prototype* Clone() const = 0;

    virtual void Method(float prototypeField)
    {
        m_prototypeField = prototypeField;
        std::cout << "Call Method from " << m_prototypeName << " with field : " << m_prototypeField << '\n';
    }
};
