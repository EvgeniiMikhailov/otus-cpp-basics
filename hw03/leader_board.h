#ifndef INC_03_HOMEWORK_LEADER_BOARD_H
#define INC_03_HOMEWORK_LEADER_BOARD_H

class LeaderBoard {
public:
    LeaderBoard();
    ~LeaderBoard();
    void add_rating(const std::string& username, int score);
    void print();
    void save();

private:
    std::map<std::string, int> leader_board_;
    void load_leader_board();
};

std::ostream& operator<<(std::ostream& out, std::map<std::string, int>& leader_board);

#endif //INC_03_HOMEWORK_LEADER_BOARD_H
