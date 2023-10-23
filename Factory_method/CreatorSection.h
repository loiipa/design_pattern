#include <iostream>
#include <memory>
#include "Section.h"
class CreatorSection
{
public:
    CreatorSection() = default;
    virtual ~CreatorSection() = default;

    virtual std::unique_ptr<Section> GetSection() const = 0;

    void PrintSectionInfo()
    {
        std::unique_ptr<Section> section = GetSection();
        std::cout << section->GetSectionInfo() << std::endl;
    }
};

class CreatorConcreteSection : public CreatorSection
{
public:
    CreatorConcreteSection() = default;
    virtual ~CreatorConcreteSection() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<ConcreteSection>();
    }
};

class CreatorSteelSection : public CreatorSection
{
public:
    CreatorSteelSection() = default;
    virtual ~CreatorSteelSection() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<SteelSection>();
    }
};

class CreatorWoodSection : public CreatorSection
{
public:
    CreatorWoodSection() = default;
    virtual ~CreatorWoodSection() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<WoodSection>();
    }
};