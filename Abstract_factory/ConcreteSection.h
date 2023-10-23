#include <string>

class ConcreteSection
{
public:
    ConcreteSection() = default;
    virtual ~ConcreteSection() = default;
    virtual std::string GetConcreteSectionInfo() const = 0;
};

class ConcreteBeamSection : public ConcreteSection
{
public:
    ConcreteBeamSection() = default;
    virtual ~ConcreteBeamSection() = default;
    std::string GetConcreteSectionInfo() const override
    {
        return "Concrete Beam Section : 400 x 600";
    }
};

class ConcreteColumnSection : public ConcreteSection
{
public:
    ConcreteColumnSection() = default;
    virtual ~ConcreteColumnSection() = default;
    std::string GetConcreteSectionInfo() const override
    {
        return "Concrete Column Section : 500 x 500";
    }
};
