#pragma once

#include "Decorator.h"

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB() = default;
    ConcreteDecoratorB(std::unique_ptr<Component> component);

    virtual ~ConcreteDecoratorB() = default;

    void Execute() override;
};

ConcreteDecoratorB::ConcreteDecoratorB(std::unique_ptr<Component> component)
    : Decorator(std::move(component))
{

}

void ConcreteDecoratorB::Execute()
{
    std::cout << "Decorator B\n";
    
    if (wrappee != nullptr)
        wrappee->Execute();
}