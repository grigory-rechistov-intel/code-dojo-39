#include "lib.h"
#include <vector>
#include <format>
#include <cassert>

const std::string lady_intro = "There was an old lady who swallowed";

const std::string get_verse(size_t n)
{

    const std::vector<std::string> animal_names = {
        "fly", "spider", "bird", "cat", "dog", "cow", "horse"
    };

    const std::vector<std::string> verses = {
            std::format("{} a fly.\n", lady_intro) +
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a spider;\n", lady_intro) +
            "That wriggled and wiggled and tickled inside her.\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a bird;\n", lady_intro) +
            "How absurd to swallow a bird.\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a cat;\n", lady_intro) +
            "Fancy that to swallow a cat!\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a dog;\n", lady_intro) +
            "What a hog, to swallow a dog!\n" \
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a cow;\n", lady_intro) +
            "I don't know how she swallowed a cow!\n" \
            "She swallowed the cow to catch the dog,\n" \
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            std::format("{} a horse...\n", lady_intro) +
            "...She's dead, of course!"
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
