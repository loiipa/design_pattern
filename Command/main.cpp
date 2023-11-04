#include "GraphInvoker.h"
#include <queue>

// invoker 대신해서 queue로 실행한다 가정 (main에는 미구현)
class GraphCommandqueue
{
public:
    void AddCommand(std::shared_ptr<GraphCommand> command)
    {
        commandQueue.push(command);
    }

    void ExecuteCommand(const std::shared_ptr<GraphCommand>& command)
    {
        commandQueue.front()->Execute();
        commandQueue.pop();
    }

private:
    std::queue<std::shared_ptr<GraphCommand>> commandQueue;
};

int main()
{
    std::shared_ptr<GraphReceiver> receiver = std::make_shared<GraphReceiver>();

    // Command 정의
    std::shared_ptr<GraphCommand> drawCommand = std::make_shared<DrawCommand>(receiver);
    std::shared_ptr<GraphCommand> clearCommand = std::make_shared<ClearCommand>(receiver);
    std::shared_ptr<GraphCommand> zoomInCommand = std::make_shared<ZoomInCommand>(receiver);
    std::shared_ptr<GraphCommand> zoomOutCommand = std::make_shared<ZoomOutCommand>(receiver);

    // 특정 상황에서 invoker가 발동된다고 가정
    auto invokerA = std::make_shared<GraphInvoker>(drawCommand);
    invokerA->Invoke();

    auto invokerB = std::make_shared<GraphInvoker>(clearCommand);
    invokerB->Invoke();

    auto invokerC = std::make_shared<GraphInvoker>(zoomInCommand);
    invokerC->Invoke();

    auto invokerD = std::make_shared<GraphInvoker>(zoomOutCommand);
    invokerD->Invoke();
};

