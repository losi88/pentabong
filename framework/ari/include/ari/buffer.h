
#pragma once

#include "ari/ari.h"

namespace ari {
class ARI_API Buffer {
private:
    static const size_t _MIN_CAPACITY;

public:
    Buffer();
    Buffer(const size_t size, const char* data);
    Buffer(const Buffer& buffer);
    Buffer(Buffer&& buffer) noexcept;
    virtual ~Buffer();

public:
    bool Append(const size_t size, const char* data);
    bool Append(const Buffer& buffer);

public:
    size_t Size() const { return _size; }
    const char* Raw() const { return _data; }

private:
    size_t calculateNewCapacity(const size_t size) const;

    bool resize(const size_t size);
    bool set(const size_t size, const char* data);
    bool append(const size_t size, const char* data);

private:
    size_t _capacity;
    size_t _size;
    char* _data;
};
}  // namespace ari