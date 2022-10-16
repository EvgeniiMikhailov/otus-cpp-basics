#ifndef INC_03_HOMEWORK_CONFIG_H
#define INC_03_HOMEWORK_CONFIG_H

struct Config {
    int max_number = 100;
    bool display_rating = false;
};

Config parse_arguments(int argc, char *argv[]);

#endif //INC_03_HOMEWORK_CONFIG_H
