#pragma once
#include "Graph.h"
#include <memory>

class GraphBuilderBase
{
public:
    GraphBuilderBase() { MakeGraph(); }
    virtual ~GraphBuilderBase() = default;
    
    virtual void Reset();
    virtual void MakeGraph();
    virtual void BuildGraphType();
    virtual void BuildGridType();
    virtual void BuildUnit();
    virtual Graph GetGraph();

protected:
    std::unique_ptr<Graph> graph;
};

void GraphBuilderBase::Reset()
{
    graph.reset(nullptr);
}

void GraphBuilderBase::MakeGraph()
{
    graph = std::make_unique<Graph>();
}

void GraphBuilderBase::BuildGraphType()
{
    graph->SetGraphType(GRAPH_TYPE::LINE);
}

void GraphBuilderBase::BuildGridType()
{
    graph->SetGridType(GRID_TYPE::CATEGORY);
}

void GraphBuilderBase::BuildUnit()
{
    graph->SetUnit("default");
}

Graph GraphBuilderBase::GetGraph()
{
    return *graph;
}

class PurchaseTimeGraphBuilder : public GraphBuilderBase
{
    void BuildGraphType() override
    {
        graph->SetGraphType(GRAPH_TYPE::POINT);
    }

    void BuildGridType() override
    {
        graph->SetGridType(GRID_TYPE::XY_GRAPH);
    }

    void BuildUnit() override
    {
        graph->SetUnit("hour");
    }
};

class PurchaseItemGraphBuilder : public GraphBuilderBase
{
    void BuildGraphType() override
    {
        graph->SetGraphType(GRAPH_TYPE::BAR);
    }

    void BuildGridType() override
    {
        graph->SetGridType(GRID_TYPE::CATEGORY);
    }

    void BuildUnit() override
    {
        graph->SetUnit("number");
    }
};