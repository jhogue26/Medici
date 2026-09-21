/*
 * Program name: Exception.h
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Defines the Exception class.
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidBidException : public std::runtime_error {
public:
    explicit
    InvalidBidException(const std::string& msg) : std::runtime_error(msg) {}
};

class ShipcapacityExceededException : public std::runtime_error {
public:
    explicit
    ShipcapacityExceededException(const std::string& msg) : std::runtime_error(msg) {}
};

class EmptyDeckException : public std::runtime_error {
public:
    explicit
    EmptyDeckException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif 