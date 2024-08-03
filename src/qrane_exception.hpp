#include <exception>

namespace qrane {

class OnedSelectionPolicyException : public std::exception {
private:
  char *msg_;

public:
  OnedSelectionPolicyException(char *msg) : msg_(msg) {}
  char *what() { return msg_; }
};

} // namespace qrane