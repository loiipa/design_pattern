#include "Command.h"

class GraphInvoker
{
public:
    GraphInvoker(std::shared_ptr<GraphCommand> command): command(command) {};
    void Invoke()
    {
        command->Execute();
    }
private:
    std::shared_ptr<GraphCommand> command;
};