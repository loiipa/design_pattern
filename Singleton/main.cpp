#include <iostream>
#include <vector>
#include "GraphCtrl.h"

int main()
{
    // 여러 개 정의
    {
        std::vector<GraphCtrl*> vecGraphCtrl{};

        for (int i = 0; i < 3; ++i)
        {
            vecGraphCtrl.push_back(GraphCtrl::GetInstance());  
        }
        
        for (const auto graphCtrl : vecGraphCtrl)
        {
            std::cout << static_cast<void*>(graphCtrl) << std::endl;
        }
    }


    // 복사 생성자, 할당 연산자, 이동 연산자 X (test)
    {
        // GraphCtrl* graphCtrl = GraphCtrl::GetInstance();
        // GraphCtrl* graphCtrlFormove = GraphCtrl::GetInstance();

        // GraphCtrl graphCtrl1;
        // std::cout << static_cast<void*>(&graphCtrl1) << std::endl;

        // GraphCtrl graphCtrl2 = *graphCtrl;
        // std::cout << static_cast<void*>(&graphCtrl2) << std::endl;

        // GraphCtrl graphCtrl3(*graphCtrl);
        // std::cout << static_cast<void*>(&graphCtrl3) << std::endl;

        // GraphCtrl graphCtrl4 = std::move(*graphCtrl);
        // std::cout << static_cast<void*>(&graphCtrl4) << std::endl;

        // GraphCtrl graphCtrl5(std::move(*graphCtrlFormove));
        // std::cout << static_cast<void*>(&graphCtrl5) << std::endl;

        // std::cout << static_cast<void*>(graphCtrl) << std::endl;
        // std::cout << static_cast<void*>(graphCtrlFormove) << std::endl;

    }
}