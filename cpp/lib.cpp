#include "lib.h"
#include <vector>
#include <format>
#include <cassert>
#include <map>

const std::string lady_intro = "There was an old lady who swallowed";

const std::string verse_intro(const std::string &animal,
                              const std::vector<std::string> &animal_names) {
    std::string res = std::format("{} a {}", lady_intro, animal);
    std::string punctuation = ";";
    if (animal == animal_names.front()) {
        punctuation = ".";
    } else if (animal == animal_names.back()) {
        punctuation = "...";
    }

    return res + punctuation + '\n';
}

const std::string verse_conclusion(const std::string &animal,
                              const std::vector<std::string> &animal_names) {
    const std::string death_line = "...She's dead, of course!";

    if (animal == animal_names.back()) {
        return death_line;
    }
    return std::format(
        "I don't know why she swallowed a {} - perhaps she'll die!\n", animal);
}

const std::string verse_comment(const std::string &animal)
{
    std::map<std::string, std::string> comments_for_animal = {
        {"fly", ""},
        {"spider", "That wriggled and wiggled and tickled inside her.\n"},
        {"bird", "How absurd to swallow a bird.\n"},
        {"cat", "Fancy that to swallow a cat!\n"},
        {"dog", "What a hog, to swallow a dog!\n"},
        {"cow", "I don't know how she swallowed a cow!\n"},
        {"horse", ""}
    };
    return comments_for_animal.at(animal);

}

const std::string rescue_attempts(const std::vector<std::string> &animal_names,
                              size_t depth)
{
    if (depth == 0) {
        return "";
    }
    const auto &inner = animal_names[depth - 1];
    const auto &outer = animal_names[depth];

    std::string separator = depth == 1 ? ";\n" : ",\n";

    std::string line = std::format("She swallowed the {} to catch the {}",
        outer, inner);

    return line + separator + rescue_attempts(animal_names, depth-1);
}

const std::string get_verse(size_t n)
{

    const std::vector<std::string> animal_names = {
        "fly", "spider", "bird", "cat", "dog", "cow", "horse"
    };

    const std::vector<std::string> verses = {
            verse_intro("fly", animal_names) +
            verse_comment("fly") +
            verse_conclusion("fly", animal_names),

            verse_intro("spider", animal_names) +
            verse_comment("spider") +
            "She swallowed the spider to catch the fly;\n" +
            verse_conclusion("fly", animal_names),

            verse_intro("bird", animal_names) +
            verse_comment("bird") +
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" +
            verse_conclusion("fly", animal_names),

            verse_intro("cat", animal_names) +
            verse_comment("cat") +
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" +
            verse_conclusion("fly", animal_names),

            verse_intro("dog", animal_names) +
            verse_comment("dog") +
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" +
            verse_conclusion("fly", animal_names),

            verse_intro("cow", animal_names) +
            verse_comment("cow") +
            "She swallowed the cow to catch the dog,\n" \
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" +
            verse_conclusion("fly", animal_names),

            verse_intro("horse", animal_names) +
            verse_comment("horse") +
            verse_conclusion("horse", animal_names)
    };

    assert(animal_names.size() == verses.size());

    if (n >= verses.size()) {
        return "";
    }
    return verses.at(n);

}

const std::string get_continuation(size_t starting_verse)
{
    auto verse = get_verse(starting_verse);

    if (verse.size() == 0) {
        return verse;
    }
    return verse + "\n" + get_continuation(starting_verse + 1);
}

const std::string chop_final_newline(std::string in)
{
    if (in.back() == '\n') {
        in.pop_back();
    }
    return in;
}

const std::string get_song()
{
    return chop_final_newline(get_continuation(0));
}
