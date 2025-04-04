#pragma once

#include <filesystem>
#include <concepts>

template<class T>
concept PathLike = std::convertible_to<T, std::filesystem::path>;
