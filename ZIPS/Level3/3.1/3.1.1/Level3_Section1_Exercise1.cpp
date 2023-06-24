#include<iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <time.h> // for ctime_s because ctime is considered "unsafe"
#include <system_error>
#include<string>

void Iprint(const std::string& s, int n ) {
	for(int i = 0; i <n ; i++){
    	// print the string and the thread ID
   		std::thread::id curr_thread_id = std::this_thread::get_id(); //thread ID is PART E
    	std::cout << "Thread: "<< s << "\t ID of: " << curr_thread_id << std::endl;
	}
}

void freeFunc(){ 
    Iprint("Free void function" , 2);
}

// stored lambda function
auto stored_lambda = []() { Iprint("Stored lambda thread: ", 2); };

class PrintClass{
    private:

    public:
        void operator()(){
            Iprint("Function object with class", 3);
        }

        //Static Member Function
        static void StaticFunction(){Iprint("Static Lambda Function", 4 );}
};

//binded member function
auto boundFunc = std::bind(Iprint, "Bounded member function", 5 );


// Part c
void joinThread(std::thread& t){
    if(t.joinable()){
        t.join();
    }    
}


// Part d 
// if thread is joinable, join it, else don't 
void joinThreadNoExcept(std::thread& t) {
    try {
        if (t.joinable()) {
            t.join();
        }
    } catch (const std::exception& e) {
        // Handle the exception if required
        std::cerr << "Exception occurred while joining the thread: " << e.what() << std::endl;
    }
}


int main(){

    // PART A/B
    // Getting timing for threads 
    const auto start_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();

	//freeFunc();

    std::thread t_freeFunc(freeFunc);
    t_freeFunc.detach();

    std::thread t_storedlambda(stored_lambda);
    //PrintClass sample;
    PrintClass sample;
    std::thread t_operator(sample);

    // Static Function 
    std::thread t_static(PrintClass::StaticFunction);

    std::thread t_boundFunc(boundFunc);

    // lambda 
    std::thread t_lambda([]() { Iprint("Bound member function thread", 6); });

    joinThreadNoExcept(t_lambda);
    joinThreadNoExcept(t_freeFunc);
    joinThreadNoExcept(t_storedlambda);
    joinThreadNoExcept(t_operator);
    joinThreadNoExcept(t_static);
    joinThreadNoExcept(t_boundFunc);
    joinThreadNoExcept(t_lambda);



    const auto stop_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count() - start_time;
    
    std::cout << "Our algo neeed so much time" << stop_time << std::endl;
	return 0;
}
