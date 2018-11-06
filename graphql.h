#include <functional>
#include <string>
#include <vector>
using std::string;

class GraphQL {
 public:
  // Register a query
  template <class T, typename... Args>
  void Query(string name, Args... args) {}

  // Digest a GraphQL request
  // Returns a JSON response
  string Digest(string request) { return "{}";};
};

#define QL_MEMBER(CLASS_NAME, MEMBER_NAME, ACTION) \
  <CLASS_NAME>(#CLASS_NAME, #MEMBER_NAME,               \
               [](decltype(CLASS_NAME::MEMBER_NAME) MEMBER_NAME) { ACTION })
// TODO extract this member signature to assembly the graph QL from-end digest

