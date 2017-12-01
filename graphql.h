#include <functional>
#include <vector>
#include <string>
using std::string;

class GraphQL
{
public:
  // Register a query
  template <class T, class ...Resolver>
  void Query(string name, Resolver... resolver);

  // Digest a GraphQL request
  // Returns a JSON response
  string Digest(string request);
};
