#include "GraphReceiver.h"

class GraphCommand
{
public:
    virtual ~GraphCommand() = default;
    virtual void Execute() = 0;

protected:
    std::shared_ptr<GraphReceiver> receiver;
};

class DrawCommand : public GraphCommand
{
public:
    DrawCommand(const std::shared_ptr<GraphReceiver>& receiver)
    {
        this->receiver = receiver;
    }

    void Execute() override
    {
        receiver->ActionDraw();
    }
};

class ClearCommand : public GraphCommand
{
public:
    ClearCommand(const std::shared_ptr<GraphReceiver>& receiver)
    {
        this->receiver = receiver;
    }
    
    void Execute() override
    {
        receiver->ActionClear();
    }
};

class ZoomInCommand : public GraphCommand
{
public:
    ZoomInCommand(const std::shared_ptr<GraphReceiver>& receiver)
    {
        this->receiver = receiver;
    }

    void Execute() override
    {
        receiver->ActionZoomIn();
    }
};

class ZoomOutCommand : public GraphCommand
{
public:
    ZoomOutCommand(const std::shared_ptr<GraphReceiver>& receiver)
    {
        this->receiver = receiver;
    }

    void Execute() override
    {
        receiver->ActionZoomOut();
    }
};