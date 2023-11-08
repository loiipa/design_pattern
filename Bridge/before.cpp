#include <iostream>
#include <memory>

class GraphView
{
public:
    virtual void CreateView() = 0;
    virtual void PrintNum() = 0;
    virtual void PrintStr() = 0;
};

class BarGraphView : public GraphView
{
public:
    void CreateView() override
    {
        std::cout << "CreateView - Bar" << std::endl;
    }

    void PrintNum()
    {
        std::cout << "Bar - 0, 1, 2" << std::endl;
    };

    void PrintStr()
    {
        std::cout << "Bar - zero, one, two" << std::endl;
    };
    
};

class LineGraphView : public GraphView
{
public:
    void CreateView() override
    {
        std::cout << "CreateView - Line" << std::endl;
    }

    void PrintNum()
    {
        std::cout << "Line - 0, 1, 2" << std::endl;
    };

    void PrintStr()
    {
        std::cout << "Line - zero, one, two" << std::endl;
    };
};

int main()
{
    std::unique_ptr<GraphView> barGraph = std::make_unique<BarGraphView>();
    std::unique_ptr<GraphView> lineGraph = std::make_unique<LineGraphView>();

    barGraph->CreateView();
    barGraph->PrintNum();
    barGraph->PrintStr();

    lineGraph->CreateView();
    lineGraph->PrintNum();
    lineGraph->PrintStr();
}