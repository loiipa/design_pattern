#include <iostream>
#include <memory>
#include "Section.h"

class SectionFactory
{
public:
    SectionFactory() = default;
    virtual ~SectionFactory() = default;

    virtual std::unique_ptr<Section> GetSection() const = 0;

    void PrintSectionInfo()
    {
        std::unique_ptr<Section> section = GetSection();
        std::cout << section->GetSectionInfo() << std::endl;
    }
};

class ConcreteSectionFactory : public SectionFactory
{
public:
    ConcreteSectionFactory() = default;
    virtual ~ConcreteSectionFactory() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<ConcreteSection>();
    }
};

class SteelSectionFactory : public SectionFactory
{
public:
    SteelSectionFactory() = default;
    virtual ~SteelSectionFactory() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<SteelSection>();
    }
};

class WoodSectionFactory : public SectionFactory
{
public:
    WoodSectionFactory() = default;
    virtual ~WoodSectionFactory() = default;

    std::unique_ptr<Section> GetSection() const override
    {
        return std::make_unique<WoodSection>();
    }
};