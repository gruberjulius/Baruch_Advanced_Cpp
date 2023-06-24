#include <iostream>
#include <<execution>
#include <numeric>
#include <execution>
#include <chrono>
#include <numeric>
#include <vector>
#include <omp.h>
#include <thread>
#include <future>

// Part b

// recursive way of calulcating the sum (dividing array into two subarrays	
double recursive(std::vector<int>&  vec, std::size_t startIdx, std::size_t endIdx) {

	// computing directly if size is smaller than 1000
	if ((endIdx-startIdx < 1000) || ((endIdx - startIdx) / 2) < startIdx) {
		return std::accumulate(vec.begin() + startIdx, vec.begin() + endIdx, 0.0);
	}
	else {

		// creating future for async call for second part to combine elements
		std::future<double> resFirstHalf{ std::async(std::launch::async, recursive, std::ref(vec), startIdx, (endIdx - startIdx) / 2) };

		// computing the whole
		return  resFirstHalf.get() + recursive(vec, (endIdx - startIdx) / 2, endIdx);
	}
}

int main() {
    //Part a
    const int SIZE = 10000000; // Size of the numeric array

    // Create a huge numeric array
    std::vector<int> array(SIZE);
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    // Sum the elements using std::accumulate()
    auto startTime = std::chrono::high_resolution_clock::now();
    int sum = std::accumulate(array.begin(), array.end(), 0);
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time accumulate: " << duration.count() << " milliseconds" << std::endl;


    //Part b


    // Sum the elements using recursive function
    startTime = std::chrono::high_resolution_clock::now();
    sum = recursive(array, 0, SIZE  -1);
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time recursive function: " << duration.count() << " milliseconds" << std::endl;



    // Sum the elements using omp reduction
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
    omp_set_num_threads(4);
    #pragma omp parallel for reduction (+:sum)
    for(long i = 0; i < array.size(); ++i){
        sum +=i;
    }

    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time using execution par: " << duration.count() << " milliseconds" << std::endl;

    // Sum the elements using std::executionpar
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
	sum = std::reduce(std::execution::par, array.begin(), array.end(), 0.0);


	//std::execution::par
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time using omp reduction: " << duration.count() << " milliseconds" << std::endl;


    // Sum the elements using std::executionpar
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
    
    std::transform(std::execution::par,
               array.begin(), array.end(), array.begin(),
               [](double v) { return v * 2.0; }
    );

	//std::execution::par
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time for std::transform in parallel : " << duration.count() << " milliseconds" << std::endl;


    // Sum the elements using std::executionpar
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
    
    std::transform(array.begin(), array.end(), array.begin(),
               [](double v) { return v * 2.0; }
    );

	//std::execution::par
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time for std::transform  sequential : " << duration.count() << " milliseconds" << std::endl;



    // Sum the elements using std::executionpar
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
    
    std::sort(array.begin(), array.end());

	//std::execution::par
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time for std::sort  sequential : " << duration.count() << " milliseconds" << std::endl;

    // Sum the elements using std::executionpar
    startTime = std::chrono::high_resolution_clock::now();
    sum = 0; 
    
    std::sort(  std::execution::par, array.begin(), array.end());

	//std::execution::par
    endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time for std::sort  parallel : " << duration.count() << " milliseconds" << std::endl;


    return 0;
}

