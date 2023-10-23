#include "CreatorSection.h"

int main()
{
    std::unique_ptr<CreatorSection> creatorA = std::make_unique<CreatorConcreteSection>();
    std::unique_ptr<CreatorSection> creatorB = std::make_unique<CreatorSteelSection>();
    std::unique_ptr<CreatorSection> creatorC = std::make_unique<CreatorWoodSection>();

    creatorA->PrintSectionInfo();
    creatorB->PrintSectionInfo();
    creatorC->PrintSectionInfo();
}