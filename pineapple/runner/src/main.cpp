#include "application.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try {
        runner::Application{}.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
