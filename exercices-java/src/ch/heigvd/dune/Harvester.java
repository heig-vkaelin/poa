package ch.heigvd.dune;

public class Harvester
{
  private int spice = 0;
  private int durability = 100;
  
  public int spice() { return spice; }

  public int durability() { return Math.max(durability, 0); }

  public void process(Extraction e) {
    if (e.type() == Resource.Spice)
      spice += e.quantity();
    durability -= e.type().hardness() * e.quantity();
  }
  
  @Override
  public String toString() {
    return String.format("Récolte de %d unités d'épice. Durabilité: %d.",
			 spice(), durability());
  }
}

