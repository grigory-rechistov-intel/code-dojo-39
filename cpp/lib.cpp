#include "lib.h"
#include <vector>
#include <format>
#include <cassert>
#include <map>

class Animal {
    std::string name;
    public:
    Animal() = delete;
    std::string intro_punctuation;
    Animal(const std::string _name) {
        name = _name;
        intro_punctuation = ";";
    }
    const std::string verse_intro() {
        const std::string lady_intro = "There was an old lady who swallowed";
        std::string res = std::format("{} a {}", lady_intro, name);
        return res + intro_punctuation + '\n';
    }
    virtual const std::string verse_comment() = 0;
};

class StartingAnimal: public Animal {
    public:
    StartingAnimal(const std::string _name): Animal(_name) {
        intro_punctuation = ".";
    }
    virtual const std::string verse_comment() {
        return "";
    }
};

class RescueAnimal: public Animal {
    std::string comment;
    public:
    RescueAnimal(const std::string _name, const std::string _comment):
        Animal(_name), comment(_comment) {}
    virtual const std::string verse_comment() {
        return comment;
    }
};

class LethalAnimal: public Animal {
    public:
    LethalAnimal(const std::string _name): Animal(_name) {
        intro_punctuation = "...";
    }
    virtual const std::string verse_comment() {
        return "";
    }
};

const std::string verse_conclusion(const std::string &animal,
                              const std::vector<std::string> &animal_names) {
    const std::string death_line = "...She's dead, of course!";

    if (animal == animal_names.back()) {
        return death_line;
    }
    return "";
}

const std::string rescue_attempts(const std::vector<std::string> &animal_names,
                              size_t depth)
{
    bool is_first_swallowed = depth == 0;
    if (is_first_swallowed) {
        auto first_animal = animal_names[0];
        return std::format(
        "I don't know why she swallowed a {} - perhaps she'll die!\n",
            first_animal);
    }

    bool is_choked_on = depth >= animal_names.size() - 1;
    if (is_choked_on) {
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

    auto fly = StartingAnimal("fly");
    auto spider = RescueAnimal("spider", "That wriggled and wiggled and tickled inside her.\n");
    auto bird = RescueAnimal("bird", "How absurd to swallow a bird.\n");
    auto cat = RescueAnimal("cat", "Fancy that to swallow a cat!\n");
    auto dog = RescueAnimal("dog", "What a hog, to swallow a dog!\n");
    auto cow = RescueAnimal("cow", "I don't know how she swallowed a cow!\n");
    auto horse = LethalAnimal("horse");
    std::vector<Animal *> animals = {&fly, &spider, &bird, &cat, &dog, &cow, &horse};

    const std::vector<std::string> verses = {
            animals[0]->verse_intro() +
            animals[0]->verse_comment() +
            rescue_attempts(animal_names, 0) +
            verse_conclusion("fly", animal_names),

            animals[1]->verse_intro() +
            animals[1]->verse_comment() +
            rescue_attempts(animal_names, 1) +
            verse_conclusion("fly", animal_names),

            animals[2]->verse_intro() +
            animals[2]->verse_comment() +
            rescue_attempts(animal_names, 2) +
            verse_conclusion("fly", animal_names),

            animals[3]->verse_intro() +
            animals[3]->verse_comment() +
            rescue_attempts(animal_names, 3) +
            verse_conclusion("fly", animal_names),

            animals[4]->verse_intro() +
            animals[4]->verse_comment() +
            rescue_attempts(animal_names, 4) +
            verse_conclusion("fly", animal_names),

            animals[5]->verse_intro() +
            animals[5]->verse_comment() +
            rescue_attempts(animal_names, 5) +
            verse_conclusion("fly", animal_names),

            animals[6]->verse_intro() +
            animals[6]->verse_comment() +
            rescue_attempts(animal_names, 6) +
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
