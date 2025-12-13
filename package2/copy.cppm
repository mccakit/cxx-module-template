export module copy;
import std;
export namespace copy
{
    void copy(const char* src, char* dest, std::size_t n)
    {
        std::copy(src, src + n, dest);
    }
} // namespace copy
