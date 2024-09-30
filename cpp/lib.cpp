#include "lib.h"
#include <vector>

const std::string get_verse(size_t n)
{
    const std::vector<std::string> verses = {
            "There was an old lady who swallowed a fly.\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a spider;\n" \
            "That wriggled and wiggled and tickled inside her.\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a bird;\n" \
            "How absurd to swallow a bird.\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a cat;\n" \
            "Fancy that to swallow a cat!\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a dog;\n" \
            "What a hog, to swallow a dog!\n" \
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a cow;\n" \
            "I don't know how she swallowed a cow!\n" \
            "She swallowed the cow to catch the dog,\n" \
            "She swallowed the dog to catch the cat,\n" \
            "She swallowed the cat to catch the bird,\n" \
            "She swallowed the bird to catch the spider,\n" \
            "She swallowed the spider to catch the fly;\n" \
            "I don't know why she swallowed a fly - perhaps she'll die!\n",

            "There was an old lady who swallowed a horse...\n" \
            "...She's dead, of course!"
    };

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
