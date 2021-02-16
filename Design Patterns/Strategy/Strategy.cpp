#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual std::string DoAlgorithm(const std::vector<std::string> &data) const = 0;
};

class Context
{
private:
    Strategy *_strategy;

public:
    Context(Strategy *strategy = nullptr) : _strategy(strategy) {}
    ~Context() { delete this->_strategy; }
    void setStrategy(Strategy *strategy) { this->_strategy = strategy; }
    void DoBuisnessLogic() const
    {
        std::cout << "Context:: Sorting data using generic algorithm" << std::endl;
        std::string result = this->_strategy->DoAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
        std::cout << "Context:: Result of algorithm is: " << result << std::endl;
    }
};

class ConcreteStrategyA : public Strategy
{
public:
    std::string DoAlgorithm(const std::vector<std::string> &data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    std::string DoAlgorithm(const std::vector<std::string> &data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            std::swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};
