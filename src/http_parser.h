#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>

typedef enum http_method_t {
    GET,    // 0
    PUT,    // 1
    DELETE, // 2
    other,  // 3
}http_method_t;

typedef enum http_version_t {
    v1_0,           // 0
    v1_1,           // 1
    not_specified,  // 2
}http_version_t;

typedef struct header_list_t{
    char key[16];
    char value[256];
    struct header_list_t *next;
}header_list_t;

typedef struct {
    http_method_t method; // GET, PUT, DELETE, ...
    char uri[256]; //paht to resource
    http_version_t version; // 1.0 or 1.1
    bool valid; // True if ok Flase if not 
    header_list_t* headers;
} http_request_t;

/* --------- FUNCTION TO PARSE A HTPPREQEUST--------
*<HTTP method>  <URI> <HTTP version>
* example GET /index.html HTTP/1.1
*/
http_request_t parse_http_request (const char* packet);


// Helper function to find a header in a header_list_t by a given key
// inputs: pointer to a header_list_t and the key
// return pointer to the header_list_t elemenent on success, NULL if such key does not exists in the list
const char* find_header_value_by_key (const header_list_t *headers, const char *key);

#endif
