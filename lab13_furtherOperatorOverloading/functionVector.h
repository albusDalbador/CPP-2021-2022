#include <vector>
#include <functional>

class FunctionVector {


    private:
        // std::vector<double(*)(double)> functions;
        std::vector<std::function<double(double)>> functions;

    public:
        // void inser
        double operator[](int) const;
        
        void insert(std::function<double(double)>);
        double calc(double);
};