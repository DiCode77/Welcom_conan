#include <iostream>
#include <fmt/core.h> // Бібліотека fmt для форматування

int main() {
    std::cout << fmt::format("Hello, {}!", "Conan") << std::endl;
    return 0;
}
