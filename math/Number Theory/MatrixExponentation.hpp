#include <vector>
using ll = long long;

class Matrix
{
private:
    int rows, cols;
    std::vector<std::vector<ll>> mat;
    ll MOD;
public:
    Matrix(int r, int c, ll mod) : rows(r), cols(c), MOD(mod)
    {
        mat.resize(r, std::vector<ll>(c, 0));
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix result(rows, other.cols, MOD);
        for (int i = 0; i < rows; ++i)
            for (int k = 0; k < cols; ++k)
                for (int j = 0; j < other.cols; ++j)
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        return result;
    }

    Matrix pow(ll exponent) const
    {
        Matrix result(rows, cols, MOD);
        for (int i = 0; i < std::min(rows, cols); ++i)
            result.mat[i][i] = 1;

        Matrix base = *this;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
                result = result * base;
            base = base * base;
            exponent /= 2;
        }
        return result;
    }
};