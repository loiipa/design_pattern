#pragma once

#include "Decorator.h"

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA() = default;
    ConcreteDecoratorA(std::unique_ptr<Component> component);

    virtual ~ConcreteDecoratorA() = default;

    void Execute() override;
};

ConcreteDecoratorA::ConcreteDecoratorA(std::unique_ptr<Component> component)
    : Decorator(std::move(component))
{

}

void ConcreteDecoratorA::Execute()
{
    std::cout << "Decorator A\n";

    if (wrappee != nullptr)
        wrappee->Execute();
}