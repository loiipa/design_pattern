#include <string>

class Section
{
public:
    Section() = default;
    virtual ~Section() = default;
    virtual std::string GetSectionInfo() const = 0;
};

class ConcreteSection : public Section
{
public:
    ConcreteSection() = default;
    virtual ~ConcreteSection() = default;
    std::string GetSectionInfo() const override
    {
        return "Concreate Section : 300*400";
    }
};

class SteelSection : public Section
{
public:
    SteelSection() = default;
    virtual ~SteelSection() = default;
    std::string GetSectionInfo() const override
    {
        return "Steel Section : 300*400*10*10";
    }
};

class WoodSection : public Section
{
public:
    WoodSection() = default;
    virtual ~WoodSection() = default;
    std::string GetSectionInfo() const override
    {
        return "Wood Section : 2*2";
    }
};