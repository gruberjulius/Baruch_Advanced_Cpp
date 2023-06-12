#include<iostream>
#include<cfloat>


template <typename T>
const char* Classify(T t)
{
    switch (std::fpclassify(t))
    {
        case FP_INFINITE:  return "Inf";
        case FP_NAN: return "NaN";
        case FP_NORMAL:    return "normal";
        case FP_SUBNORMAL: return "subnormal";
        case FP_ZERO: return "zero";
        default:  return "unknown";
    }
}

template <typename T>
const void Classify2(T t){
    if(std::isfinite(t)){
        std::cout << "Value " << t <<" is finite";
    }else if(std::isinf(t)){
        std::cout << "Value " << t <<" is infinite";
    }else if(std::isnan(t)){
        std::cout << "Value " << t <<" is NaN";
    }else if(std::isnormal(t)){
        std::cout << "Value " << t <<" is normal";
    }else{
        std::cout << "Value " << t << "is neither finite nor infinite nor NaN nor normal" << std::endl;
    }
}

int main(){

    
    double val = std::numeric_limits<double>::max();
    std::cout << Classify(val) << std::endl;
    std::cout << Classify(2.0 * val) << std::endl;
    std::cout << Classify(3.1415 + val) << std::endl;
    double val2 = std::numeric_limits<double>::min() - 3.1415;
    std::cout << Classify(val2) << std::endl;
    std::cout << Classify(val2/2.0) << std::endl;
    std::cout << Classify(DBL_MIN/2) << std::endl;
    double factor = 2.0;
    std::cout << Classify(factor) << std::endl;
    val2 = factor*std::numeric_limits<double>::max();
    std::cout << Classify(val2) << std::endl;
    std::cout << Classify(val2 - val2) << std::endl;
    std::cout << Classify(std::sqrt(-1.0)) << std::endl;
    std::cout << Classify(std::log(0.0)) << std::endl;
    std::cout << Classify(std::exp(val)) << std::endl;
    return 0;
}
