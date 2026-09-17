#include <iostream>
#include <string>
using namespace std;

// Strongly typed enum class for HTTP status codes
enum class HTTPStatus
{
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

// Function to handle HTTP response
void handleResponse(HTTPStatus status, const string& endpoint)
{
    cout << "[" << endpoint << "] -> ";

    switch (status)
    {
        case HTTPStatus::OK:
            cout << "200 OK - Request successful";
            break;

        case HTTPStatus::Created:
            cout << "201 Created - Resource created";
            break;

        case HTTPStatus::BadRequest:
            cout << "400 Bad Request - Invalid request";
            break;

        case HTTPStatus::Unauthorized:
            cout << "401 Unauthorized - Authentication required";
            break;

        case HTTPStatus::NotFound:
            cout << "404 Not Found - Resource not found";
            break;

        case HTTPStatus::ServerError:
            cout << "500 Server Error - Internal server error";
            break;

        default:
            cout << "Unknown status";
    }

    cout << endl;
}

int main()
{
    handleResponse(HTTPStatus::OK, "/api/users");
    handleResponse(HTTPStatus::Unauthorized, "/api/login");
    handleResponse(HTTPStatus::NotFound, "/api/profile");
    handleResponse(HTTPStatus::ServerError, "/api/payment");

    return 0;
}/*
 *  Network Request Dispatcher A.cpp
 *
 *  Created on: 16-Sept-2026
 *      Author: chaitanya
 */




