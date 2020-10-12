private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun f(x: Int): Int {
  var cur = x + 1
  while (cur % 10 == 0) cur /= 10
  return cur
}

fun main() {
  var n = readInt()
  var reached = HashSet<Int>()
  while (reached.add(n)) n = f(n)
  println(reached.size)
}
