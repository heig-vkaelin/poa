package ch.heigvd.dune;

import java.util.*;

public class Extraction
{
  private final Resource type;
  private final int quantity;

  Extraction(Resource type, int quantity) {
    this.type = type;
    this.quantity = quantity;
  }
  
  public Resource type() { return type; }

  public int quantity() { return quantity; }

  @Override
  public String toString() {
    return String.format("[%s: %d]", type.name().toLowerCase(), quantity);
  }

  public boolean equals(Object o) {
    if (o == this)
      return true;
    
    if (o == null || o.getClass() != getClass())
      return false;
    
    Extraction e = (Extraction) o;
    return e.type() == type() && e.quantity() == quantity();
  }

  public int hashCode() {
    return Objects.hash(type, quantity);
  }
  
  public static Extraction random() {
    Resource[] types = Resource.values();
    return random(types[Data.randomInt(0, types.length)]);
  }

  public static Extraction random(Resource type) {
    return new Extraction(type, Data.randomInt(1, 5));
  }
}
