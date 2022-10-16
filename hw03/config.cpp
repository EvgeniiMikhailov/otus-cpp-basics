#include <string>

#include "config.h"

Config parse_arguments(int argc, char *argv[]) {
    Config config;

    for (int i=0; i<argc; ++i) {
        std::string argv_string{argv[i]};
        if (argv_string == "-table") {
            config.display_rating = true;
        }
        if (argv_string == "-max") {
            if (i+1 < argc) {
                config.max_number = std::stoi(argv[i+1]);
            }
        }
    }

    return config;
}