#pragma once

#include <exception>
#include <string>

class SongException : public std::exception
{
public:
    explicit SongException(const std::string& errorDescription) : errorDescription_(errorDescription) {}

    const char* what() const noexcept override
    {
        return errorDescription_.c_str();
    }

private:
    std::string errorDescription_;
};
