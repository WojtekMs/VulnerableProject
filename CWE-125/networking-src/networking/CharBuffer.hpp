#pragma once

#include <string>

namespace networking {

class CharBuffer
{
    char* buffer_{};
    unsigned int size_{};

   public:
    CharBuffer() = delete;
    explicit CharBuffer(unsigned int size);
    ~CharBuffer() noexcept;
    CharBuffer(const CharBuffer&) = delete;
    CharBuffer(CharBuffer&&) = delete;
    CharBuffer& operator=(const CharBuffer&) = delete;
    CharBuffer& operator=(CharBuffer&&) = delete;
    char* getBuffer() noexcept;
    std::string getString() const;
    void clear();
};
}
