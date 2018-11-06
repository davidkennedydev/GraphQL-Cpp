#include <iostream>
#include <string>
#include "graphql.h"

#include "custumer.h"

using std::string;

int main(void) {
  // Create a GraphQL digester
  GraphQL app;

  // Have 2 ways to declare a GraphQL query,

  // Search by the name of class and member (with sugar sintax)
  // Recomended because it's type safe and named at compile type
  // regsiter a GraphQL query behaviour
  app.Query QL_MEMBER(Custumer, id,
                      {  // query by id
                        Custumer custumer;
                        custumer.id = id;
                        custumer.name = "none";
                        return custumer;  // return the full data
                      }  // GraphQL take care of just return what is needed
  );

  // Raw C++17 with customizable renaming members (without sugar sintax)
  // regsiter a GraphQL query behaviour
  app.Query<Custumer>("custumer", "id",  // Set query name of type and member
                      [](string id) {    // query by id
                        Custumer custumer;
                        custumer.id = id;
                        custumer.name = "none";
                        return custumer;  // return the full data
                      }  // GraphQL take care of just return what is needed
  );

  std::cout <<     // put on console
      app.Digest(  // this query result
          "{                          "
          "  custumer(id : \"1\") {   "
          "    id                     "
          "    name                   "
          "  }                        "
          "}                          ")
            << std::endl;

  /* Expected reponse:
      {
        "data" : {
          "custumer" : {
            "id" : "1",
            "name" : "none"
          }
        }
      }
   */
}
