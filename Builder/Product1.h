#pragma once
#include <string>
#include <vector>
/**
 * It makes sense to use the Builder pattern only when your products are quite
 * complex and require extensive configuration.
 *
 * Unlike in other creational patterns, different concrete builders can produce
 * unrelated products. In other words, results of various builders may not
 * always follow the same interface.
 */
class Product1
{
public:
    std::vector<std::string> m_parts;

    void ListParts() const
    {
        printf("Product parts: \n");
        for (int i = 0; i < (int)m_parts.size(); i++)
        {
            if (m_parts[i] == m_parts.back())
            {
                printf("%s\n", m_parts[i].c_str());
            }
            else
            {
                printf("%s, ", m_parts[i].c_str());
            }
        }
    }
};
