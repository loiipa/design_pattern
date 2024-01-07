#include <iostream>
#include <vector>

class DrawRectangle
{
public:
    DrawRectangle(int width, int height)
    : width(width), height(height) { this->outChar = '*'; }
    
    virtual ~DrawRectangle() = default;

    // abstract function
    virtual std::string GetRectangleInfo() const = 0;

    // virtual function
    virtual void OnDraw() const
    {
        for (int idxHeight = 0; idxHeight < this->height; ++idxHeight)
        {
            if (idxHeight == 0 || idxHeight == this->height - 1)
            {
                const std::string line(this->width, this->outChar);
                std::cout << line << std::endl;
            }
            else
            {
                std::string line(this->width - 2, ' ');
                line = outChar + line + outChar;
                std::cout << line << std::endl;
            }
        }
    }

    // Hook - subclass에서 GetRectangleInfo() 정의
    void DrawAll() const
    {
        std::cout << this->GetRectangleInfo() << std::endl;
        this->OnDraw();
        std::cout << "\n";
    }

    // function
    std::pair<int, int> GetSpec() const
    {
        return { this->width, this->height };
    }


protected:
    int width;
    int height;
    char outChar;
};

class DrawStarRectangle : public DrawRectangle
{
public:
    DrawStarRectangle(int width, int height)
    : DrawRectangle(width, height) {}

    virtual ~DrawStarRectangle() = default;

    // Implement abstract function
    std::string GetRectangleInfo() const override
    {
        auto spec = GetSpec();
        return "Name   - Star\nwidth  - " + std::to_string(spec.first) + "\nheight - " + std::to_string(spec.second);
    }

    // override
    void OnDraw() const override
    {
        for (int idxHeight = 0; idxHeight < this->height; ++idxHeight)
        {
            if (idxHeight == 0 || idxHeight == this->height - 1)
            {
                const std::string line(this->width, this->outChar);
                std::cout << line << std::endl;
            }
            else
            {
                std::string line(this->width - 2, outChar);
                line = outChar + line + outChar;
                std::cout << line << std::endl;
            }
        }
    }
};

class DrawEmptyRectangle : public DrawRectangle
{
public:
    DrawEmptyRectangle(int width, int height)
    : DrawRectangle(width, height) {}

    virtual ~DrawEmptyRectangle() = default;

    std::string GetRectangleInfo() const override
    {
        auto spec = GetSpec();
        return "Name   - Empty\nwidth  - " + std::to_string(spec.first) + "\nheight - " + std::to_string(spec.second);
    }
};

class DrawSevenRectangle : public DrawRectangle
{
public:
    DrawSevenRectangle(int width, int height)
    : DrawRectangle(width, height) { outChar = '7';}

    virtual ~DrawSevenRectangle() = default;

    std::string GetRectangleInfo() const override
    {
        auto spec = GetSpec();
        return "Name   - 7\nwidth  - " + std::to_string(spec.first) + "\nheight - " + std::to_string(spec.second);
    }

    void OnDraw() const override
    {
        for (int idxHeight = 0; idxHeight < this->height; ++idxHeight)
        {
            if (idxHeight == 0 || idxHeight == this->height - 1)
            {
                const std::string line(this->width, this->outChar);
                std::cout << line << std::endl;
            }
            else
            {
                std::string line(this->width - 2, this->outChar);
                line = outChar + line + outChar;
                std::cout << line << std::endl;
            }
        }
    }
};


int main()
{
    DrawStarRectangle draw1(5, 10);
    DrawEmptyRectangle draw2(10, 5);
    DrawSevenRectangle draw3(7, 7);

    draw1.DrawAll();
    draw2.DrawAll();
    draw3.DrawAll();
}