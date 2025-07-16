#include <bits/stdc++.h>

using namespace std;

namespace program
{
	namespace IO
	{
		struct input_t
		{
			static const int BUF_SIZ = 500000;
			FILE *f;
			char Buf[BUF_SIZ], *p, *pend;
			input_t(FILE *_f) : f(_f), p(Buf), pend(Buf) {}
			~input_t() { fclose(f); }
			char getchar();
			template <typename T>
			T read();
		};

		char input_t::getchar()
		{
			if (p >= pend)
			{
				p = Buf;
				pend = Buf + fread(Buf, sizeof(char), BUF_SIZ, f);
				if (p >= pend)
					return EOF;
			}
			return *p++;
		}

		template <typename T>
		T input_t::read()
		{
			T s = 0;
			int fl = 0;
			char ch;
			while (!isdigit(ch = getchar()))
				fl ^= (ch == '-');
			do
				s = s * 10 + ch - '0';
			while (isdigit(ch = getchar()));
			return fl ? -s : s;
		}

		struct output_t
		{
			static const int BUF_SIZ = 500000;
			FILE *f;
			char Buf[BUF_SIZ], *p, *const pend;
			output_t(FILE *_f) : f(_f), p(Buf), pend(Buf + BUF_SIZ) {}
			~output_t()
			{
				fwrite(Buf, sizeof(char), p - Buf, f);
				fclose(f);
			}
			void putchar(char ch);
			template <typename T>
			void write(T x);
			void puts(const char *ch);
		};

		void output_t::putchar(char ch)
		{
			*p++ = ch;
			if (p >= pend)
			{
				fwrite(Buf, sizeof(char), p - Buf, f);
				p = Buf;
			}
		}

		template <typename T>
		void output_t::write(T x)
		{
			static char St[30];
			char *top = St;
			if (x < 0)
			{
				putchar('-');
				x = -x;
			}
			do
				*top++ = x % 10 + '0';
			while (x /= 10);
			while (top > St)
				putchar(*--top);
		}

		void output_t::puts(const char *ch)
		{
			while (*ch)
				putchar(*ch++);
			putchar('\n');
		}
	}

	IO::input_t input(stdin);
	IO::output_t output(stdout);

	typedef long long big;

	const int MAXN = 100000;

	template <typename T>
	vector<T> &operator*=(vector<T> &A, vector<int> B)
	{
		vector<T> C = A;
		for (int i = 0; i < A.size(); i++)
			A[i] = C[B[i]];
		return A;
	}

	template <typename T1, typename T2>
	void qpow(T1 &S, T2 X, big n)
	{
		while (n)
		{
			if (n & 1)
				S *= X;
			X *= X;
			n >>= 1;
		}
	}

	void work()
	{
		int n = input.read<int>(), m;
		big k;
		vector<big> X;
		vector<int> C;
		for (int i = 0; i < n; i++)
		{
			X.push_back(input.read<big>());
			C.push_back(i);
		}
		for (int i = n - 1; i > 0; i--)
			X[i] -= X[i - 1];
		m = input.read<int>();
		k = input.read<big>();
		while (m--)
		{
			int x = input.read<int>();
			swap(C[x - 1], C[x]);
		}
		qpow(X, C, k);
		for (int i = 1; i < n; i++)
			X[i] += X[i - 1];
		for (int i = 0; i < n; i++)
		{
			output.write(X[i]);
			output.puts(".0");
		}
	}
}

int main()
{
	program::work();
	return 0;
}
