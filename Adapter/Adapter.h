#pragma once
#include "common.h"
#include "Adaptee.h"
#include "Target.h"
/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
#ifdef USE_SINGLE_INHERITANCE
class Adapter : public Target
{
private:
    Adaptee* m_adaptee = nullptr;

public:
    Adapter(Adaptee* adaptee) : m_adaptee(adaptee)
    {
    }

    std::string Request() const override
    {
        std::string to_reverse = this->m_adaptee->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};
#endif

#ifdef USE_MULTIPLE_INHERITANCE
class Adapter : public Target, public Adaptee
{
public:
    Adapter()
    {
    }

    std::string Request() const override
    {
        std::string to_reverse = SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter requested: " + to_reverse;
    }
};
#endif
