#include <string>

class SteelSection
{
public:
    SteelSection() = default;
    virtual ~SteelSection() = default;
    virtual std::string GetSteelSectionInfo() const = 0;
};

class SteelBeamSection : public SteelSection
{
public:
    SteelBeamSection() = default;
    virtual ~SteelBeamSection() = default;
    std::string GetSteelSectionInfo() const override
    {
        return "Steel Beam Section : 400 x 600 x 20 x 20";
    }
};

class SteelColumnSection : public SteelSection
{
public:
    SteelColumnSection() = default;
    virtual ~SteelColumnSection() = default;
    std::string GetSteelSectionInfo() const override
    {
        return "Steel Column Section : 500 x 500 x 20 x 20";
    }
};
