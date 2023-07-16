#include "SDE.h"
#include <random>


class SDEjump : public SDE
{
private:
    const OptionData& optionData;
    mutable std::default_random_engine dre;
    mutable std::poisson_distribution<int> poissonDist; 

public:
    explicit SDEjump(const OptionData& data) : optionData(data), poissonDist(1.0) {} // intialize both distributions 

   	//drift term 
    double drift(double x, double V) const override
    {
        return (optionData.r - optionData.D - jump(x, V)) * V;
    }

	//diffusion term
    double diffusion(double x, double V) const override
    {
        return optionData.sig * V;
    }

    // jump term
    // including the jump term
    double jump(double x, double V) const override
    {
        int jumps = poissonDist(dre); // n of jumps 
        double jumpSize = 0.1;       
        return jumps * jumpSize;
    }
};
