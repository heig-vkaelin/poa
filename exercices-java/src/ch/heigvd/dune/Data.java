package ch.heigvd.dune;

import java.util.*;
import java.util.stream.*;

public class Data
{
  private static final Random GENERATOR = new Random(42);
  
  public static int randomInt(int min, int max) {
    return GENERATOR.nextInt(max - min) + min;
  }
  
  // Valeurs fixes, uniquement utilisées pour les tests
  private static final Extraction[] EXTRACTED_VALUES = {
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random(),
    Extraction.random()
  };
  
  public static Stream<Extraction> asStream() {
    return Stream.of(EXTRACTED_VALUES);
  }
  
  public static List<Extraction> asList() {
    return Arrays.asList(EXTRACTED_VALUES);
  }
}
