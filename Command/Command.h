#include "GraphReceiver.h"

class GraphCommand
{
public:
    GraphCommand(std::shared_ptr<GraphReceiver> receiver): receiver(receiver) {};
    virtual ~GraphCommand() = default;
    virtual void Execute() = 0;

protected:
    std::shared_ptr<GraphReceiver> receiver;
};

class DrawCommand : public GraphCommand
{
    void Execute() override
    {
        receiver->ActionDraw();
    }
};

class ClearCommand : public GraphCommand
{
    void Execute() override
    {
        receiver->ActionClear();
    }
};

class ZoomInCommand : public GraphCommand
{
    void Execute() override
    {
        receiver->ActionZoomIn();
    }
};

class ZoomOutCommand : public GraphCommand
{
    void Execute() override
    {
        receiver->ActionZoomOut();
    }
};