#include "lib.h"
#include <vector>
#include <format>

class Animal;
using Sequence = std::vector<Animal *>;

class Animal {
    protected:
    std::string name;
    std::string intro_punctuation;
    public:
    const std::string get_name() const {return name;}
    Animal() = delete;
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
    virtual const std::string verse_conclusion() = 0;
    virtual const std::string reason_to_swallow(const Animal *prey) = 0;
    virtual const std::string separator() {return ",\n";}

    virtual const std::string swallow_sequence(const Sequence animals, size_t depth) = 0;
};


class StartingAnimal: public Animal {
    public:
    StartingAnimal(const std::string _name): Animal(_name) {
        intro_punctuation = ".";
    }
    virtual const std::string verse_comment() {
        return "";
    }
    virtual const std::string verse_conclusion() {
        return "";
    }

    virtual const std::string reason_to_swallow(const Animal *prey) {
        return std::format(
            "I don't know why she swallowed a {} - perhaps she'll die!\n",
                name);
    }
    virtual const std::string separator() {return ";\n";};

    virtual const std::string swallow_sequence(const Sequence animals, size_t depth) {
        return reason_to_swallow(nullptr);
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
    virtual const std::string verse_conclusion() {
        return "";
    }
    virtual const std::string reason_to_swallow(const Animal *prey) {
        return std::format("She swallowed the {} to catch the {}", name, prey->get_name());
    }
    virtual const std::string swallow_sequence(const Sequence animals, size_t depth) {
        auto prey = depth > 0? animals.at(depth - 1): nullptr;

        auto line = reason_to_swallow(prey);

        std::string separator = prey->separator();
        return line + separator + prey->swallow_sequence(animals, depth-1);
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
    virtual const std::string verse_conclusion() {
        return "...She's dead, of course!";
    }
    virtual const std::string reason_to_swallow(const Animal *prey) {
        return "";
    }

    virtual const std::string swallow_sequence(const Sequence animals, size_t depth) {
        return reason_to_swallow(nullptr);
    }
};


class NullAnimal: public Animal {
    public:
    NullAnimal(const std::string _name): Animal(_name) {}
    virtual const std::string verse_comment() {
        return "";
    }
    virtual const std::string verse_conclusion() {
        return "";
    }
    virtual const std::string reason_to_swallow(const Animal *prey) {
        return "";
    }
    virtual const std::string separator() {return "";};
    virtual const std::string swallow_sequence(const Sequence animals, size_t depth) {
        return "";
    }
};

const std::string get_verse(size_t n)
{
    auto fly = StartingAnimal("fly");
    auto spider = RescueAnimal("spider", "That wriggled and wiggled and tickled inside her.\n");
    auto bird = RescueAnimal("bird", "How absurd to swallow a bird.\n");
    auto cat = RescueAnimal("cat", "Fancy that to swallow a cat!\n");
    auto dog = RescueAnimal("dog", "What a hog, to swallow a dog!\n");
    auto cow = RescueAnimal("cow", "I don't know how she swallowed a cow!\n");
    auto horse = LethalAnimal("horse");
    Sequence animals = {&fly, &spider, &bird, &cat, &dog, &cow, &horse};

    if (n >= animals.size()) {
        return "";
    }
    auto animal = animals.at(n);
    auto verse = animal->verse_intro() + animal->verse_comment() +
        animal->swallow_sequence(animals, n) + animal->verse_conclusion();

    return verse;
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
