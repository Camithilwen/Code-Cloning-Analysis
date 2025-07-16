#include <cstdio>
using namespace std;

namespace roadagain
{

struct union_find_node
{
    unsigned parent;
    unsigned lank;

    union_find_node() = default;
    union_find_node(unsigned num)
    {
        this->parent = num;
        this->lank = 1;
    }
};

class union_find_tree
{
public:
    union_find_tree(unsigned size) : size(size), group(size)
    {
        this->forest = new union_find_node[size];
        for (unsigned i = 0; i < size; i++){
            this->forest[i] = union_find_node(i);
        }
    }
    ~union_find_tree()
    {
        delete[] this->forest;
    }

    unsigned get_size()
    {
        return (this->size);
    }

    unsigned get_group()
    {
        return (this->group);
    }

    void unite(unsigned a, unsigned b)
    {
        if (this->forest[a].lank <= this->forest[b].lank){
            this->forest[b].parent = this->forest[a].parent;
            this->forest[a].lank++;
        }
        else {
            this->forest[a].parent = this->forest[b].parent;
            this->forest[b].lank++;
        }
        this->group--;
    }

    unsigned find(unsigned num)
    {
        if (this->forest[num].parent == num){
            return (num);
        }
        return (this->forest[num].parent = find(this->forest[num].parent));
    }

    bool same(unsigned a, unsigned b)
    {
        return (this->find(a) == this->find(b));
    }

private:
    const unsigned size;
    unsigned group;
    union_find_node* forest;
};

}
using namespace roadagain;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

union_find_tree* uf;
char map[16][16];

void island(int y, int x)
{
    if (map[y][x] == '0') return;
    map[y][x] = '0';
    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (0 <= tx && tx < 12 && 0 <= ty && ty < 12){
            uf->unite(y * 12 + x, ty * 12 + tx);
            island(ty, tx);
        }
    }
}

int main()
{
    while (~scanf("%s", map[0])){
        for (int i = 1; i < 12; i++){
            scanf("%s", map[i]);
        }
        uf = new union_find_tree(12 * 12);

        int cnt = 0;
        for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++){
                if (map[i][j] == '1'){
                    cnt++;
                    island(i, j);
                }
            }
        }

        printf("%d\n", cnt);
        delete uf;
    }

    return 0;
}