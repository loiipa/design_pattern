#include <iostream>
#include <memory>

class GraphReceiver
{
public:
    void ActionDraw()
    {
        std::cout << "Draw" << std::endl;
    }

    void ActionClear()
    {
        std::cout << "Clear" << std::endl;
    }

    void ActionZoomIn()
    {
        std::cout << "Zoom In" << std::endl;
    }

    void ActionZoomOut()
    {
        std::cout << "Zoom Out" << std::endl;
    }
};
