#include "CreatorSection.h"
#include <iostream>

int main()
{
    std::unique_ptr<CreatorSection> CreatorA = std::make_unique<CreatorBeamSection>();
    std::unique_ptr<CreatorSection> CreatorB = std::make_unique<CreatorColumnSection>();

    std::unique_ptr<ConcreteSection> SectionA = CreatorA->CreateConcreteSection();
    std::unique_ptr<ConcreteSection> SectionB = CreatorB->CreateConcreteSection();
    std::unique_ptr<SteelSection> SectionC = CreatorA->CreateSteelSection();
    std::unique_ptr<SteelSection> SectionD = CreatorB->CreateSteelSection();

    std::cout << SectionA->GetConcreteSectionInfo() << std::endl;
    std::cout << SectionB->GetConcreteSectionInfo() << std::endl;
    std::cout << SectionC->GetSteelSectionInfo() << std::endl;
    std::cout << SectionD->GetSteelSectionInfo() << std::endl;
}