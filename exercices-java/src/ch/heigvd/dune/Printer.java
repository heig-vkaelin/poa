package ch.heigvd.dune;

import java.util.*;
import java.util.stream.*;

public class Printer
{
  private static int questionCounter = 0;

  public static void questionTitle(String title) {
    System.out.println(String.format("%s-- %d. %s",
        questionCounter > 0 ? "\n" : "",
        ++questionCounter, title));
  }

  public static <T> void printList(List<T> list) {
    printStream(list == null ? null : list.stream(), ", ");
  }

  public static <T> void printStream(Stream<T> stream, String delimiter) {
    if (stream == null) {
      System.out.println("pas de données");
    }
    else {
      Object[] elements = stream.toArray();
      StringBuilder sb = new StringBuilder();
      boolean first = true;
      for (Object o : elements) {
        if (!first)
          sb.append(delimiter);
        sb.append(o);
        first = false;
      }
      System.out.println(sb);
    }
  }
}

