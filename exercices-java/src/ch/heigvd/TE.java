package ch.heigvd;

// Nom: Valentin Kaelin

import ch.heigvd.dune.*;

import java.util.*;
import java.util.concurrent.atomic.AtomicReference;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.*;

public class TE {
    public static void main(String... args) {
        { // 1
            Printer.questionTitle("Plus grande quantité de pierre extraite (sans flux/boucle)");
            Extraction resultat =
                    Collections.max(Data.asList(),
                            Comparator.comparing(e -> e.type() == Resource.Rock ?
                                    e.quantity() : Integer.MIN_VALUE)
                    );

            System.out.println(resultat != null &&
                    resultat.type() == Resource.Rock ? resultat.quantity() : 0);
        }
        { // 2
            Printer.questionTitle("Epice extraite (avec un flux)");
            List<Extraction> resultat = Data.asStream()
                    .filter(e -> e.type() == Resource.Spice)
                    .collect(Collectors.toList());

            Printer.printList(resultat);
        }
        { // 3
            Printer.questionTitle("Epice extraite (avec un flux, mais sans lambda)");
            Stream<Extraction> resultat = Data.asStream()
                    .filter(new Predicate<Extraction>() {
                        @Override
                        public boolean test(Extraction e) {
                            return e.type() == Resource.Spice;
                        }
                    });

            Printer.printStream(resultat, ", ");
        }
        { // 4
            Printer.questionTitle("Stream des 7 premières extractions uniques, " +
                    "triées par nom de type croissant et par quantité décroissante");
            Stream<Extraction> resultat = Data.asStream()
                    .distinct()
                    .sorted(Comparator.comparing((Extraction e) -> e.type().name())
                            .thenComparing(Extraction::quantity, Comparator.reverseOrder()))
                    .limit(7);

            Printer.printStream(resultat, "\n");
        }
        { // 5
            Printer.questionTitle("Fonctionnement de la moissonneuse et " +
                    "comptage du nombre d'extractions d'épice");
            Harvester h = new Harvester();
            Stream<Extraction> data = Utils.harvest(h, Data.asStream());
            long numberSpiceExtractions = data.filter(e -> e.type() == Resource.Spice)
                    .count();

            System.out.println(h + " Extractions: " + numberSpiceExtractions);
        }
        { // 6
            Printer.questionTitle("Quantité de pierres extraites par la moissonneuse (sumInt)");
            Harvester h = new Harvester();
            int nbRocks = Utils.sumInt(
                    Utils.harvest(h, Data.asStream()),
                    e -> e.type() == Resource.Rock ? e.quantity() : 0);

            System.out.println(
                    String.format("La moissonneuse a extrait %d unités de pierre.",
                            nbRocks));
        }
        {
            Printer.questionTitle("Flux d'extractions infini");
            Harvester h = new Harvester();
            int maxExtractions = 50;
            Map<Resource, Integer> extracted = new TreeMap<>();
            Stream<Extraction> s = Utils.harvest(h, Utils.infiniteExtractionsStream());

            s.limit(maxExtractions)
                    .forEach(
                            e -> extracted.merge(e.type(), e.quantity(), Integer::sum)
                    );

            System.out.println(h + " Extractions: " + maxExtractions);
            extracted.forEach((l, nb) -> {
                System.out.println("> " + l + ": " + nb);
            });
        }
    }
}

class Utils {
    // 5
    public static Stream<Extraction> harvest(
            Harvester h, Stream<Extraction> extractions) {
        return extractions.map(e -> {
            if (h.durability() > 0) {
                h.process(e);
                return e;
            }
            return Extraction.random(Resource.Sand);
        });
    }

    // 6
    public static int sumInt(Stream<Extraction> extractions, Function<Extraction, Integer> f) {
        return extractions.map(f).reduce(0, Integer::sum);
    }

    public static Stream<Extraction> infiniteExtractionsStream() {
        // Méthode rendue de débile...
//        AtomicReference<Resource> lastExtractionType = new AtomicReference<>();
//        return Stream.generate(() -> {
//            Extraction e;
//            if (lastExtractionType.get() == Resource.Spice) {
//                e = Extraction.random(Resource.Sand);
//            } else {
//                e = Extraction.random();
//            }
//            lastExtractionType.set(e.type());
//            return e;
//        });

        return Stream.iterate(Extraction.random(), e -> {
            if (e.type() == Resource.Spice)
                return Extraction.random(Resource.Sand);

            return Extraction.random();
        });
    }
}
