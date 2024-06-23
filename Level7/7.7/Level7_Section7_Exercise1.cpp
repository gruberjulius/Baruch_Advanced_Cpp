#include <iostream>
#include <random>
#include "StopWatch.h"
#include "OptionData.hpp"
#include "SDEstd.h"
#include "SDEjump.h" 

//Gievn Code
int main()
{

    std::cout << "1 factor MC with explicit Euler\n";

    OptionData myOption{ 65.0, 0.25, 0.08, 0.3, 0.0, -1 };
    SDEstd sde(myOption);
    // Initial value of SDEstd
    double S_0 = 60;
    // Variables for underlying stock
    double x;
    double VOld = S_0;
    double VNew;
    long NT = 100;

    std::cout << "Number of time steps: ";
    std::cin >> NT;

    // V2 mediator stuff

    long NSIM = 50000;
    std::cout << "Number of simulations: ";
    std::cin >> NSIM;
    double M = static_cast<double>(NSIM);
    double dt = myOption.T / static_cast<double> (NT);
    double sqrdt = std::sqrt(dt);

    // Normal random number

    double dW;
    double price = 0.0; // Option price
    double payoffT;
    double avgPayoffT = 0.0;
    double squaredPayoff = 0.0;
    double sumPriceT = 0.0;

    // Normal (0,1) rng
    std::default_random_engine dre;
    std::normal_distribution<double> nor(0.0, 1.0);

    // Create a random number
    dW = nor(dre);
    StopWatch sw;
    sw.StartStopWatch();
    
    for (long i = 1; i <= M; ++i)
    {
    // Calculate a path at each iteration
    if ((i/100'000) * 100'000 == i)
    {
        // Give status after each 10000th iteration
        std::cout << i << ", ";
    }
    VOld = S_0;
    x = 0.0;
    for (long index = 0; index <= NT; ++index)
        {
            // Create a random number
            dW = nor(dre);
            // The FDM (in this case explicit Euler)
            VNew = VOld + (dt * sde.drift(x, VOld)) + (sqrdt * sde.diffusion(x, VOld) * dW);
            VOld = VNew;
            x += dt;
        }
// Assemble quantities (postprocessing)
    payoffT = myOption.myPayOffFunction(VNew);
    sumPriceT += payoffT;
    avgPayoffT += payoffT/M;
    avgPayoffT *= avgPayoffT;

    squaredPayoff += (payoffT*payoffT);
}

// Finally, discounting the average price

    price = std::exp(-myOption.r * myOption.T) * sumPriceT/M;
    std::cout << "Price, after discounting: " << price << ", " << std::endl;

    double SD = std::sqrt((squaredPayoff / M) - sumPriceT*sumPriceT/(M*M));
    std::cout << "Standard Deviation: " << SD << ", " << std::endl;

    double SE = SD / std::sqrt(M);
    std::cout << "Standard Error: " << SE << ", " << std::endl;

    sw.StopStopWatch();
    std::cout << "Elapsed time in seconds: " << sw.GetTime() << '\n';

    // implemented the original code.
    //the next step would be implementing jump diffusion as well.s
   

    return 0;
}
