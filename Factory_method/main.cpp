#include "CreatorSection.h"

int main()
{
    // Creator
    std::unique_ptr<SectionFactory> creatorA = std::make_unique<ConcreteSectionFactory>();
    std::unique_ptr<SectionFactory> creatorB = std::make_unique<SteelSectionFactory>();
    std::unique_ptr<SectionFactory> creatorC = std::make_unique<WoodSectionFactory>();

    creatorA->PrintSectionInfo();
    creatorB->PrintSectionInfo();
    creatorC->PrintSectionInfo();

    // Product
    std::unique_ptr<Section> ProductA = creatorA->GetSection();
    std::unique_ptr<Section> ProductB = creatorB->GetSection();
    std::unique_ptr<Section> ProductC = creatorC->GetSection();
    
    ProductA->GetSectionInfo();
    ProductB->GetSectionInfo();
    ProductC->GetSectionInfo();

    // not use pattern
    std::unique_ptr<Section> ProductA = std::make_unique<ConcreteSection>();
    std::unique_ptr<Section> ProductA = std::make_unique<SteelSection>();
    std::unique_ptr<Section> ProductA = std::make_unique<WoodSection>();
}

// 핵심은 클라이언트 코드가 직접적으로 new나 생성자를 쓰지 않고 Factory를 통해서 생성하는 것.