#ifndef EF_SHIM_H_
#define EF_SHIM_H_

#include <memory>

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
std::unique_ptr<T[]> make_unique(std::size_t size) {
    return std::unique_ptr<T[]>(new T[size]);
}

template <typename T, std::size_t N>
constexpr std::size_t size(const T (&)[N]) noexcept {
    return N;
}

#endif
