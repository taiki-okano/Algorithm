#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string input;
    const std::string festival = "FESTIVAL";

    std::cin >> input;

    auto itr = std::find_end(input.begin(), input.end(), festival.begin(), festival.end());

    std::cout << input.substr(0, std::distance(input.begin(), itr)) << std::endl;

    return 0;
}
