#include <memory>

class GraphCtrl
{
private:
    GraphCtrl() = default;
    GraphCtrl(const GraphCtrl&) = delete;

    // GraphCtrl& operator=(const GraphCtrl&) = delete;
    // GraphCtrl(GraphCtrl&&) = delete;
    // GraphCtrl& operator=(GraphCtrl&&) = delete;

public:
    static GraphCtrl* GetInstance()
    {
        if (graphCtrl == nullptr)
        {
            graphCtrl = new GraphCtrl();
        }
        return graphCtrl;
    }

private:
    static GraphCtrl* graphCtrl;

};

GraphCtrl* GraphCtrl::graphCtrl = nullptr;  