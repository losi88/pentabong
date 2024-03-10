
#include "ari/buffer.h"

namespace ari {
const size_t Buffer::_MIN_CAPACITY = 1024;
const size_t Buffer::_MAX_CAPACITY = 1024 * 1024;

Buffer::Buffer() {
    _capacity = 0;
    _size = 0;
    _data = nullptr;
}

Buffer::Buffer(const size_t size) {
    _capacity = 0;
    _size = 0;
    _data = nullptr;
    resize(size);
}

Buffer::Buffer(const size_t size, const char* data) {
    _capacity = 0;
    _size = 0;
    _data = nullptr;
    set(size, data);
}

Buffer::Buffer(const Buffer& buffer) {
    _capacity = buffer._capacity;
    set(buffer._size, buffer._data);
}

Buffer::Buffer(Buffer&& buffer) noexcept {
    _capacity = std::move(buffer._capacity);
    _size = std::move(buffer._size);
    _data = std::move(buffer._data);
}

Buffer::~Buffer() {
    _capacity = 0;
    _size = 0;
    if (_data) {
        free(_data);
    }
}

bool Buffer::Set(const size_t size, const char* data) {
    return set(size, data);
}

bool Buffer::Set(const Buffer& buffer) {
    return Set(buffer.Size(), buffer.Raw());
}

bool Buffer::Append(const size_t size, const char* data) {
    return append(size, data);
}

bool Buffer::Append(const Buffer& buffer) {
    return Append(buffer.Size(), buffer.Raw());
}

size_t Buffer::calculateNewCapacity(const size_t size) const {
    size_t newCapacity = _capacity;
    if (newCapacity < _MIN_CAPACITY) {
        newCapacity = _MIN_CAPACITY;
    }

    while (size > newCapacity) {
        newCapacity *= 2;
    }
    return newCapacity;
}

bool Buffer::resize(const size_t size) {
    size_t newCapacity = calculateNewCapacity(size);
    if (_capacity >= newCapacity) {
        return true;
    }

    _capacity = newCapacity;

    if (_data) {
        char* newData = (char*)realloc(_data, _capacity * sizeof(char));
        if (newData) {
            _data = newData;
        }
    } else {
        _data = (char*)calloc(_capacity, sizeof(char));
    }

    if (!_data) {
        return false;
    }

    return true;
}

bool Buffer::set(const size_t size, const char* data) {
    if (false == resize(size)) {
        return false;
    }

    _size = size;
    memcpy(_data, data, _size);
    return true;
}
bool Buffer::append(const size_t size, const char* data) {
    if (false == resize(_size + size)) {
        return false;
    }

    memcpy(_data + _size, data, size);
    _size += size;
    return true;
}
}  // namespace ari