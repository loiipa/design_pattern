#pragma once

class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void Execute() = 0;
};