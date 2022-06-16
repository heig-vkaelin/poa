package ch.heigvd.company;

import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Company {
    public static void main(String... args) {
        List<Developer> developers = Data.randomDevs();

        System.out.println("-- 1. Coffee addict :");
        Developer addict = Collections.max(developers, Comparator.comparing(Developer::coffeeConsumption));

        System.out.println(String.format("> %s with %.2f dl.",
                addict.name(),
                addict.coffeeConsumption() / 100.0));


        System.out.println("\n-- 2. Most fluent developer :");
        Developer mostFluent = Collections.max(developers,
                Comparator.comparing(new Function<Developer, Integer>() {
                    @Override
                    public Integer apply(Developer d) {
                        return d.skills().size();
                    }
                })
        );

        System.out.println("> " + mostFluent.name());


        System.out.println("\n-- 3. Number of developers knowing 3+ languages");
        long geeks = developers.stream()
                .filter(d -> d.skills().size() >= 3)
                .count();

        System.out.println(String.format("> %d devs", geeks));


        System.out.println("\n-- 4. Cat lovers :");
        String cats = developers.stream()
                .filter(d -> d.hobbies().contains(Hobby.Cats))
                .map(Developer::name)
                .collect(Collectors.joining(", "));

        System.out.println(String.format("> %s", cats.isEmpty() ? "none" : cats));


        System.out.println("\n-- 5. Most hobbies :");
        Developer[] mostHobbies = developers.stream()
                .sorted(Comparator.comparing(d -> d.hobbies().size(), Comparator.reverseOrder()))
                .limit(3)
                .toArray(Developer[]::new);

        for (Developer d : mostHobbies)
            System.out.println("> " + d.name());


        System.out.println("\n-- 6. Total coffee consumption of Java coders");
        int milliliters = developers.stream()
                .filter(d -> d.skills().stream().anyMatch(s -> s.language() == Language.Java))
                .collect(Collectors.summingInt(Developer::coffeeConsumption));

        System.out.println(String.format("> %.3f l", milliliters / 1000.0));


        System.out.println("\n-- 7. Number of people knowing each language");

        Map<Language, Integer> devsPerLanguage = new TreeMap<>();
        //  devsPerLanguage.merge(s.language(), 1, (old, value) -> old + value)
        developers.forEach(d -> d.skills().forEach(
                s -> devsPerLanguage.merge(s.language(), 1, Integer::sum))
        );

        devsPerLanguage.forEach((l, nb) -> {
            System.out.println("> " + l + " : " + nb + " devs");
        });


        System.out.println("\n-- 8. Average number of code lines per day");
        double meanLines = averageOf(developers,
                Developer::skills, Skill::linesOfCodePerDay);

        System.out.println(String.format("> %.2f lines per day", meanLines));
    }

    private static <T, U> double averageOf(List<T> collection,
                                           Function<T, List<U>> listMapper,
                                           Function<U, Integer> valueMapper) {
        double sum = 0;
        int count = 0;
        for (T t : collection) {
            for (U u : listMapper.apply(t)) {
                sum += valueMapper.apply(u);
                count++;
            }
        }

        return count == 0 ? 0 : sum / count;
    }
}
