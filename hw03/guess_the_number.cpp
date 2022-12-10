#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

#include "leader_board.h"
#include "config.h"

int RunGame(int max_number) {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    const int random_value = std::rand() % max_number;

    int attempts = 1;
    std::cout << "Let the Game begin!" << std::endl;
    while (true) {
        int guess;
        std::cout << "Enter your number: ";
        std::cin >> guess;
        if (guess < random_value) {
            std::cout << "Less than." << std::endl;
        } else if (guess > random_value) {
            std::cout << "Greater than." << std::endl;
        } else {
            std::cout << "You win!" << std::endl;
            return attempts;
        }
        ++attempts;
    }
}

int main(int argc, char *argv[]) {
    Config config = parse_arguments(argc, argv);
    LeaderBoard leaderBoard;

    if (config.display_rating) {
        leaderBoard.print();
        return 0;
    }

    std::string name;
    std::cout << "Please tell you name: ";
    std::cin >> name;
    int score = RunGame(config.max_number);

    leaderBoard.add_rating(name, score);
    leaderBoard.print();
}
