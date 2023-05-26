#include <iostream>


int main()
{
    const std::string LOWER = "The number is lower than this";
    const std::string HIGHER = "The number is higher that this";
    const std::string END = "Congratulations, the number is: ";

    std::srand((unsigned int)std::time(nullptr)); // using current time as seed for Random

    int random_number = std::rand();

    int secret_number = random_number % 10 + 1; // %10 gives [0;9] range while +1 enforces range to be [1; 10]

    std::cout << "Guess number 1-10 :" << std::endl;

    int guess_number;
    std::string message;
    do
    {
        std::cin >> guess_number;

        if (secret_number < guess_number) message = LOWER;
        if (secret_number > guess_number) message = HIGHER;

        std::cout << message << std::endl;
        message = "";

    } while (guess_number != secret_number);

    std::cout << END << guess_number << std::endl;

    return 0;
}
