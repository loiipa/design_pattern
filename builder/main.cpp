#include <iostream>
#include "director.h"

int main()
{
    // draw time graph
    std::shared_ptr<GraphBuilderBase> timeGraphBuilder = std::make_shared<PurchaseTimeGraphBuilder>();
    Director director(timeGraphBuilder);
    
    director.MakeUnitGraph();
    const auto& timeGraph = timeGraphBuilder->GetGraph();
    timeGraph.DrawGraph();

    std::cout << std::endl;

    // draw item graph
    std::shared_ptr<GraphBuilderBase> itemGraphBuilder = std::make_shared<PurchaseItemGraphBuilder>();
    director.ChangeBuilder(itemGraphBuilder);
   
    director.MakeNotUnitGraph();
    const auto& itemGraph = itemGraphBuilder->GetGraph();
    itemGraph.DrawGraph();
}