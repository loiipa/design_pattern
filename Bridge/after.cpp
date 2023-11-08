#include <iostream>
#include <memory>

class GraphCtrl
{
public:
    virtual void PrintData() = 0;
};

class NumGraphCtrl : public GraphCtrl
{
public:
    void PrintData() override
    {
        std::cout << "0, 1, 2" << std::endl;
    }
};

class StrGraphCtrl : public GraphCtrl
{
public:
    void PrintData() override
    {
        std::cout << "zero, one, two" << std::endl;
    }
};

class GraphView
{
public:
    //GraphView() = default;
    GraphView(std::shared_ptr<GraphCtrl> graphCtrl) : m_pGraphCtrl(graphCtrl){};
    virtual void CreateView() = 0;
    virtual void Print() = 0;

protected:
    std::shared_ptr<GraphCtrl> m_pGraphCtrl;
};

class BarGraphView : public GraphView
{
public:
    BarGraphView(std::shared_ptr<GraphCtrl> graphCtrl) : GraphView(graphCtrl){};

    void CreateView() override
    {
        std::cout << "CreateView - Bar" << std::endl;
    }

    void Print()
    {
        std::cout << "Bar - ";
        m_pGraphCtrl->PrintData();
    };
};

class LineGraphView : public GraphView
{
public:
    LineGraphView(std::shared_ptr<GraphCtrl> graphCtrl) : GraphView(graphCtrl){};

    
    void CreateView() override
    {
        std::cout << "CreateView - Line" << std::endl;
    }

    void Print()
    {
        std::cout << "Line - ";
        m_pGraphCtrl->PrintData();
    };
};

int main()
{
    std::shared_ptr<GraphCtrl> numGraphCtrl = std::make_shared<NumGraphCtrl>();
    std::shared_ptr<GraphCtrl> strGraphCtrl = std::make_shared<StrGraphCtrl>();

    std::unique_ptr<GraphView> barGraphNum = std::make_unique<BarGraphView>(numGraphCtrl);
    std::unique_ptr<GraphView> barGraphStr = std::make_unique<BarGraphView>(strGraphCtrl);
    std::unique_ptr<GraphView> lineGraphNum = std::make_unique<LineGraphView>(numGraphCtrl);
    std::unique_ptr<GraphView> lineGraphStr = std::make_unique<LineGraphView>(strGraphCtrl);

    barGraphNum->CreateView();
    barGraphNum->Print();

    barGraphStr->CreateView();
    barGraphStr->Print();

    lineGraphNum->CreateView();
    lineGraphNum->Print();

    lineGraphStr->CreateView();
    lineGraphStr->Print();
}