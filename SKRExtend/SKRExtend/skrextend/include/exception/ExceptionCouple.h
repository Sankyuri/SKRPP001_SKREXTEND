#pragma once
#include <exception>


namespace skrex {


class ExceptionCouple : public std::exception {
public:

    ExceptionCouple() noexcept :
        exception(),
        m_dat1()
    {
    }

    explicit ExceptionCouple(const char *a_msg0, const char *a_msg1) noexcept :
        exception(a_msg0),
        m_dat1()
    {
        __std_exception_data _InitData = { a_msg1, true };
        __std_exception_copy(&_InitData, &m_dat1);
    }

    ExceptionCouple(const char *a_msg0, const char *a_msg1, int a_num) noexcept :
        exception(a_msg0, a_num),
        m_dat1()
    {
        m_dat1._What = a_msg1;
    }

    ExceptionCouple(const ExceptionCouple &a_other) noexcept :
        exception(a_other.what()),
        m_dat1()
    {
        __std_exception_copy(&a_other.m_dat1, &m_dat1);
    }

    ExceptionCouple(const exception &a_other) noexcept :
        exception(a_other),
        m_dat1()
    {
        // do nothing
    }

    ExceptionCouple &operator =(const ExceptionCouple &a_other) noexcept
    {
        if (this == &a_other)
        {
            return *this;
        }


        (std::exception)*this = (std::exception)a_other;
        __std_exception_destroy(&m_dat1);
        __std_exception_copy(&a_other.m_dat1, &m_dat1);
        return *this;
    }

    ExceptionCouple &operator =(const exception &a_other) noexcept
    {
        if (this == &a_other)
        {
            return *this;
        }
        
        __std_exception_destroy(&m_dat1);
        (std::exception)*this = (std::exception)a_other;
        return *this;
    }

    virtual ~ExceptionCouple() noexcept
    {
        __std_exception_destroy(&m_dat1);
    }

    _NODISCARD virtual char const* what0() const
    {
        return exception::what();
    }

    _NODISCARD virtual char const* what1() const
    {
        return m_dat1._What ? m_dat1._What : "Unknown exception";
    }

private:
    __std_exception_data m_dat1;
    
    // hide function
    _NODISCARD virtual char const* what() const override
    {
        return exception::what();
    }

};


} // namespace skrex



