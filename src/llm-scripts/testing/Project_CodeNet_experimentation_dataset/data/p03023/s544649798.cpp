/* ＵＴＦ－８ */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <type_traits>
#include <limits>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define USE_COLORED 1

#ifdef USE_COLORED
static const char stdout_pre[]  = "\033[1m"; // bold black
static const char stderr_pre[]  = "\033[31;1m"; // bold red
static const char stdxxx_post[] = "\033[m";

// 当然ながら GCC(g++)/libstdc++ 依存
#include <ext/stdio_filebuf.h>
using stdio_filebuf = __gnu_cxx::stdio_filebuf<char>;
class colored_stdio_filebuf : public stdio_filebuf {
private:
	const char* const pre_;
	const char* const post_;

public:
	colored_stdio_filebuf(FILE* fp, const char* pre, const char* post) : stdio_filebuf(fp, std::ios_base::out), pre_(pre), post_(post)
	{
	}

protected:
	std::streamsize xsputn(const char* s, std::streamsize count) override
	{
		stdio_filebuf::xsputn(pre_, strlen(pre_));
		auto ret = stdio_filebuf::xsputn(s, count);
		stdio_filebuf::xsputn(post_, strlen(post_));
		return ret;
	}
};
#endif

int main()
{
#ifdef USE_COLORED
	if (getenv("DEBUG")) {
		std::cout.rdbuf(new colored_stdio_filebuf(stdout, stdout_pre, stdxxx_post));
		std::cerr.rdbuf(new colored_stdio_filebuf(stderr, stderr_pre, stdxxx_post));
	} else
#endif
	{
		int fd = open("/dev/null", O_WRONLY);
		dup2(fd, 2);
		close(fd);
	}
	
	int N;
	std::cin >> N;
	std::cout << (180 * (N-2)) << "\n";
}
