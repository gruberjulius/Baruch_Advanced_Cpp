#include "SDE.h"

class SDEstd : public SDE
{
	private:
	//option data stored private	
    const OptionData& optionData;

public:
    explicit SDEstd(const OptionData& data): optionData(data){}

	//drift term
    double drift(double x, double V) const override
    {
        return (optionData.r - optionData.D) * V; //r-dividend * V
    }

    // Diffusion function
    double diffusion(double x, double V) const override
    {
        return optionData.sig * V;
    }

	//no jump in std class
    double jump(double x, double V) const override
    {
        return 0.0; 
    }
};
