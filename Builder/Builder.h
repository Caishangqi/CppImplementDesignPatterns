#pragma once
/**
 * The Builder interface specifies methods for creating the different parts of
 * the Product objects.
 */
class Builder
{
public:
    virtual      ~Builder() = default;
    virtual void Reset() = 0;
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};
