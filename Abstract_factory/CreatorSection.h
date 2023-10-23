#include "ConcreteSection.h"
#include "SteelSection.h"
#include <memory>

class CreatorSection
{
public:
    CreatorSection() = default;
    virtual ~CreatorSection() = default;
    virtual std::unique_ptr<ConcreteSection> CreateConcreteSection() const = 0;
    virtual std::unique_ptr<SteelSection> CreateSteelSection() const = 0;
};

class CreatorBeamSection : public CreatorSection
{
public:
    CreatorBeamSection() = default;
    virtual ~CreatorBeamSection() = default;

    std::unique_ptr<ConcreteSection> CreateConcreteSection() const override
    {
        return std::make_unique<ConcreteBeamSection>();
    }

    virtual std::unique_ptr<SteelSection> CreateSteelSection() const override
    {
        return std::make_unique<SteelBeamSection>();
    }
};

class CreatorColumnSection : public CreatorSection
{
public:
    CreatorColumnSection() = default;
    virtual ~CreatorColumnSection() = default;
    
    std::unique_ptr<ConcreteSection> CreateConcreteSection() const override
    {
        return std::make_unique<ConcreteColumnSection>();
    }

    virtual std::unique_ptr<SteelSection> CreateSteelSection() const override
    {
        return std::make_unique<SteelColumnSection>();
    }
};