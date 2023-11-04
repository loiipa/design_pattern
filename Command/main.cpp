#include "GraphInvoker.h"

// class GraphCommandqueue
// {
// private:
//     std::queue<std::shared_ptr<GraphCommand>> command;
// };

int main()
{
    auto receiver = std::make_shared<GraphReceiver>();

    auto drawCommand = std::make_shared<DrawCommand>(receiver);
    auto clearCommand = std::make_shared<ClearCommand>(receiver);
    auto zoomInCommand = std::make_shared<ZoomInCommand>(receiver);
    auto zoomOutCommand = std::make_shared<ZoomOutCommand>(receiver);

    auto invokerA = std::make_shared<GraphInvoker>(drawCommand);
    invokerA->Invoke();

    auto invokerB = std::make_shared<GraphInvoker>(clearCommand);
    invokerB->Invoke();

    auto invokerC = std::make_shared<GraphInvoker>(zoomInCommand);
    invokerC->Invoke();

    auto invokerD = std::make_shared<GraphInvoker>(zoomOutCommand);
    invokerD->Invoke();
};

