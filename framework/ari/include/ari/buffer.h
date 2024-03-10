
#pragma once

#include "ari/ari.h"

namespace ari {
class ARI_API Buffer {
public:
    static const size_t _MIN_CAPACITY;
    static const size_t _MAX_CAPACITY;

public:
    Buffer();
    Buffer(const size_t size);
    Buffer(const size_t size, const char* data);
    Buffer(const Buffer& buffer);
    Buffer(Buffer&& buffer) noexcept;
    virtual ~Buffer();

public:
    bool Set(const size_t size, const char* data);
    bool Set(const Buffer& buffer);
    bool Append(const size_t size, const char* data);
    bool Append(const Buffer& buffer);

public:
    size_t Capacity() const { return _capacity; }
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