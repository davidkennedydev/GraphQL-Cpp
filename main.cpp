#include <iostream>
#include <string>
#include "graphql.h"

#include "custumer.h"

using std::string;

int main(void)
{
  // Create a GraphQL digester
  GraphQL app;

  // regsiter a GraphQL query behaviour
  app.Query<Custumer>("custumer", // to custumer node
      [](string id) { // query by id
        Custumer custumer;
        custumer.id = id;
        custumer.name = "none";
        return custumer; // return the full data
      } // GraphQL take care of just return what is needed
  );

  std::cout << // put on console
    app.Digest( // this query result
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

