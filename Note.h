#include <string>

class Note 
{
private:
  std::string noteText;
  std::string noteRoom;
public:
  Note(std::string room, std::string noteText);
  ~Note() {};
  std::string getText();
  std::string getRoom();
};
