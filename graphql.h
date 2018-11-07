#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class GraphQL {
 public:
  // Register a query
  template <class T>
  void Query(std::string type, std::string member,
             std::function<T(std::string)> query) {
    queries[type][member] = [query](std::string parameter) {
      return static_cast<std::string>(query(parameter));
    };
  };

  // Digest a GraphQL request
  // Returns a JSON response
  std::string Digest(std::string request) {
    size_t start = 0;
    size_t end = 0;
    auto GetToken = [&]() {
      const char* letters_and_numbers =
          "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ0123456789";
      start = request.find_first_of(letters_and_numbers, end);
      end = request.find_first_not_of(letters_and_numbers, start);
      return request.substr(start, end - start);
    };

    std::string type = GetToken();
    std::string member = GetToken();
    std::string value = GetToken();

    std::stringstream response;
    response << "{ \"data\": { \"" << type
             << "\" : "
             // TODO(DavidUser): Instead get the string output, get a json
             // document and remove the uneeded members based on request
             << queries[type][member](value) << " } }";
    return response.str();
  };

 private:
  std::map<std::string,
           std::map<std::string, std::function<std::string(std::string)>>>
      queries;
};

#define QL_MEMBER(CLASS_NAME, MEMBER_NAME, ACTION) \
  <CLASS_NAME>(#CLASS_NAME, #MEMBER_NAME,          \
               [](decltype(CLASS_NAME::MEMBER_NAME) MEMBER_NAME) { ACTION })
// TODO extract this member signature to assembly the graph QL from-end digest
