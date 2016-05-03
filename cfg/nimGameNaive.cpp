/*


Two players are given an array of positive integers. They make moves one after another. During a move one should decrease exactly one element of the array by some integer. The one, after whose move the array contains a negative integer, loses.

Who wins the game assuming both play optimally?

Example

    For sequence = [2], the output should be
    nimGameNaive(sequence) = true;
    For sequence = [2, 2], the output should be
    nimGameNaive(sequence) = false.

    [input] array.integer sequence

    Array of positive integers.

    [output] boolean

    true if the first player wins, false otherwise.



*/


//https://codefights.com/task/prTdxKfJWK5HNhuN3
bool nimGameNaive(std::vector<int> sequence) {

  for (int i = 0; i < sequence.size(); i++) {
    int tmp = sequence[i];
    for (int j = 0; j < tmp; j++) {
      sequence[i] = j;

      if (!nimGameNaive(sequence)) {
        return  true ; //...
      }
    }
    sequence[i] = tmp;
  }
  return false;
}

