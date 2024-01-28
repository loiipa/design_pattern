#pragma once
#include "builder.h"

class Director
{
public:

    Director(std::shared_ptr<GraphBuilderBase> builder)
    : builder(builder) {}
    
    void ChangeBuilder(std::shared_ptr<GraphBuilderBase> builder);
    void MakeUnitGraph();
    void MakeNotUnitGraph();

protected:
    std::shared_ptr<GraphBuilderBase> builder;
};

void Director::ChangeBuilder(std::shared_ptr<GraphBuilderBase> builder)
{
    this->builder = builder;
}

void Director::MakeUnitGraph()
{
    builder->BuildGraphType();
    builder->BuildGridType();
    builder->BuildUnit();
}

void Director::MakeNotUnitGraph()
{
    builder->BuildGraphType();
    builder->BuildGridType();
}