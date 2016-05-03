/*
Determine if the given directed graph is a tournament.  
Example 
For

`n` = 5,
`from` = [2, 1, 3, 4, 4, 4, 1, 2, 3, 4],
`to`   = [3, 2, 1, 3, 2, 1, 5, 5, 5, 5]

the output should be
isTournament(n, from, to) = true.

    [input] integer n

    A positive integer n representing the number of vertices in the given graph.

    [input] array.integer from

    An array of integers containing integers less than or equal to n.

    [input] array.integer to

    An array of the same length as from containing integers less than or equal to n. For each i in range [0, from.length) there is an edge from the vertex number from[i] to the vertex to[i] in the given directed graph.

    [output] boolean

    true if the given graph is a tournament, false otherwise.

*/

// https://codefights.com/task/BEBpSkgBzfwozvobC
bool isTournament(int n, std::vector<int> from, std::vector<int> to) {

  std::vector<bool> line(n, false);
  std::vector<std::vector<bool>> edges(n, line);

  for (int i = 0; i < from.size(); i++) {
    edges[ from[i] - 1 ][ to[i] - 1 ] = true;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!(edges[i][j] ^ edges[j][i])) {
        return  ... ; // false
      }
    }
  }

  if (from.size() != n * (n - 1) / 2) {
    return false;
  }
  return true;
}


