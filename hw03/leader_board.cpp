#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "leader_board.h"

const std::string high_scores_filename = "high_scores.txt";

LeaderBoard::LeaderBoard() {
    load_leader_board();
}

LeaderBoard::~LeaderBoard() {
    save();
}

void LeaderBoard::add_rating(const std::string &username, int score) {
    if (leader_board_.count(username) == 0) {
        leader_board_[username] = score;
    } else {
        if (leader_board_[username] > score) {
            leader_board_[username] = score;
        }
    }
}

void LeaderBoard::print() {
    std::cout << leader_board_;
}

void LeaderBoard::save() {
    std::ofstream out_file{high_scores_filename};
    if (!out_file.is_open()) {
        std::cerr << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return;
    }

    for (const auto& [username, score] : leader_board_) {
        out_file << username << " " << score << std::endl;
    }

    out_file.close();
}

void LeaderBoard::load_leader_board() {
    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        std::cerr << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return;
    }

    while (true) {
        std::string username;
        int score = 1000;

        in_file >> username;
        in_file >> score;

        in_file.ignore();

        if (username.empty()) {
            if (in_file.fail()) {
                break;
            }
            continue;
        }

        if (leader_board_[username] < score) {
            leader_board_[username] = score;
        };
    }
}


std::ostream& operator<<(std::ostream& out, std::map<std::string, int>& leader_board) {
    struct UserScore {
        std::string name;
        int score;
    };

    std::vector<UserScore> players;
    for (const auto& [username, score]: leader_board) {
        players.push_back({username, score});
    }
    std::sort(players.begin(), players.end(),
              [](const UserScore& lhs, const UserScore& rhs){return lhs.score < rhs.score;}
              );
    for (const auto& player: players) {
        out << player.name << ": " << player.score << std::endl;
    }

    return out;
}


