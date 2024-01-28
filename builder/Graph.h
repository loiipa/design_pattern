#pragma once
#include <iostream>

enum class GRAPH_TYPE : unsigned int
{
    LINE = 0,
    POINT,
    BAR,
    // ...
};

enum class GRID_TYPE : unsigned int
{
    XY_GRAPH = 0,
    CATEGORY,
    // ...
};

class Graph
{
public:
    Graph() = default;
    Graph(const GRAPH_TYPE& graphType, const GRID_TYPE& gridType, const std::string& unit)
    : graphType(graphType), gridType(gridType), unit(unit) {}

    void SetGraphType(const GRAPH_TYPE& graphType)
    {
        this->graphType = graphType;
    }

    void SetGridType(const GRID_TYPE& gridType)
    {
        this->gridType = gridType;
    }
    
    void SetUnit(std::string&& unit)
    {
        this->unit = std::move(unit);
    }

    void DrawGraph() const
    {
        std::cout << "graph type : " << static_cast<unsigned int>(graphType) << std::endl;
        std::cout << "grid type : " << static_cast<unsigned int>(gridType) << std::endl;
        std::cout << "unit : '" << unit << "'" << std::endl;
    }

private:
    GRAPH_TYPE graphType;
    GRID_TYPE  gridType;
    std::string unit;
};