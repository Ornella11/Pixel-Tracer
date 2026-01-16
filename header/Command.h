// Command.h
# ifndef COMMAND_H
# define COMMAND_H
# include <string>
# include <vector>
# include <memory>
# include "Area.h"

class Command {
    private:
    std::string name;
    std::vector<int> intParams;
    std::vector<std::string> strParams;
    
    public:
    // Constructeur
    Command();

    // Destructeur
    ~Command() = default;

    // Méthodes
    void addIntParam(int p);
    void addStrParam(const std::string& p);
    void parse(const std::string& line);
    bool execute(Area& area);
    void clear();

    // Getters
    const std::string& getName() const { return name; }
    const std::vector<int>& getIntParams() const { return intParams; }
    const std::vector<std::string>& getStrParams() const { return strParams; }
};


# endif // COMMAND_H