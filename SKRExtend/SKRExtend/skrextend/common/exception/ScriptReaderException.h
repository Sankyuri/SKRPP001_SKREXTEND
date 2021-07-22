#pragma once
#include <exception>
#include <xstring>




namespace skrex {


class FileOpenException : public std::exception {
public:
    explicit FileOpenException(const std::string &a_fname) :
        std::exception(("FileOpenException:\n" + a_fname).c_str()) {}

    explicit FileOpenException(const char *a_fname) :
        std::exception(("FileOpenException:\n" + std::string(a_fname)).c_str()) {}


    explicit FileOpenException(const std::string &a_fname, const std::string &a_msg) :
        std::exception((
            "FileOpenException:\n" + a_fname + "\n" +
            a_msg).c_str()
        )
    {}

    explicit FileOpenException(const std::string &a_fname, const char *a_msg) :
        std::exception((
            "FileOpenException:\n" + a_fname + "\n" +
            a_msg).c_str()
        )
    {}

    explicit FileOpenException(const char *a_fname, const std::string &a_msg) :
        std::exception((
            "FileOpenException: " + std::string(a_fname) + "\n" +
            a_msg).c_str()
        )
    {}

    explicit FileOpenException(const char *a_fname, const char *a_msg) :
        std::exception((
            "FileOpenException: " + std::string(a_fname) + "\n" +
            std::string(a_msg)).c_str()
        )
    {}

};


} // namespace skrextend



