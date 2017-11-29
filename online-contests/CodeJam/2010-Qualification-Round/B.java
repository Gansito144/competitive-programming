import java.util.*;
import java.math.*;
import java.io.*;

public class B
{
  public static void main (String args[]) 
  {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for (int tc=1; tc<=cases; ++tc)
    {
      int N = in.nextInt();
      BigInteger [] Arr = new BigInteger[N];
      for (int i=0; i<N; ++i)
      {
        Arr[i] = in.nextBigInteger();
      }
      BigInteger G = Arr[1].subtract(Arr[0]).abs();
      for (int i=2; i<N; ++i)
      {
        G = G.gcd(Arr[i].subtract(Arr[i-1]).abs());
      }
      BigInteger ans = G.subtract(Arr[0].mod(G)).mod(G);
      System.out.println("Case #" + tc + ": " + ans);
    }
  }
}

