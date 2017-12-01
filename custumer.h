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
};
