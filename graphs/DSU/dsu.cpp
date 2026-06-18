#include <utility>

class DSU
{
  int n;
  bool compression;

  int *rank;
  int *size;
  int *parent;

public:
  DSU(int n, bool compression = true) : n(n), compression(compression)
  {
    rank = new int[n + 1]{};
    size = new int[n + 1]{};
    parent = new int[n + 1]{};
    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x)
  {
    if (!compression)
    {
      while (parent[x] != x)
        x = parent[x];
      return x;
    }

    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite_by_rank(int a, int b)
  {
    a = find(a);
    b = find(b);

    if (a != b)
    {
      if (rank[a] < rank[b])
        std::swap(a, b);

      parent[b] = a;

      size[a] += size[b];

      if (rank[a] == rank[b])
        rank[a]++;
    }
  }

  void unite_by_size(int a, int b)
  {
    a = find(a);
    b = find(b);

    if (a != b)
    {
      if (size[a] < size[b])
        std::swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }

  int getSize(int x)
  {
    return size[find(x)];
  }

  ~DSU()
  {
    delete[] rank;
    delete[] size;
    delete[] parent;
  }
};