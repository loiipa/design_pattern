#pragma once

#include "Component.h"
#include <memory>
#include <iostream>

class Decorator : public Component
{
public:
    Decorator() = default;
    Decorator(std::unique_ptr<Component> component);
    virtual ~Decorator() = default;

    void Execute() override;

protected:
    std::unique_ptr<Component> wrappee;
};

Decorator::Decorator(std::unique_ptr<Component> component)
    : wrappee(std::move(component))
{

}


void Decorator::Execute()
{
    std::cout << "Base Decorator\n";
    
    if (wrappee != nullptr)
        wrappee->Execute();
}