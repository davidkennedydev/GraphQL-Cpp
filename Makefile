all: graphql_server

graphql_server: main.cpp ./graphql.h
	g++ -std=c++17 $< -o $@

clean:
	-rm -f graphql_server
