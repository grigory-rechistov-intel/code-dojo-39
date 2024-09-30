#include "lib.h"
#include <vector>
#include <format>

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
};

const std::string rescue_attempts(const std::vector<Animal *> animals, size_t depth)
{
    auto this_animal = animals[depth];
    auto prey = depth > 0? animals.at(depth - 1): nullptr;

    bool is_first_swallowed = depth == 0;
    bool is_choked_on = depth >= animals.size() - 1;
    if (is_first_swallowed || is_choked_on) {
        return this_animal->reason_to_swallow(nullptr);
    }

    auto line = this_animal->reason_to_swallow(prey);

    std::string separator = prey->separator();

    return line + separator + rescue_attempts(animals, depth-1);
}


const std::string get_verse(size_t n)
{

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
            rescue_attempts(animals, 0) +
            animals[0]->verse_conclusion(),

            animals[1]->verse_intro() +
            animals[1]->verse_comment() +
            rescue_attempts(animals, 1) +
            animals[1]->verse_conclusion(),

            animals[2]->verse_intro() +
            animals[2]->verse_comment() +
            rescue_attempts(animals, 2) +
            animals[2]->verse_conclusion(),

            animals[3]->verse_intro() +
            animals[3]->verse_comment() +
            rescue_attempts(animals, 3) +
            animals[3]->verse_conclusion(),

            animals[4]->verse_intro() +
            animals[4]->verse_comment() +
            rescue_attempts(animals, 4) +
            animals[4]->verse_conclusion(),

            animals[5]->verse_intro() +
            animals[5]->verse_comment() +
            rescue_attempts(animals, 5) +
            animals[5]->verse_conclusion(),

            animals[6]->verse_intro() +
            animals[6]->verse_comment() +
            rescue_attempts(animals, 6) +
            animals[6]->verse_conclusion(),
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
