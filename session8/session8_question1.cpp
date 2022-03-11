#include <iostream>
#include <string>
#include <vector>

class Candidate {
private:
    std::string lastName;
    unsigned int votes;
public:
    Candidate(std::string ln = "", unsigned int v = 0);
    void setLastName(std::string ln);
    void setVotes(unsigned int v);
    std::string getLastName() const;
    unsigned int getVotes() const;
};

Candidate::Candidate(std::string ln, unsigned int v)
    : lastName(ln), votes(v) {}

void Candidate::setLastName(std::string ln) {
    this->lastName = ln;
}
void Candidate::setVotes(unsigned int v) {
    this->votes = v;
}
std::string Candidate::getLastName() const {
    return this->lastName;
}
unsigned int Candidate::getVotes() const {
    return this->votes;
}

int main()
{
    const int N_CANDIDATES = 5;
    std::vector<Candidate> Candidates(N_CANDIDATES);
    std::string temp_string;
    unsigned int temp_votes = 0;
    unsigned int total_votes = 0;
    std::string winner = "";
    unsigned int winnerVotes = 0;
    for (int i = 0; i < N_CANDIDATES; i++) {
        std::cout << "Enter last name: ";
        std::getline(std::cin, temp_string);
        Candidates[i].setLastName(temp_string);
        std::cout << "Enter number of votes: ";
        std::cin >> temp_votes;
        std::cin.get();
        Candidates[i].setVotes(temp_votes);
        total_votes += temp_votes;
        if (Candidates[i].getVotes() >= winnerVotes) {
            winner = Candidates[i].getLastName();
            winnerVotes = Candidates[i].getVotes();
        }
    }
    std::cout << "Candidates\t\t\tVotes Received\t\t\t% of Total Votes\n";
    double percentage = 0;
    for (int i = 0; i < N_CANDIDATES; i++) {
        std::cout << Candidates[i].getLastName()
            << "\t\t\t\t" << Candidates[i].getVotes();
        percentage = double(Candidates[i].getVotes()) / double(total_votes);
        std::cout << "\t\t\t\t" << percentage << "\n";
    }
    std::cout << "Total" << "\t\t\t\t" << total_votes << "\n";
    std::cout << "The winner of the election is " << winner << "\n";

}