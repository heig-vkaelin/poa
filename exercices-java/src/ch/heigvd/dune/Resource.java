package ch.heigvd.dune;

public enum Resource
{
  Spice(1), Sand(2), Rock(5);

  private int hardness;

  private Resource(int hardness) {
    this.hardness = hardness;
  }
  
  public int hardness() {
    return hardness;
  }
};
