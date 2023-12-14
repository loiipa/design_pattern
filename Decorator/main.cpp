#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

int main()
{
    {
        std::unique_ptr<Component> decoA = std::make_unique<ConcreteDecoratorA>();
        std::unique_ptr<Decorator> decoB = std::make_unique<ConcreteDecoratorB>(std::move(decoA));
        std::unique_ptr<ConcreteDecoratorA> decoC = std::make_unique<ConcreteDecoratorA>(std::move(decoB));
        std::unique_ptr<ConcreteDecoratorB> decoD = std::make_unique<ConcreteDecoratorB>(std::move(decoC));
        std::unique_ptr<Decorator> decoE = std::make_unique<Decorator>(std::move(decoD));
        std::unique_ptr<Component> decoF = std::make_unique<Decorator>(std::move(decoE));
        
        decoE->Execute();
    }

    {
        std::unique_ptr<Component> deco = std::make_unique<ConcreteDecoratorA>();
        deco = std::make_unique<ConcreteDecoratorB>(std::move(deco));
        deco = std::make_unique<Decorator>(std::move(deco));
        deco = std::make_unique<ConcreteDecoratorA>(std::move(deco));
        deco = std::make_unique<ConcreteDecoratorB>(std::move(deco));

        deco->Execute();
    }


    std::cout << "end\n";
}