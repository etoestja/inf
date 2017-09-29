def fib(n: Int): Int = {
  def fibt(k: Int, a: Int, b: Int): Int = {
    if(k >= n) b
    else fibt(k + 1, b, a + b)
  }
  fibt(1, 0, 1)
}
