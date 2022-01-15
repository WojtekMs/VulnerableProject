#include "networking/CharBuffer.hpp"
#include <cstring>

namespace networking {
CharBuffer::CharBuffer(unsigned int size) {
    buffer_ = new char[size];
    size_ = size;
}

CharBuffer::~CharBuffer() noexcept {
    delete [] buffer_;
}

char* CharBuffer::getBuffer() noexcept {
    return buffer_;
}

std::string CharBuffer::getString() const {
    return std::string(buffer_);
}

void CharBuffer::clear() {
    std::memset(buffer_, 0, size_);
}
}

