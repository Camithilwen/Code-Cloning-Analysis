/**
 * @brief 8クイーン問題を扱う
 *
 * @date 2016/02/29
 */



//****************************************
// 必要なヘッダファイルのインクルード
//****************************************

#include <iostream>
#include <vector>



//****************************************
// 型シノニム
//****************************************

using array1D = std::vector<int>;
using array2D = std::vector<array1D>;



//****************************************
// 大域変数の定義
//****************************************

static const int N = 8;                 /**< マスの数 */
static const int FREE = 0, NOFREE = 1;  /**< クイーンが配置できるか否か */



//****************************************
// 構造体の定義
//****************************************

struct board {
    array1D row;    /**< row[x]がNOFREEならば行xは被襲撃位置 */
    array1D col;    /**< col[x]がNOFREEならば列xは被襲撃位置 */
    array1D dpos;   /**< dpos[x]がNOFREEならば左下の列xは被襲撃位置 */
    array1D dneg;   /**< dneg[x]がNOFREEならば右下の列xは被襲撃位置 */
    
    array2D state;  /**< 盤面の状態  */

    board() : row(N, FREE), col(N, FREE),
              dpos(2 * N - 1, FREE), dneg(2 * N - 1, FREE),
              state(N, array1D(N, FREE)) { }

    /**< 盤面の状態を印刷する */
    void print()
    {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (state[y][x] && row[y] != x) { return; }
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                std::cout << ((row[y] == x) ? "Q" : ".");
            }
            std::cout << std::endl;
        }
    }

    /**< @brief 座標(x, y)にQueenを配置する */
    void move(int x, int y)
    {
        row[y] = x;
        col[x] = dpos[y + x] = dneg[y - x + N - 1] = NOFREE;
    }

    /**< @brief 座標(x, y)からQueenを取り除く */
    void undo(int x, int y)
    {
        row[y] = col[x] = dpos[y + x] = dneg[y - x + N - 1] = FREE;
    }

    /**< @brief 座標(x, y)にQueenを配置可能かどうか調べる */
    bool canMove(int x, int y)
    {
        return !(col[x] || dpos[y + x] || dneg[y - x + N - 1]);
    }

    /**
     * @brief 再帰的に盤面を探索し、Queenが配置できる場所を探す
     * @param 探索対象のy座標
     */
    void visit(int y)
    {
        // Queenの配置に成功した
        if (y >= N) { print(); return; }
    
        for (int x = 0; x < N; x++) {
            // 座標(x, y)が配置不可能な場合、continue
            if (!canMove(x, y)) { continue; }
       
            move(x, y);    // 座標(x, y)にQueenを配置する
               
            visit(y + 1);  // 次の行へ再帰

            undo(x, y);    // 座標(x, y)からQueenを取り除く
        }
    }

    /**< @brief 座標(x, y)にQueenを初期段階で配置する */
    void initqueen(int x, int y)
    {
        state[y][x] = true;
    }
};



//****************************************
// 関数の定義
//****************************************

int main()
{
    using namespace std;
    board B;

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        B.initqueen(c, r);
    }

    B.visit(0);

    return 0;
}