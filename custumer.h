#include <string>
#include <vector>
#include "purchase.h"

using std::string;

/// Custumer
/// This represents a custumer
struct Custumer {
  string id;
  string name;
  string email;
  unsigned short age;
  std::vector<Purchase> purchases;

  operator std::string() {
    // TODO(DavidUser): Move json strigfy outer this class and generic
    return "{ id: \"" + id + "\", name: \"" + name + "\", email: \"" + email +
           "\", age: " + std::to_string(age) + " }";
  }
};
